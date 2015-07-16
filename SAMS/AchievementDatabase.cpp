//
//  AchievementDatabase.cpp
//  SAMS
//
//  Created by Jack Peng on 15/7/16.
//  Copyright (c) 2015年 Jack Peng. All rights reserved.
//

#include "AchievementDatabase.h"

int AchivementDatabase::NewData()
{
    static int n;
    float grades_eng,grades_chi,grades_mat;
    string str;
    
    cout << "Please enter the information of students, enter 0 to exit." << endl;
    while(true)
    {
        cout << "Now please enter the student ID:";
        cin >> n;
        if (n == 0) {
            listStu.sort([](const Student& Element1,const Student& Element2)->bool{return (Element1.Number - Element2.Number ) < 0;});
            return 0;
        }
        while(n < 0)
        {
            cout << "Input error! Please enter the student ID again:";
            cin >> n;
            if(find_if(listStu.cbegin(), listStu.cend(),[](const Student& Element)->bool{return (Element.Number == n);}) != listStu.cend())
            {
                cout << "Repeat number! Please enter the student ID again:";
                cin >> n;
            }
        }
        
        cout << "Please enter the name of the student:";
        cin >> str;
        
        cout << "Please enter the Chinese score of the student(0~100):";
        cin >> grades_chi;
        while(grades_chi < 0 || grades_chi > 100)
        {
            cout << "Input error! Please enter the score again:";
            cin >> grades_chi;
        }
        
        cout << "Please enter the Mathematics score of the student(0~100):";
        cin >> grades_mat;
        while(grades_mat < 0 || grades_mat > 100)
        {
            cout << "Input error! Please enter the score again:";
            cin >> grades_mat;
        }
        
        cout << "Please enter the English score of the student(0~100):";
        cin >> grades_eng;
        while(grades_eng < 0 || grades_eng > 100)
        {
            cout << "Input error! Please enter the score again:";
            cin >> grades_eng;
        }
        
        listStu.push_back(Student(n,str,grades_eng,grades_chi,grades_mat));
    }
}

int AchivementDatabase::Print()
{
    auto iElement=listStu.cbegin();
    if(iElement == listStu.cend())
    {
        cout << "There's no information in the database!" << endl;
        return 0;
    }
    cout << setw(65) << setfill('-') << '-' << endl;
    cout << "|Number\t|Name\t|Chinese\t|Mathematics\t|English\t|" << endl;
    cout << setw(65) << setfill('-') << '-' << endl;
    for(iElement = listStu.cbegin();
        iElement != listStu.cend();
        iElement ++)
    {
        cout << "|" << (*iElement).Number << "\t|" << (*iElement).Name << "\t|" << (*iElement).Chinese \
        << "\t\t|" << (*iElement).Math << "\t\t|" << (*iElement).English << endl;
        cout << setw(65) << setfill('-') << '-' << endl;
    }
	cout << "Press any key to continue.";
    getchar();
    getchar();
    return 0;
}

int AchivementDatabase::Add()
{
    static int n;
    float grades_eng,grades_chi,grades_mat;
    string str;
    
    cout << "Now please enter the student ID:";
    cin >> n;
    while(n < 0)
    {
        cout << "Input error! Please enter the student ID again:";
        cin >> n;
        if(find_if(listStu.cbegin(), listStu.cend(),[](const Student& Element)->bool{return (Element.Number==n);}) != listStu.cend())
           {
               cout << "Repeat number! Please enter the student ID again:";
               cin >> n;
           }
           }
           
           cout << "Please enter the name of the student:";
           cin >> str;
           
           cout << "Please enter the Chinese score of the student(0~100):";
           cin >> grades_chi;
           while(grades_chi < 0 || grades_chi > 100)
           {
               cout << "Input error! Please enter the score again:";
               cin >> grades_chi;
           }
           
           cout << "Please enter the Mathematics score of the student(0~100):";
           cin >> grades_mat;
           while(grades_mat < 0 || grades_mat > 100)
           {
               cout << "Input error! Please enter the score again:";
               cin >> grades_mat;
           }
           
           cout << "Please enter the English score of the student(0~100):";
           cin >> grades_eng;
           while(grades_eng < 0 || grades_eng > 100)
           {
               cout << "Input error! Please enter the score again:";
               cin >> grades_eng;
           }
           
           listStu.push_back(Student(n,str,grades_eng,grades_chi,grades_mat));
           
    listStu.sort([](const Student& Element1,const Student& Element2)->bool{return (Element1.Number - Element2.Number ) < 0;});
    
           cout << "There are" << listStu.size() << "students in the database now." << endl;
    return 0;
           }
           
