//
//  CommonTools.cpp
//  AncientStory
//
//  Created by xiaoming on 2017/7/30.
//
//

#include "CommonTools.hpp"

int CommonTools::getRandomNum(int min,int max)
{
    if (max<=min) {
        return min;
    }
    unsigned long num=arc4random()%(max-min+1)+min;
    int randomPoint=(int)num;
    return randomPoint;
}


vector<string> CommonTools::Split (string str,string pattern)
{
    string::size_type pos;
    vector<std::string> result;
    str+=pattern;
    int size=(int)str.size();
    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=(int)pos+(int)pattern.size()-1;
        }  
    }  
    return result;
}

int CommonTools::getLocalData(string key,int dValue)
{
    int value = UserDefault::getInstance()->getIntegerForKey(key.c_str(), dValue);
    UserDefault::getInstance()->flush();
    return value;
}
void CommonTools::setLocalData(string key,int value)
{
    UserDefault::getInstance()->setIntegerForKey(key.c_str(), value);
    UserDefault::getInstance()->flush();
}

string CommonTools::getLocalData(string key)
{
    string value = UserDefault::getInstance()->getStringForKey(key.c_str(), "");
    UserDefault::getInstance()->flush();
    return value;
}
void CommonTools::setLocalData(string key,string value)
{
    UserDefault::getInstance()->setStringForKey(key.c_str(), value);
    UserDefault::getInstance()->flush();
}



