//
//  GameDefine.h
//  AncientStory
//
//  Created by xiaoming on 2017/7/27.
//
//

#ifndef GameDefine_h
#define GameDefine_h

#define WIDTH    Director::getInstance()->getWinSize().width
#define HEIGHT   Director::getInstance()->getWinSize().height

#define FONT_VERDANA              "Verdana-Bold"
#define FONT_HELVETICA_BOLD       "Helvetica-Bold"
#define FONT_GEORGIA              "Georgia-Bold"
#define FONT_HELVETICA            "Helvetica"


//GameSetting
#define BOX_SIZE    32

#define ITEM_DRESS     "1001"
#define EVENT_DEVIL    "1001"



//UserData  用户数据
#define UD_MAP_BUILDING   "ud_map_building"
#define UD_MAP_RUINS      "ud_map_ruins"
#define UD_USER_ITEMS     "ud_user_items"
#define UD_DATE   "ud_date"
#define UD_TIME   "ud_time"


enum TimeNow{
    Morning = 1,
    Noon = 2,
    Evening = 3,
};

enum BuildingType{
    Town = 1,
    Dungeons = 2,
    Ruins = 3,
};

enum SelectPanelType{
    Explore = 1,
};



#endif /* GameDefine_h */
