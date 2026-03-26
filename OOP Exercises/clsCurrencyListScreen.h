#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include <string>
class clsCurrencyListScreen:protected clsScreen
{
private:

        static void PrintClientRecordLine(clsCurrency Currency)
        {

            cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
            cout << "| " << setw(20) << left << Currency.CurrencyCode();
            cout << "| " << setw(30) << left << Currency.CurrencyName();
            cout << "| " << setw(20) << left << Currency.Rate();
         

        }

 public:


        static void ShowClientsList()
        {
           /* if (!CheckAccessRight(clsUser::))
            {
                return;
            }*/

            vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
            string Title = "\t  Currencyl List Screen";
            string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Client(s).";

            _DrawScreenHeader(Title, SubTitle);


            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
            cout << "| " << left << setw(20) << " Code";
            cout << "| " << left << setw(30) << " Name";
            cout << "| " << left << setw(20) << "Rates/($)";
           
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vCurrencies.size() == 0)
                cout << "\t\t\t\tNo Currencies Available In the System!";
            else

                for (clsCurrency Currency : vCurrencies)
                {

                    PrintClientRecordLine(Currency);
                    cout << endl;
                }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

        }

    };



