//
//  MainScene.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/27.
//
//

#include "MainScene.hpp"
#include "GameDefine.h"
#include "WorldMap.hpp"
#include "ModelManager.hpp"

Scene * MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainScene::init()
{
    if(!Layer::init()){
        return false;
    }

    this->setButtons();
    return true;
}

void MainScene::setButtons()
{
//    auto colorBack = LayerColor::create(Color4B(238, 237, 236, 255), WIDTH, HEIGHT);
//    this->addChild(colorBack);
    
    
    auto labelTitle = Label::createWithSystemFont("Ancient Story", FONT_VERDANA, 70);
    labelTitle->setPosition(Vec2(WIDTH/2+10, HEIGHT*4/5-10));
    this->addChild(labelTitle);
    //labelTitle->setColor(Color3B(205, 105, 201));
    
    auto labelStart=Label::createWithSystemFont("Start", FONT_VERDANA, 54);
    auto itemStart = MenuItemLabel::create(labelStart, CC_CALLBACK_1(MainScene::onStartClick, this));
    
    
    
    auto menu = Menu::create(itemStart,NULL);
    this->addChild(menu);
    
    ModelManager::getInstance();
    
}

void MainScene::onStartClick(Ref *ref)
{
    CCLOG("OnStartClick~~~");
    auto scene = WorldMap::createScene();
    Director::getInstance()->replaceScene(scene);
    
}



