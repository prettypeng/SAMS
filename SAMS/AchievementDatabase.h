//
//  AchievementDatabase.h
//  SAMS
//
//  Created by Jack Peng on 15/7/16.
//  Copyright (c) 2015年 Jack Peng. All rights reserved.
//

#ifndef __SAMS__AchievementDatabase__
#define __SAMS__AchievementDatabase__

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <fstream>
#include <stdio.h>
using namespace std;

class AchivementDatabase{
public:
    class Student{
    public:
        int Number;
        string Name;
        float English,Chinese,Math;
        Student(int InputNumber,string InputName,float Eng,float Chi,float Mat)
        :Number(InputNumber), Name(InputName), English(Eng), Chinese(Chi), Math(Mat)  {}
    };
    int  NewData(); //创建数据库
    int  Print();   //显示数据信息
    int  Add();     //添加信息
    int  Search();  //搜索信息
    int  Delete(); //删除信息
    int  Sort();    //排序
    int  Save();    //保存信息
    int  Load();    //加载信息
    int  Statistic(); //统计
    
private:
    list <Student> listStu;
    
};
#endif /* defined(__SAMS__AchievementDatabase__) */
