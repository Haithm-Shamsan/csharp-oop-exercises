#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsCurrency.h"
class clsUpdateRateScreen:protected clsScreen
{
private:
	static void _PrintCurrncy(clsCurrency Currency)
	{
		cout << "Currency Card :";
		cout << "\n_________________________\n\n";
		cout << "Country :" << Currency.Country() << endl;
		cout << "Code :" << Currency.CurrencyCode() << endl;
		cout << "Name :" << Currency.CurrencyName() << endl;
		cout << "Rate/($) :" << Currency.Rate() << endl;
		cout << "\n_________________________\n";
	}
	static float _ReadNewRate()
	{
		float NewRate = 0;
		cout << "Enter New Rate :" << endl;
		NewRate=clsInputValidate<float>::ReadNumber();
		return NewRate;
	}
	

public:

	static void ShowUpdateRateScreen()
	{
		
		
		
		cout << "Please Enter CurrencyCode : " << endl;
		string CurrencyCode = clsInputValidate<string>::ReadString();
		clsCurrency Currency =clsCurrency::FindByCode(CurrencyCode);
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Currency Not found Enter Again :" << endl;
			CurrencyCode = clsInputValidate<string>::ReadString();
		}
		_PrintCurrncy(Currency);

		cout << "\n\n Are you sure you want to update rate to this currency ?y/n" << endl;
		char Answer = 'n';
		cin >> Answer;

		cout << "\nUpdate Currency Rate \n";
		cout << "\n___________________________\n";
		if (Answer == 'Y' || Answer == 'y')
		{
			Currency.UpdateRate(_ReadNewRate());
			cout << "Currency Updated Succssfully :-)" << endl;

			_PrintCurrncy(Currency);
		}


	}


};

