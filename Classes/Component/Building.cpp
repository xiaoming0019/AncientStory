//
//  Building.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/31.
//
//

#include "Building.hpp"

Building::Building(Vec2 point,BuildingType bType)
{
    m_Point = point;
    m_Type = bType;
    m_Destroyed = false;
}
Building::Building(int pointPos,int destroyTime)
{
    m_Point = Vec2(pointPos/1000, pointPos%1000);
    m_Type = Ruins;
    m_Destroyed = true;
    m_DestroyTime = destroyTime;
}

int Building::getPointPos()
{
    return (int)m_Point.x * 1000 + (int)m_Point.y;
}
BuildingType Building::getType()
{
    return m_Type;
}
Vec2 Building::getPoint()
{
    return m_Point;
}

bool Building::getDestroyed()
{
    return m_Destroyed;
}
void Building::buildingDestroy()
{
    m_Destroyed = true;
}
int Building::getDestroyTime()
{
    return m_DestroyTime;
}
