//
//  WorldMap.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/29.
//
//

#include "WorldMap.hpp"
#include "GameDefine.h"
#include "Models.h"
#include "CommonTools.hpp"
#include "GameTools.hpp"
#include "GameManager.hpp"


Scene * WorldMap::createScene()
{
    auto scene = Scene::create();
    auto layer = WorldMap::create();
    scene->addChild(layer);
    return scene;
}

bool WorldMap::init()
{
    if(!Layer::init()){
        return false;
    }
    m_SelectPanel = NULL;
    m_WorldMapUI = NULL;
    GameManager::getInstance()->setWorldMap(this);
    GameManager::getInstance()->gameStart();
    m_CurrentBuilding = NULL;
    backMap = Node::create();
    m_CurrentStory = NULL;
    this->addChild(backMap);
    this->refreshWorldMap();
    
    this->openTouchEvent();
    
    this->initUI();
    return true;
}

void WorldMap::refreshWorldMap()
{
    auto builds = GameManager::getInstance()->getBuildings();
    auto events = GameManager::getInstance()->getSpecialEvents();
    auto ruins = GameManager::getInstance()->getRuinedBuildings();
    if(m_Buildings.size()==0){
        for(auto key : builds.keys()){
            if(ruins.at(key)!=NULL){
                continue;
            }
            auto build = builds.at(key);
            auto event = events.at(key);
            auto buildBox = new BuildingBox(build,event);
            backMap->addChild(buildBox);
            buildBox->setPosition(build->getPoint()*BOX_SIZE);
            m_Buildings.insert(buildBox->getBuilding()->getPointPos(), buildBox);
        }
    }
    else{
        while (true) {
            bool operationSuccess = false;
            for(auto key : m_Buildings.keys()){
                auto buildBox = m_Buildings.at(key);
                if(ruins.at(key)!=NULL){
                    buildBox->removeFromParent();
                    m_Buildings.erase(key);
                    operationSuccess = true;
                    break;
                }
            }
            if(!operationSuccess){
                break;
            }
        }
    }
    
   
    
    
    
    
}

void WorldMap::initUI()
{
    m_WorldMapUI = Layer::create();
    
    auto layerColor = LayerColor::create(Color4B(255, 255, 255, 255), WIDTH, 120);
    m_WorldMapUI->addChild(layerColor);
    layerColor->setPosition(Vec2(0, HEIGHT-120));
    
    
    m_StoryBoard = LayerColor::create(Color4B(255, 255, 255, 255), WIDTH, 220);
    m_WorldMapUI->addChild(m_StoryBoard);
    
    this->addChild(m_WorldMapUI);
    auto level = Label::createWithSystemFont("LV: 9999", FONT_HELVETICA_BOLD, 26);
    level->setAnchorPoint(Vec2(0, 1));
    m_WorldMapUI->addChild(level);
    level->setPosition(Vec2(10, HEIGHT-10));
    level->setColor(Color3B(0, 0, 0));
    
    m_LabelHp = Label::createWithSystemFont("HP: 9999", FONT_HELVETICA_BOLD, 26);
    m_LabelHp->setAnchorPoint(Vec2(0, 1));
    m_LabelHp->setPosition(Vec2(level->getPositionX(), level->getPositionY()-level->getContentSize().height-5));
    m_LabelHp->setColor(Color3B(0, 0, 0));
    m_WorldMapUI->addChild(m_LabelHp);
    
    auto labelMp = Label::createWithSystemFont("MP: 9999", FONT_HELVETICA_BOLD, 26);
    labelMp->setAnchorPoint(Vec2(0, 1));
    labelMp->setPosition(Vec2(m_LabelHp->getPositionX(), m_LabelHp->getPositionY()-level->getContentSize().height-5));
    labelMp->setColor(Color3B(0, 0, 0));
    m_WorldMapUI->addChild(labelMp);
    
    auto labelRest = Label::createWithSystemFont("Rest", FONT_HELVETICA_BOLD, 30);
    auto labelItem = MenuItemLabel::create(labelRest, CC_CALLBACK_1(WorldMap::onRestClick, this));
    labelRest->setColor(Color3B(0, 0, 0));
    labelItem->setPosition(Vec2(WIDTH/2-50, HEIGHT/2-40));
    auto menu = Menu::create(labelItem, NULL);
    m_WorldMapUI->addChild(menu);
    
    
    
    
    auto heroHead = Sprite::create("heroHead.jpg");
    heroHead->setScale(0.38, 0.38);
    m_StoryBoard->addChild(heroHead);
    heroHead->setPosition(Vec2(100, m_StoryBoard->getContentSize().height/2));
    
    m_LabelStory = Label::createWithSystemFont("Find something to do!", FONT_HELVETICA_BOLD, 26);
    m_LabelStory->setColor(Color3B(0, 0, 0));
    m_StoryBoard->addChild(m_LabelStory);
    m_LabelStory->setAnchorPoint(Vec2(0, 1));
    m_LabelStory->setPosition(Vec2(heroHead->getPositionX()+heroHead->getContentSize().width*heroHead->getScaleX()/2 + 16, m_StoryBoard->getContentSize().height-25));
    
    
    
    this->resetStoryLabel();
    
}

