//
//  ModelManager.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/29.
//
//

#include "ModelManager.hpp"
#include "ModelBuilder.hpp"
#include "CommonTools.hpp"

static ModelManager * m_ModelManager = NULL;

ModelManager * ModelManager::getInstance()
{
    if(m_ModelManager==NULL){
        m_ModelManager = new ModelManager();
    }
    return m_ModelManager;
}
ModelManager::ModelManager()
{
    dataList.push_back("System");
    dataList.push_back("Dialog");
    dataList.push_back("Story");
    dataList.push_back("SpecialEvent");
    dataList.push_back("Item");
    this->InitModels();
}

void ModelManager::InitModels()
{
    for(int i=0;i<dataList.size();i++){
        FileUtils * fileUtils = FileUtils::getInstance();
        auto fullPath = fileUtils->fullPathForFilename(dataList[i] + ".csv");
        auto fileData = fileUtils->getStringFromFile(fullPath);
        auto dataRes = CommonTools::Split(fileData, "\n");
        for(int j=1;j<dataRes.size();j++){
            auto data = CommonTools::Split(dataRes[j], ";");
            if(data[0]==""){
                continue;
            }
            auto baseModel = ModelBuilder::BuildSystemModel(dataList[i],data);
            auto key = dataList[i] + "_" + data[0];
            if(baseModel!=NULL){
                m_dataPool.insert(key, baseModel);
            }
            
        }
    }
}

BaseModel * ModelManager::getModel(string modelName,string key)
{
    string modelKey = modelName + "_" + key;
    auto baseModel = m_dataPool.at(modelKey);
    return baseModel;
}
