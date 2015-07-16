//
//  main.cpp
//  SAMS
//
//  Created by Jack Peng on 15/7/16.
//  Copyright (c) 2015年 Jack Peng. All rights reserved.
//

#include <iostream>
#include "AchievementDatabase.h"
using namespace std;

int menu(){
    int k=0;
    cout << endl << endl;
    cout << "\t\tStudent Achievement Management System" << endl << endl;
    cout << setw(68) << setfill('*') << ' ' << endl;
    cout << "1 Create a database\t2 Print the scores\t3 Search the scores" << endl;
    cout << "4 Add a student\t\t5 Delete a student\t6 Sort the data" << endl;
    cout << "7 Save the database\t8 Load the database\t9 Statistics" << endl;
    cout << setw(68) << setfill('*') << ' ' << endl;
    cout << "Please enter the number you want(Enter 0 to exit):";
    cin >> k;
    return k;
}

int main(int argc, const char * argv[])
{
    AchivementDatabase Database;
    while (true) {
        int k=menu();
        switch (k) {
            case 1: Database.NewData(); break;
            case 2: Database.Print(); break;
            case 3: Database.Search(); break;
            case 4: Database.Add(); break;
            case 5: Database.Delete(); break;
            case 6: Database.Sort(); break;
            case 7: Database.Save(); break;
            case 8: Database.Load(); break;
            case 9: Database.Statistic(); break;
            case 0: return 0;
            default:
                cout << "Input error! Please try again!" << endl;
        }
    }
    return 0;
}
