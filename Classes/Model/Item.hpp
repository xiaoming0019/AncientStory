//
//  Item.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/8/7.
//
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include "BaseModel.hpp"
class Item : public BaseModel
{
public:
    Item();
    void initModel(vector<string> data);
    string getId();
    string getName();
private:
    string Id;
    string name;
    
    
};

#endif /* Item_hpp */
