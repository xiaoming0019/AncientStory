//
//  WorldMap.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/29.
//
//

#ifndef WorldMap_hpp
#define WorldMap_hpp

#include <stdio.h>
#include "SelectPanel.hpp"
#include "GameDefine.h"
#include "BuildingBox.hpp"
#include "Story.hpp"


class WorldMap : public Layer , public SelectPanelDelegate
{
public:
    CREATE_FUNC(WorldMap);
    bool init();
    static Scene * createScene();
    void onBuildingBoxClick(BuildingBox * buildingBox);
private:
    void refreshWorldMap();
    void openTouchEvent();
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    Vec2 startPoint;
    Node * backMap;
    Layer * m_WorldMapUI;
    void initUI();
    Label * m_LabelHp;
    void resetStoryLabel();
    Node * m_StoryBoard;
    Label * m_LabelStory;
    
    void onRestClick(Ref *ref);
    void onSureClick(Ref *ref);
    void onCancleClick(Ref *ref);
    
    SelectPanel * m_SelectPanel;
    void addSelectPanel(SelectPanelType panelType);
    void removeSelectPanel();
    Map<int, BuildingBox *> m_Buildings;
    
    BuildingBox * m_CurrentBuilding;
    //Delegate
    void selectPanelCallBack(int result);
    
    
    void eventStart(SpecialEvent * event);
    void eventStoryShow(Story * story);
    void eventStoryContinue();
    Story * m_CurrentStory;
    
};

#endif /* WorldMap_hpp */
