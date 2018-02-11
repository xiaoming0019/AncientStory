//
//  BuildingBox.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/31.
//
//

#ifndef BuildingBox_hpp
#define BuildingBox_hpp

#include <stdio.h>
#include "Building.hpp"
#include "SpecialEvent.hpp"

class BuildingBox : public Node
{
public:
    BuildingBox(Building * building,SpecialEvent * event);
    Building * getBuilding();
    SpecialEvent * getEvent();
    void clearEvent();
private:
    Building * m_Building;
    SpecialEvent * m_Event;
    void openTouchEvent();
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    Sprite * m_EventFlag;
    
};

#endif /* BuildingBox_hpp */
