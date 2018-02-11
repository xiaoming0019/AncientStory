//
//  GameTools.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/30.
//
//

#include "GameTools.hpp"
#include "Models.h"

string GameTools::getDialog(string dialogId)
{
    string dialog = "";
    auto dialogModel = (Dialog *)ModelManager::getInstance()->getModel("Dialog", dialogId);
    if(dialogModel!=NULL){
        dialog = dialogModel->getStringCH();
    }
    return dialog;
}
