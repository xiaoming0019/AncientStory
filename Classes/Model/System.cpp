//
//  System.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/30.
//
//

#include "System.hpp"

System::System()
{
}
void System::initModel(vector<string> data)
{
    Id = data[0];
    for(int i=1;i<7;i++){
        string param = data[i];
        params.push_back(param);
    }
    this->autorelease();
}
string System::getId()
{
    return Id;
}
string System::getParam(int index)
{
    if(index<1 || index>params.size()){
        return "";
    }
    return params.at(index-1);
}
