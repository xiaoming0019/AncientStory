//
//  ModelBuilder.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/30.
//
//

#ifndef ModelBuilder_hpp
#define ModelBuilder_hpp

#include <stdio.h>
#include "BaseModel.hpp"

class ModelBuilder
{
public:
    static BaseModel * BuildSystemModel(string modelName,vector<string> modelData);
};


#endif /* ModelBuilder_hpp */
