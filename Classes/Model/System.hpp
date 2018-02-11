//
//  System.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/30.
//
//

#ifndef System_hpp
#define System_hpp

#include <stdio.h>
#include "BaseModel.hpp"
class System : public BaseModel
{
public:
    System();
    void initModel(vector<string> data);
    string getId();
    string getParam(int index);
private:
    string Id;
    vector<string>params;
};

#endif /* System_hpp */
