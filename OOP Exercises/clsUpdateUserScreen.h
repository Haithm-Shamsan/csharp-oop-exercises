#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include"clsUser.h"
class clsUpdateUserScreen:protected clsScreen
{
private:

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "Enter First Name : ";
		User.FirstName = clsInputValidate<string>::ReadString();
		cout << "Enter Last Name : ";
		User.LastName = clsInputValidate<string>::ReadString();
		cout << "Enter Email : ";
		User.Email = clsInputValidate<string>::ReadString();
		cout << "Enter Phone Number :";
		User.Phone = clsInputValidate<string>::ReadString();
		cout << "Enter UserName : ";
		User.UserName = clsInputValidate<string>::ReadString();
		cout << "Enter PassWord : ";
		User.Password = clsInputValidate<string>::ReadString();
		cout << "Enter Premissions : ";
		User.Permissions = _ReadPermissionToSet();


	}
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.GetFullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}

	static int _ReadPermissionToSet()
	{
		int Permissions = 0;
		char Answer = 'y';


		cout << "Do you want to give full access?y/n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "Do you want to give access to :" << endl;

		cout << "\nShow Client List? y/n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pClientList;
		}

		cout << "\n Add New Client ? y/n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pAddNewClinet;
		}

		cout << "\n Delete Client? y/n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pDeleteClient;

		}
		cout << "\nUpdate Client  ? y/n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nFind Client ? y/n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nShow Transaction Menue ? y/n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pTransaction;

		}

		cout << "\nShow User Menue ? y/n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			 Permissions += clsUser::enPermissions::pManageUser;
		}

		cout << "Show Login Register?y/n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
		 Permissions+=clsUser::enPermissions::pLoginRegiser;
		}

		return Permissions;
	}

	public:
		static void ShowUpdateUserScreen()
		{ _DrawScreenHeader("Update User Screen");
		 
		string UserName = "";
		cout << "Enter Username :" << endl;
		 UserName=clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "there is no username like that enter again :" << endl;
			 UserName=clsInputValidate<string>::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		cout << "Are you sure you want to change that user ? " << endl;
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "  Update Screen ";
			cout << "\n___________________________\n";

			_ReadUserInfo(User);

			clsUser::enSaveResults SaveResulte;
			SaveResulte = User.Save();

			switch (SaveResulte)
			{
			case clsUser::svFaildEmptyObject:

				cout << "Save User process filed becouse its empty " << endl;


				break;
			case clsUser::svSucceeded:

				cout << "Save User process Seccessded :-)" << endl;
				_PrintUser(User);
				break;
		
			}


		}



        }
		

};

