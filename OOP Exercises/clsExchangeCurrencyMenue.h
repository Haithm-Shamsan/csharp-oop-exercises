#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsCurrencyListScreen.h"
#include "clsFindCurrncy.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsExchangeCurrencyMenue:protected clsScreen
{
 private:
	enum enExchangeCurrencyMenue {
		enListCurrencies = 1, enFindCurrency = 2, enUpdateRate = 3, enCurrencyCalculator = 4, enBackToMainMenue = 5
	};
	static void _ShowListCurrenciesScreen()
	{
		/*cout << "List Currencies Will Be Here\n";*/
		clsCurrencyListScreen::ShowClientsList();
	}


	static void _ShowFindCurrencyScreen()
	{
		/*cout << "Find Currency Will Be Here\n";*/
		clsFindCurrncy::FindCurrencyScreen();
	}

	static void _ShowUpdateRateCurrencyScreen()
	{
		/*cout << "List Currencies Will Be Here\n";*/
		clsUpdateRateScreen::ShowUpdateRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		/*cout << "Currency Calculator Will Be Here\n";*/
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
		_BackToExchangeCurrencyMenue();
	}

	
	static void _BackToExchangeCurrencyMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowExchangeCurrencyMenue();

	}

	static short _ReadNumber()
	{
		cout << "Enter Number Form [1 - 5]" << endl;
		short Answer = clsInputValidate<short>::ReadNumberBetween(1, 5);
		return Answer;
	}

	static void PreformExchangeCurrencyMenue(enExchangeCurrencyMenue ExchangeCurrency)
	{
		
		switch (ExchangeCurrency)
		{
		case clsExchangeCurrencyMenue::enListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_BackToExchangeCurrencyMenue();
			break;
		case clsExchangeCurrencyMenue::enFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_BackToExchangeCurrencyMenue();
			break;

		case clsExchangeCurrencyMenue::enUpdateRate:
			system("cls");
			_ShowUpdateRateCurrencyScreen();
			_BackToExchangeCurrencyMenue();
			break;
		case clsExchangeCurrencyMenue::enCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			
			break;
		case clsExchangeCurrencyMenue::enBackToMainMenue:
			system("cls");
			
			break;
		
		}





	}


public:


	static void ShowExchangeCurrencyMenue()
	{

		system("cls");
		_DrawScreenHeader("\t\Exchange Currency Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tExchange Currency Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Currencies List.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency .\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Back To Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		PreformExchangeCurrencyMenue(enExchangeCurrencyMenue(_ReadNumber()));
		return;
	}
};