int AchivementDatabase::Search()
{
       static int number=0;
       cout << "Please enter the student ID that you want to search:";
       cin >> number;
    
       if (number==0) {
           cout << "Input error! Now exit!" << endl;
           return 0;
       }
    
       auto iElement=listStu.begin();
       if(iElement==listStu.end())
           cout << "There's no information in the database!" << endl;
        
       iElement=find_if(listStu.begin(),listStu.end(),[](const Student& Input)->bool{return (Input.Number==number);});
        
       if(iElement != listStu.end())
       {
           cout << setw(65) << setfill('-') << '-' << endl;
           cout << "|Number\t|Name\t|Chinese\t|Mathematics\t|English\t|" << endl;
           cout << setw(65) << setfill('-') << '-' << endl;
           cout << "|" << (*iElement).Number << "\t|" << (*iElement).Name << "\t|" << (*iElement).Chinese \
           << "\t|" << (*iElement).Math << "\t|" << (*iElement).English << endl;
           cout << setw(65) << setfill('-') << '-' << endl;
       }
       else
           cout << "There is no the student!" << endl;
       return 0;
}
           
int AchivementDatabase::Delete()
{
    static int number;
    cout << "Please enter the student ID that you want to delete:";
    cin >> number;
            
    if (number==0) {
        cout << "Input error! Now exit!" << endl;
        return 0;
    }
    
    auto iElement=listStu.begin();
    if(iElement==listStu.end())
        cout << "There's no information in the database!" << endl;
            
    iElement=find_if(listStu.begin(),listStu.end(),[](const Student& Input)->bool{return (Input.Number==number);});
            
    if(iElement != listStu.end())
    {
        listStu.erase(iElement);
    }
    else
        cout << "There is no the student!" << endl;
    
    cout << "There are" << listStu.size() << "students in the database now." << endl;
    return 0;
}
           
int AchivementDatabase::Sort()
{
    if (listStu.begin() == listStu.end()) {
        cout << "There is no information in the database, please create a new database!" << endl;
        return 0;
    }
    int i;
    
    cout << setw(65) << setfill('*') << '*' << endl;
    cout << "1 Sort by number\t2 Sort by name\t3 Sort by English scores" << endl;
    cout << "4 Sort by math scores\t5 Sort by Chinese scores" << endl;
    cout << setw(65) << setfill('*') << '*' << endl;
    cout << "Please choose the number you want:";
    cin >> i;
    
    switch (i) {
        case 1:
            listStu.sort([](const Student& Element1,const Student& Element2)->bool{return (Element1.Number) < (Element2.Number);});
            break;
        case 2:
            listStu.sort([](const Student& Element1,const Student& Element2)->bool{return (Element1.Name) < (Element2.Name);});
            break;
        case 3:
            listStu.sort([](const Student& Element1,const Student& Element2)->bool{return (Element1.English) > (Element2.English);});
            break;
        case 4:
            listStu.sort([](const Student& Element1,const Student& Element2)->bool{return (Element1.Math > Element2.Math);});
            break;
        case 5:
            listStu.sort([](const Student& Element1,const Student& Element2)->bool{return (Element1.Chinese) > (Element2.Chinese);});
                    break;
                default:
                    cout << "Input error! Now exit!" << endl;return 0;
            }
            
            (*this).Print();
            return 0;
        }
           
           int AchivementDatabase::Save()
        {
            string fname;
            cout << "Please enter the name of the file:";
            cin >> fname;
            
            fstream wFile;
            wFile.open(fname,ios_base::out|ios_base::trunc);
            
            if (wFile.is_open())
            {
                auto iElement=listStu.cbegin();
                if(iElement == listStu.cend())
                {
                    cout << "There's no information in the database!" << endl;
                    return 0;
                }
                wFile << "\t\tStudent Achievement Management System" << endl;
                wFile << setw(65) << setfill('-') << '-' << endl;
                wFile << "|Number\t|Name\t|Chinese\t|Mathematics\t|English\t|" << endl;
                wFile << setw(65) << setfill('-') << '-' << endl;
                for(iElement=listStu.cbegin();
                    iElement != listStu.cend();
                    iElement ++)
                {
                    wFile << (*iElement).Number << "\t" << (*iElement).Name << "\t" << (*iElement).Chinese \
                    << "\t" << (*iElement).Math << "\t" << (*iElement).English << endl;
                }
                wFile.close();
            }
            else
            {
                cout << "Can't open the file!" << endl;return 0;
            }
            cout << "File is writen successfully!" << endl;
            return 0;
        }
           
           int AchivementDatabase::Load()
        {
            string fname;
            
            cout << "Please enter the name of the file:";
            cin >> fname;
            
            fstream rFile;
            rFile.open(fname,ios_base::in);
            
            if (rFile.is_open())
            {
                listStu.erase(listStu.begin(),listStu.end());
                int n;
                float grades_eng,grades_chi,grades_mat;
                string str;
                
                for(int index=1; index <= 4; index++)
                    getline(rFile,str);
                while(!rFile.eof()){
                    rFile >> n >> str >> grades_chi >> grades_mat >> grades_eng;
                    listStu.push_back(Student(n,str,grades_eng,grades_chi,grades_mat));
                }
                listStu.erase(--listStu.cend());
                rFile.close();
            }
            else
            {
                cout << "Can't open the file!" << endl;return 0;
            }
            (*this).Print();
            return 0;
        }
           
           int AchivementDatabase::Statistic()
        {
            
            return 0;
        }
