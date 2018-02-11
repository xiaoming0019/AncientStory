//
//  MainScene.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/27.
//
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class MainScene : public Layer
{
public:
    CREATE_FUNC(MainScene);
    bool init();
    static Scene * createScene();
private:
    void setButtons();
    void onStartClick(Ref *ref);
    
};



#endif /* MainScene_hpp */
