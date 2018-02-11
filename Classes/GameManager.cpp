//
//  GameManager.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/31.
//
//

#include "GameManager.hpp"
#include "CommonTools.hpp"
#include "Models.h"

static GameManager * m_GameManager = NULL;

GameManager::GameManager()
{
    this->init();
}
GameManager * GameManager::getInstance()
{
    if(m_GameManager==NULL){
        m_GameManager = new GameManager();
    }
    return m_GameManager;
}
void GameManager::init()
{
    m_Date = CommonTools::getLocalData(UD_DATE, 1);
    m_TimeNow = (TimeNow)CommonTools::getLocalData(UD_TIME, 1);
    m_Buildings.clear();
    m_WorldMap = NULL;
    m_User = new User();
    this->initWorldMap();
}

TimeNow GameManager::getTimeNow()
{
    return m_TimeNow;
}
int GameManager::getDate()
{
    return m_Date;
}

Map<int, Building *> GameManager::getBuildings()
{
    return m_Buildings;
}

Map<int, SpecialEvent *> GameManager::getSpecialEvents()
{
    return m_SpecialEvents;
}
Map<int, Building *> GameManager::getRuinedBuildings()
{
    return m_RuinedBuildings;
}

User * GameManager::getUser()
{
    return m_User;
}

void GameManager::gameStart()
{
    if(m_TimeNow==Morning){
        //Event
        int randomCount = 0;
        while (true) {
            randomCount++;
            if(randomCount>10){
                break;
            }
            auto randomEvent = this->getRandomEvent();
            if(this->checkEventAdded(randomEvent)){
                continue;
            }
            if(this->addEventToBuilding(randomEvent)){
                break;
            }
        }
    }
}

bool GameManager::checkEventAdded(string eventId)
{
    bool eventAdded = false;
    for(auto key : m_SpecialEvents.keys()){
        if(m_SpecialEvents.at(key)->getId()==eventId){
            eventAdded = true;
            break;
        }
    }
    return eventAdded;
}

bool GameManager::addEventToBuilding(string eventId)
{
    Vector<Building *>buildings;
     auto specialEvent = (SpecialEvent *) ModelManager::getInstance()->getModel("SpecialEvent", eventId);
    for (auto key : m_Buildings.keys()) {
        if((int)m_Buildings.at(key)->getType() == specialEvent->getBuildingType()){
            buildings.pushBack(m_Buildings.at(key));
        }
    }
    if(buildings.size()==0){
        return false;
    }
    auto ranBuild = buildings.getRandomObject();
    m_SpecialEvents.insert(ranBuild->getPointPos(), specialEvent);
    return true;
}


string GameManager::getRandomEvent()
{
    auto system = (System *) ModelManager::getInstance()->getModel("System", "WM_Event");
    auto events = CommonTools::Split(system->getParam(1), ",");
    return events[CommonTools::getRandomNum(0, (int)events.size()-1)];
}



void GameManager::initWorldMap()
{
    if(!m_Buildings.empty()){
        return;
    }
    string mapData = CommonTools::getLocalData(UD_MAP_BUILDING);
    if(mapData==""){
        for (int i=1; i<50; i++) {
            auto rX = CommonTools::getRandomNum(1, 99);
            auto rY = CommonTools::getRandomNum(1, 99);
            Vec2 point = Vec2(rX, rY);
            BuildingType type = (BuildingType)CommonTools::getRandomNum(1, 2);
            auto building = new Building(point,type);
            m_Buildings.insert(building->getPointPos(), building);
            mapData = mapData + Value(building->getPointPos()).asString() + "_" + Value((int)type).asString() + ";";
        }
        CommonTools::setLocalData(UD_MAP_BUILDING, mapData);
    }
    else{
        auto mapRes = CommonTools::Split(mapData, ";");
        for(int i=0;i<mapRes.size();i++){
            auto dataRes = CommonTools::Split(mapRes[i], "_");
            if(dataRes.size()!=2){
                continue;
            }
            int pointPos = atoi(dataRes[0].c_str());
            Vec2 point = Vec2(pointPos/1000, pointPos%1000);
            BuildingType type = (BuildingType)atoi(dataRes[1].c_str());
            auto building = new Building(point,type);
            m_Buildings.insert(building->getPointPos(), building);
            
        }
    }
    
    string ruinsData = CommonTools::getLocalData(UD_MAP_RUINS);
    if(ruinsData!=""){
        auto ruinRes = CommonTools::Split(ruinsData, ";");
        for (int i=0; i<ruinRes.size(); i++) {
            auto dataRes = CommonTools::Split(ruinRes[i], "_");
            if(dataRes.size()!=2){
                continue;
            }
            int pointPos = atoi(dataRes[0].c_str());
            int ruinedTime = atoi(dataRes[1].c_str());
            auto building = new Building(pointPos,ruinedTime);
            m_RuinedBuildings.insert(pointPos, building);
        }
    }
}

void GameManager::buildingRuin(Building * building)
{
    int time = m_Date*10 + (int)m_TimeNow;
    auto ruinBuilding = new Building(building->getPointPos(),time);
    m_RuinedBuildings.insert(ruinBuilding->getPointPos(), ruinBuilding);
    this->updateRuinData();
}

void GameManager::buildingExplor(Building * building)
{
    
}

void GameManager::updateRuinData()
{
    string ruins = "";
    for (auto key : m_RuinedBuildings.keys()) {
        auto building = m_RuinedBuildings.at(key);
        ruins = ruins + Value(building->getPointPos()).asString() + "_" + Value(building->getDestroyTime()).asString() + ";";
    }
    CommonTools::setLocalData(UD_MAP_RUINS, ruins);
    
}

void GameManager::setWorldMap(WorldMap *worldMap)
{
    m_WorldMap = worldMap;
}
WorldMap * GameManager::getCurrWorldMap()
{
    return m_WorldMap;
}
