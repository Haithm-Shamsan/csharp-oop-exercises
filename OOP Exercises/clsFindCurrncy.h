#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsString.h"
#include <string>
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsFindCurrncy:protected clsScreen
{
private:



	static void _PrintCurrncy(clsCurrency Currency)
	{
		cout << "Currency Card :" ;
		cout << "\n_________________________\n\n";
		cout << "Country :" << Currency.Country()<<endl;
		cout << "Code :" << Currency.CurrencyCode() << endl;
		cout << "Name :" << Currency.CurrencyName() << endl;
		cout << "Rate/($) :" << Currency.Rate() << endl;
		cout << "\n_________________________\n";
	}

	static void _ShowReslulte(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "Currency Found :-)" << endl;
			 _PrintCurrncy(Currency);


		}
		else
		{
			cout << "Currency not found !" << endl;

		}
	}

public:
	static void FindCurrencyScreen()
	{
		
		clsScreen::_DrawScreenHeader("Find Currency Screen");
		short Answer = 0;

		cout << "Find By [1] Code [2] Country ?" << endl;
		cin >> Answer;

		if (Answer == 1)
		{
			
			cout << "Please Enter CurrncyCode : " << endl;
			string CurrncyCode = clsString::UpperAllString(clsInputValidate<string>::ReadString());
			
		 clsCurrency Currency=	clsCurrency::FindByCode(CurrncyCode);
		 _ShowReslulte(Currency);
		}
		else
		{
			cout << "Please Enter Country Name : " << endl;
			string Country = clsInputValidate<string>::ReadString();
			clsCurrency CurrencyByCountry = clsCurrency::FindByCountry(Country);
			cout << endl;
			_ShowReslulte(CurrencyByCountry);
			
			
			
		}


	}
};

