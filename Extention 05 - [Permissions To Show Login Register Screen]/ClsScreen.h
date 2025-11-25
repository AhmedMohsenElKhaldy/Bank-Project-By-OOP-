#pragma once
#include<iostream>
#include"Global.h"
#include"ClsUser.h"
#include"ClsDate.h"
using namespace std;
class ClsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\n\t\t\t\t\t_________________________________________";
        cout << "\n\n\t\t\t\t\t\t" << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t " << SubTitle;
        }
        cout << "\n\t\t\t\t\t_________________________________________\n";
  
        cout << "\n\t\t\t\t\t User Name : " << CurrentUser.UserName ;
        cout << "\n\t\t\t\t\t Date Login Is: " << ClsDate::DateToString(ClsDate());
        
        cout << "\n\n";
    }
    static bool CheckPermissionRight(ClsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckPermissions(Permission))
        {
            cout << "\n\t\t\t\t ________________________________________\n\n";
            cout << "\n\t\t\t\t\t Access Denied!, Call The Admin" ;
            cout << "\n\t\t\t\t_________________________________________\n\n";
            
            return false;
        }
        else
        {
            
            return true;
        }
    }
};

