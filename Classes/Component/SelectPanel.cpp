//
//  SelectPanel.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/8/2.
//
//

#include "SelectPanel.hpp"
using namespace std;
#include "GameTools.hpp"

SelectPanel * SelectPanel::create(SelectPanelType panelType)
{
    auto panel = new SelectPanel(panelType);
    return panel;
}
SelectPanel::SelectPanel(SelectPanelType panelType)
{
    Node::init();
    m_PanelType = panelType;
    m_Delegate = NULL;
    this->autorelease();
    
    string strSure = "Sure";
    string strCancle = "Cancle";
    if(m_PanelType==Explore){
        strSure = GameTools::getDialog("D_Common_Explore");
        strCancle = GameTools::getDialog("D_Common_Destroy");
    }
    auto labelSure = Label::createWithSystemFont(strSure, FONT_VERDANA, 20);
    auto labelCancle = Label::createWithSystemFont(strCancle, FONT_VERDANA, 20);
    labelSure->setColor(Color3B(0, 0, 0));
    labelCancle->setColor(Color3B(0, 0, 0));
    auto itemSure = MenuItemLabel::create(labelSure, CC_CALLBACK_1(SelectPanel::onSelectClick, this));
    itemSure->setTag(1);
    
    
    auto itemCancle = MenuItemLabel::create(labelCancle, CC_CALLBACK_1(SelectPanel::onSelectClick, this));
    itemCancle->setTag(2);
    
    auto menu = Menu::create(itemSure,itemCancle, NULL);
    this->addChild(menu);
    
    itemSure->setPosition(Vec2(WIDTH/2-60, -HEIGHT/2+100));
    itemCancle->setPosition(Vec2(WIDTH/2-60, -HEIGHT/2+50));
    
    
}
void SelectPanel::setDelegate(SelectPanelDelegate * delegate)
{
    m_Delegate = delegate;
}

void SelectPanel::onSelectClick(Ref *ref)
{
    int result = ((Node *)ref)->getTag();
    if(m_Delegate!=NULL){
        m_Delegate->selectPanelCallBack(result);
    }
}

