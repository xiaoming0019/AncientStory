//
//  Item.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/8/7.
//
//

#include "Item.hpp"

Item::Item()
{
}
void Item::initModel(vector<string> data)
{
    int index = 0;
    Id = data[index++];
    name = data[index++];
    this->autorelease();
}
string Item::getId()
{
    return Id;
}
string Item::getName()
{
    return name;
}
