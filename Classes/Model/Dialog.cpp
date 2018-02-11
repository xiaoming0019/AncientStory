//
//  Dialog.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/29.
//
//

#include "Dialog.hpp"
Dialog::Dialog()
{
}
void Dialog::initModel(vector<string> data)
{
    int index = 0;
    Id = data[index++];
    stringCH = data[index++];
    stringEN = data[index++];
    
    this->autorelease();
}
string Dialog::getId()
{
    return Id;
}
string Dialog::getStringCH()
{
    return stringCH;
}
string Dialog::getStringEN()
{
    return stringEN;
}
