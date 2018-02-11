//
//  ModelBuilder.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/30.
//
//

#include "ModelBuilder.hpp"
#include "Models.h"

BaseModel * ModelBuilder::BuildSystemModel(string modelName,vector<string> data)
{
    BaseModel * baseModel = NULL;
    if(modelName=="Dialog"){
        baseModel = new Dialog();
    }
    else if(modelName=="System"){
        baseModel = new System();
    }
    else if(modelName=="Story"){
        baseModel = new Story();
    }
    else if(modelName=="SpecialEvent"){
        baseModel = new SpecialEvent();
    }
    else if(modelName=="Item"){
        baseModel = new Item();
    }
    
    
    if(baseModel!=NULL){
        baseModel->initModel(data);
    }
    return baseModel;
}
