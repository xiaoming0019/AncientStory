//
//  ModelManager.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/29.
//
//

#ifndef ModelManager_hpp
#define ModelManager_hpp

#include <stdio.h>
#include "BaseModel.hpp"

class ModelManager : public Ref
{
public:
    static ModelManager * getInstance();
    ModelManager();
    BaseModel * getModel(string modelName,string key);
private:
    vector<string>dataList;
    void InitModels();
    Map<string, BaseModel *> m_dataPool;
    
};


#endif /* ModelManager_hpp */
