//
//  Building.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/31.
//
//

#ifndef Building_hpp
#define Building_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
#include "GameDefine.h"

class Building : public Ref
{
public:
    Building(Vec2 point,BuildingType bType);
    Building(int pointPos,int destroyTime);
    int getPointPos();
    BuildingType getType();
    Vec2 getPoint();
    bool getDestroyed();
    void buildingDestroy();
    int getDestroyTime();
private:
    Vec2 m_Point;
    BuildingType m_Type;
    bool m_Destroyed;
    int m_DestroyTime;
};


#endif /* Building_hpp */
