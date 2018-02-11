//
//  SpecialEvent.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/8/1.
//
//

#include "SpecialEvent.hpp"

SpecialEvent::SpecialEvent()
{
}
void SpecialEvent::initModel(vector<string> data)
{
    int index = 0;
    Id = data[index++];
    story = data[index++];
    buildingType = atoi(data[index++].c_str());
    duration = atoi(data[index++].c_str());
    this->autorelease();
}

string SpecialEvent::getId()
{
    return Id;
}
string SpecialEvent::getStory()
{
    return story;
}
int SpecialEvent::getBuildingType()
{
    return buildingType;
}
int SpecialEvent::getDuration()
{
    return duration;
}
