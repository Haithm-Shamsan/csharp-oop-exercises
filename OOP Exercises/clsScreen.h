#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include "clsGloble.h"
#include "clsDate.h"
#include <ctime>

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
            cout << "\n\t\t\t\t\t______________________________________\n";

            cout << "\n\t\t\t\t\tUser : " << CurrentUser.UserName<<"\n";
            cout << "\t\t\t\t\tDate : " << clsDate::DateToString(clsDate());
            
            cout << "\n";

        }

        static bool CheckAccessRight(clsUser::enPermissions Permissions)
        {
            if (! CurrentUser.CheckAccessPermission(Permissions))
            {
   cout << "\t\t\t\t\t______________________________________";
   cout << "\n\n\t\t\t\t\t  " << " Access Dinaid! Contact your admain";
 
            
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
            }
            else
                return true;
         
        }
    
};

