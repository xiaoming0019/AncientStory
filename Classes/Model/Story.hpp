//
//  Story.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/31.
//
//

#ifndef Story_hpp
#define Story_hpp

#include <stdio.h>
#include "BaseModel.hpp"
class Story : public BaseModel
{
public:
    Story();
    void initModel(vector<string> data);
    string getId();
    string getDialog();
    string getNext();
    string getNecessaryItem();
    string getCostItem();
    string getGetItem();
    string getSelectBranch();
private:
    string Id;
    string dialog;
    string next;
    string necessaryItem;
    string costItem;
    string getItem;
    string selectBranch;
};

#endif /* Story_hpp */
