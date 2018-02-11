//
//  SpecialEvent.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/8/1.
//
//

#ifndef SpecialEvent_hpp
#define SpecialEvent_hpp

#include <stdio.h>
#include "BaseModel.hpp"

class SpecialEvent : public BaseModel
{
public:
    SpecialEvent();
    void initModel(vector<string> data);
    string getId();
    string getStory();
    int getBuildingType();
    int getDuration();
private:
    string Id;
    string story;
    int buildingType;
    int duration;
    
    
};

#endif /* SpecialEvent_hpp */
