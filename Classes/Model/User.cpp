//
//  User.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/31.
//
//

#include "User.hpp"
#include "GameDefine.h"
#include "CommonTools.hpp"

User::User()
{
    this->initUser();
}
void User::initUser()
{
    string itemData = CommonTools::getLocalData(UD_USER_ITEMS);
    if(itemData!=""){
        auto itemRes = CommonTools::Split(itemData, ";");
        for (int i=0; i<itemRes.size(); i++) {
            auto oneData = CommonTools::Split(itemRes[i], "_");
            if(oneData.size()==2){
                int num = atoi(oneData[1].c_str());
                m_Items.insert(make_pair(oneData[0], num));
            }
        }
    }
}

int User::getItemNum(string itemId)
{
    int itemNum = m_Items.at(itemId);
    return itemNum;
}
void User::itemAdd(string itemId,int num)
{
    int itemNum = m_Items.at(itemId) + num;
    m_Items.insert(make_pair(itemId, itemNum));
    this->updateItems();
}
void User::itemCost(string itemId,int num)
{
    int itemNum = m_Items.at(itemId)-num;
    if(itemNum<=0){
        m_Items.erase(itemId);
    }
    else{
        m_Items.insert(make_pair(itemId, itemNum));
    }
    this->updateItems();
}
void User::updateItems()
{
    string itemData = "";
    
    map<std::string,int>::iterator itr;
    for(itr=m_Items.begin();itr!=m_Items.end();++itr){
        string oneItem = itr->first + "_" + Value(itr->second).asString();
        itemData = itemData + oneItem + ";";
    }
    CommonTools::setLocalData(UD_USER_ITEMS, itemData);
}
