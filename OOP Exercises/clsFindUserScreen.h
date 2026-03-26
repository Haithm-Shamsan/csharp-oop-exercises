#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsFindUserScreen:protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.GetFullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("Find User Screen");
        string UserName = "";
        cout << "Enter UserName : " << endl;
        UserName = clsInputValidate<string>::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "That UserName not Fount Enter Again : " << endl;
            UserName = clsInputValidate<string>::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        if (!User1.IsEmpty())
        {
            cout << "User Found :-)\n\n";
          
        }
        else
        {
            cout << "User Not Found !" << endl;
        }
  _PrintUser(User1);

    }







};

