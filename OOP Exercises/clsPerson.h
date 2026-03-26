#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
    
    private:
      
        string _FirstName;
        string _LastName;
        string _Email;
        string _Phone;


    public:
    
  clsPerson( string FirstName, string LastName, string Email, string Phone)
        {

            
            _FirstName = FirstName;
            _LastName = LastName;
            _Email = Email;
            _Phone = Phone;



        }

       
        void SetFirstName(string FirstName)
        {
            _FirstName = FirstName;
        }

        string GetFirstName()
        {
            return _FirstName;
        }
        __declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;
        void SetLastName(string LastName)
        {
            _LastName = LastName;
        }
        string GetLastName()
        {
            return _LastName;
        }
        __declspec(property(get = GetLastName, put = SetLastName))string LastName;

        string GetFullName()
        {
            return _FirstName + " " + _LastName;
        }

        void SetEmail(string Email)
        {
            _Email = Email;
        }
        string GetEmail()
        {
            return _Email;
        }
        __declspec(property(get = GetEmail, put = SetEmail))string Email;
        void SetPhone(string Phone)
        {
            Phone = _Phone;
        }
        string GetPhone()
        {
            return _Phone;
        }
        __declspec(property(get = GetPhone, put = SetPhone))string Phone;






        void Print()
        {
            cout << "Person1 Information" << endl;
            cout << "\n______________________________\n";
          
            cout << "First Name  : " << _FirstName << endl;
            cout << "Last Name   : " << _LastName << endl;
            cout << "Full Name   : " << GetFullName() << endl;
            cout << "Email       : " << _Email << endl;
            cout << "Phone       : " << _Phone << endl;
            cout << "_______________________________\n";
        }

        void SentEmail(string Subject, string Body)
        {
            cout << "\n\nThe Folwing Massege Send succssfully to this Email :" << _Email << endl;
            cout << "\nSubject : " << Subject << endl;
            cout << "\nBody    : " << Body << endl;
        }
        void SentSMS(string Contant)
        {
            cout << "\nThe Folowing Massage sent seccssfully to the Number : " << _Phone << endl;
            cout << Contant << endl;
        }

    
};

