#pragma once
#include<iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsTransfer :protected clsScreen
{
private:

	static void _PrintClinetInfo(clsBankClient Client)
	{
		cout << "\n______________________\n";
		cout << "Name : " << Client.GetFullName() << endl;
		cout << "Account Number : " << Client.AccountNumber() << endl;
		cout << "Balance : " << Client.AccountBalance;
		cout << "\n______________________\n";
	}


	static string _ReadAccountNumber(string Massage="")
	{
		string AccountNumber;
		cout << Massage<<endl;
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Invalied Account Number /Enter Again : " << endl;
			AccountNumber = clsInputValidate<string>::ReadString();
		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SorceClient)
	{

          float Amount = 0;
		 cout << endl << "Enter Transfer Ammount : " << endl;
		 Amount = clsInputValidate<float>::ReadNumber();

		/* while (Amount > SorceClient.AccountBalance)
		 {
			 cout << "The Ammount Bigger Than your Balance/ Enter Again : " << endl;
			 Amount = clsInputValidate::ReadFolatNumber();

		 }*/
		 return Amount;

	}


public:

	static void ShowTransferScreen()
	{


		clsScreen::_DrawScreenHeader("Transfer Screen ");

		 clsBankClient SourceClient=clsBankClient::Find(_ReadAccountNumber("\n\nEnter Account Number That you want to transfer from "));
		 _PrintClinetInfo(SourceClient);
	   
		 clsBankClient DistnationClient = clsBankClient::Find(_ReadAccountNumber("Enter Account Number That you want to transfer to"));
		 _PrintClinetInfo(DistnationClient);

		 float Amount = _ReadAmount(SourceClient);
		 char Answer = 'n';
		 cout << "Are you sure you want to transfer [" << Amount << "] To " << DistnationClient.GetFullName() << "? y/n" << endl;
		 cin >> Answer;

		 if (SourceClient.Transfer(Amount, DistnationClient,CurrentUser.UserName))
		 {
			 cout << "Transfer done Seccssfully " << endl;
		 }
		 else
			 cout << "Filed Transfer " << endl;
		 
		 _PrintClinetInfo(SourceClient);
		 cout << endl;
		 _PrintClinetInfo(DistnationClient);
		 
		 
	}
	
	




};

