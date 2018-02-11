//
//  User.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/31.
//
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
using namespace std;
#include "Item.hpp"

class User : public Ref
{
public:
    User();
    int getItemNum(string itemId);
    void itemAdd(string itemId,int num);
    void itemCost(string itemId,int num);
private:
    void initUser();
    map<string, int> m_Items;
    void updateItems();
};

#endif /* User_hpp */
