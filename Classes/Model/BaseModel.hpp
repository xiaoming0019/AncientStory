//
//  BaseModel.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/29.
//
//

#ifndef BaseModel_hpp
#define BaseModel_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class BaseModel : public Ref
{
public:
    virtual void initModel(vector<string> data) = 0;
};


#endif /* BaseModel_hpp */
