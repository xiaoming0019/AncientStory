//
//  SelectPanel.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/8/2.
//
//

#ifndef SelectPanel_hpp
#define SelectPanel_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
#include "GameDefine.h"

class SelectPanelDelegate
{
public:
    virtual void selectPanelCallBack(int result) = 0;
};


class SelectPanel : public Node
{
public:
    static SelectPanel * create(SelectPanelType panelType);
    SelectPanel(SelectPanelType panelType);
    void setDelegate(SelectPanelDelegate * delegate);
private:
    SelectPanelType m_PanelType;
    SelectPanelDelegate * m_Delegate;
    void onSelectClick(Ref *ref);
    
};

#endif /* SelectPanel_hpp */
