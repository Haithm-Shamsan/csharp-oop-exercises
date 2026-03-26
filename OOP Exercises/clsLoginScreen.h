#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsGloble.h"
#include "clsMainScreen.h"
class clsLoginScreen:protected clsScreen
{

private:

static bool _Login()
	{
		string UserName, password;
		bool LoginFiled = false;
		short FiledLoginCount = 0;
		do
		{
		
			if (LoginFiled)
			{
				cout << "Invalied Username,Password !\n";
				FiledLoginCount++;
				cout << "You have " <<3-FiledLoginCount << "Triels to Login.";
		     }

			if (FiledLoginCount == 3)
			{
				cout << "you have Locked after 3 Triels ";
				false;


			};
			

			cout << "\n\nEnter UserName :" << endl;
			cin >> UserName;
			cout << "Enter Password :" << endl;
			cin >> password;

			CurrentUser = clsUser::Find(UserName, password);
			 LoginFiled=CurrentUser.IsEmpty();

			


		} while (LoginFiled);
	
		CurrentUser.RegestrLogIn();
		clsMainScreen::ShowMainMenue();
		return true;

	}





public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
}




};

