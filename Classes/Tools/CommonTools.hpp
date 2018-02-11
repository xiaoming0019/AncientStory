//
//  CommonTools.hpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/30.
//
//

#ifndef CommonTools_hpp
#define CommonTools_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class CommonTools
{
public:
    static int getRandomNum(int min,int max);
    static vector<string> Split (string str,string pattern);
    static int getLocalData(string key,int dValue);
    static void setLocalData(string key,int value);
    static string getLocalData(string key);
    static void setLocalData(string key,string value);
};

#endif /* CommonTools_hpp */
