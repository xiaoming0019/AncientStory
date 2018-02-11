//
//  GameManager.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/31.
//
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include "GameDefine.h"
#include "Building.hpp"
#include "SpecialEvent.hpp"
#include "WorldMap.hpp"
#include "User.hpp"

class GameManager : public Ref
{
public:
    GameManager();
    static GameManager * getInstance();
    TimeNow getTimeNow();
    int getDate();
    void gameStart();
    Map<int, Building *> getBuildings();
    Map<int, SpecialEvent *> getSpecialEvents();
    Map<int, Building *> getRuinedBuildings();
    void setWorldMap(WorldMap *worldMap);
    WorldMap * getCurrWorldMap();
    void buildingRuin(Building * building);
    void buildingExplor(Building * building);
    User * getUser();
private:
    void init();
    TimeNow m_TimeNow;
    int m_Date;
    void initWorldMap();
    void initUserData();
    Map<int, Building *> m_Buildings;
    Map<int, SpecialEvent *> m_SpecialEvents;
    Map<int, Building *> m_RuinedBuildings;
    User * m_User;
    string getRandomEvent();
    bool checkEventAdded(string eventId);
    bool addEventToBuilding(string eventId);
    WorldMap * m_WorldMap;
    void updateRuinData();
    
};

#endif /* GameManager_hpp */
