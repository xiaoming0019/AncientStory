//
//  BuildingBox.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/31.
//
//

#include "BuildingBox.hpp"
#include "GameManager.hpp"

BuildingBox::BuildingBox(Building * building,SpecialEvent * event)
{
    m_Building = building;
    m_Event = event;
    Node::init();
    std::string buildPic = "";
    if(building->getType()==Town){
        buildPic = "Town.png";
    }
    else if (building->getType()==Dungeons){
        buildPic = "Dungeons.png";
    }
    auto pic = Sprite::create(buildPic);
    this->addChild(pic);
    pic->setAnchorPoint(Vec2(0, 0));
    this->setContentSize(pic->getContentSize());
    this->openTouchEvent();
    m_EventFlag = NULL;
    if(event!=NULL){
        m_EventFlag = Sprite::create("EventFlag.png");
        this->addChild(m_EventFlag);
        m_EventFlag->setPosition(Vec2(this->getContentSize().width/2, this->getContentSize().height-20));
    }
}
Building * BuildingBox::getBuilding()
{
    return m_Building;
}

SpecialEvent * BuildingBox::getEvent()
{
    return m_Event;
}

void BuildingBox::openTouchEvent()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(false);
    touchListener->onTouchBegan = CC_CALLBACK_2(BuildingBox::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(BuildingBox::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}
bool BuildingBox::onTouchBegan(Touch* touch, Event* event)
{
    return true;
}
void BuildingBox::onTouchEnded(Touch* touch, Event* event)
{
    auto nodePos = this->getParent()->convertToNodeSpace(touch->getLocation());
    if(this->getBoundingBox().containsPoint(nodePos)){
        GameManager::getInstance()->getCurrWorldMap()->onBuildingBoxClick(this);
    }
}

void BuildingBox::clearEvent()
{
    if(m_EventFlag!=NULL){
        m_EventFlag->removeFromParent();
        m_EventFlag = NULL;
        m_Event = NULL;
    }
}