void WorldMap::resetStoryLabel()
{
    auto system = (System *)ModelManager::getInstance()->getModel("System", "WM_Welcome");
    auto dialogs = CommonTools::Split(system->getParam(1), ",");
    auto dialogId = "D_Hello_" + dialogs[CommonTools::getRandomNum(0, (int)dialogs.size()-1)];
    m_LabelStory->setString(GameTools::getDialog(dialogId));
}


void WorldMap::onRestClick(Ref *ref)
{
    CCLOG("onRestClick~~");
    
}
void WorldMap::onSureClick(Ref *ref)
{
}
void WorldMap::onCancleClick(Ref *ref)
{
}

void WorldMap::addSelectPanel(SelectPanelType panelType)
{
    if(m_SelectPanel!=NULL){
        this->removeSelectPanel();
    }
    m_SelectPanel = SelectPanel::create(panelType);
    m_SelectPanel->setDelegate(this);
    m_StoryBoard->addChild(m_SelectPanel);
}
void WorldMap::removeSelectPanel()
{
    if(m_SelectPanel!=NULL){
        m_SelectPanel->removeFromParent();
        m_SelectPanel=NULL;
    }
}

void WorldMap::selectPanelCallBack(int result)
{
    CCLOG("selectPanelCallBack:%d",result);
    if(m_CurrentBuilding==NULL){
        CCLOG("m_CurrentBuilding is null~");
        return;
    }
    if(result==2){
        GameManager::getInstance()->buildingRuin(m_CurrentBuilding->getBuilding());
        m_CurrentBuilding = NULL;
        this->refreshWorldMap();
        this->resetStoryLabel();
    }
    else if (result==1){
        if (GameManager::getInstance()->getUser()->getItemNum(ITEM_DRESS)==0) {
            auto event = (SpecialEvent *) ModelManager::getInstance()->getModel("Event", EVENT_DEVIL);
            this->eventStart(event);
            m_CurrentBuilding->clearEvent();
            m_CurrentBuilding=NULL;
        }
        else if (m_CurrentBuilding->getEvent()!=NULL) {
            this->eventStart(m_CurrentBuilding->getEvent());
            m_CurrentBuilding->clearEvent();
            m_CurrentBuilding=NULL;
        }
    }
    
}

void WorldMap::eventStart(SpecialEvent * event)
{
    auto story = (Story *) ModelManager::getInstance()->getModel("Story", event->getStory());
    this->eventStoryShow(story);
}

void WorldMap::eventStoryShow(Story * story)
{
    m_CurrentStory = story;
    if(m_CurrentStory==NULL){
        this->resetStoryLabel();
    }
    else{
        if(m_CurrentStory->getSelectBranch()==""){
            this->removeSelectPanel();
        }
        m_LabelStory->setString(GameTools::getDialog(m_CurrentStory->getDialog()));
    }
}

void WorldMap::eventStoryContinue()
{
    if(m_CurrentStory!=NULL){
        auto story = (Story *) ModelManager::getInstance()->getModel("Story", m_CurrentStory->getNext());
        this->eventStoryShow(story);
    }
    
}






void WorldMap::openTouchEvent()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(WorldMap::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(WorldMap::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(WorldMap::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}
bool WorldMap::onTouchBegan(Touch* touch, Event* event)
{
    if(m_CurrentStory!=NULL){
        this->eventStoryContinue();
        return false;
    }
    startPoint = touch->getLocation();
    return true;
}
void WorldMap::onTouchEnded(Touch* touch, Event* event)
{
    
}
void WorldMap::onTouchMoved(Touch* touch, Event* event)
{
    auto difPoint = touch->getLocation()-startPoint;
    
    backMap->setPosition(backMap->getPosition()+difPoint);
    startPoint = touch->getLocation();
    
    
}
void WorldMap::onBuildingBoxClick(BuildingBox * buildingBox)
{
    m_CurrentBuilding = buildingBox;
    CCLOG("onBuildingBoxClick~");
    if(buildingBox->getBuilding()->getType()==Town){
        m_LabelStory->setString(GameTools::getDialog("D_Building_Town"));
    }
    else if (buildingBox->getBuilding()->getType()==Dungeons){
        m_LabelStory->setString(GameTools::getDialog("D_Building_Dungeons"));
    }
    this->addSelectPanel(Explore);
}




