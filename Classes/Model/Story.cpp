//
//  Story.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/31.
//
//

#include "Story.hpp"

Story::Story()
{
}
void Story::initModel(vector<string> data)
{
    int index = 0;
    Id = data[index++];
    dialog = data[index++];
    next = data[index++];
    necessaryItem = data[index++];
    costItem = data[index++];
    getItem = data[index++];
    selectBranch = data[index++];
    this->autorelease();
}
string Story::getId()
{
    return Id;
}
string Story::getDialog()
{
    return dialog;
}
string Story::getNext()
{
    return next;
}
string Story::getNecessaryItem()
{
    return necessaryItem;
}
string Story::getCostItem()
{
    return costItem;
}
string Story::getGetItem()
{
    return getItem;
}
string Story::getSelectBranch()
{
    return selectBranch;
}
