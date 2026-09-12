#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
       
       if (CurrentUser.IsEmpty() == true)
       {
           cout << "\t\t\t\t\t";
           cout << "User: ";
           cout << "\033[31mNo User Logged In\033[0m\n";
 
       }
       else
       {
           string User = CurrentUser.UserName + " - " + CurrentUser.FullName();
           cout << "\t\t\t\t\t";
           cout << "User: ";
           cout << "\033[32m" << User << "\033[0m\n";
       }

        cout << "\t\t\t\t\t";
        cout << "Date: ";
        clsDate().Print();
        cout << "\n";
    }

    static bool  CheckAccessRights(clsUser::enPermissions ScreenPermissionValue)
    {
        if (CurrentUser.CheckAccessPermission(ScreenPermissionValue) == false)
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        return true;
    }

};
