//
//  Dialog.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/29.
//
//

#ifndef Dialog_hpp
#define Dialog_hpp

#include <stdio.h>
#include "BaseModel.hpp"
class Dialog : public BaseModel
{
public:
    Dialog();
    void initModel(vector<string> data);
    string getId();
    string getStringCH();
    string getStringEN();
private:
    string Id;
    string stringCH;
    string stringEN;
    
    
};

#endif /* Dialog_hpp */
