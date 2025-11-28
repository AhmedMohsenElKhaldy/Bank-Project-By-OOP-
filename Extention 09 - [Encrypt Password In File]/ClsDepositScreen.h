#pragma once
#include"ClsBankClient.h"
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include<iomanip>

using namespace std;

class ClsDepositScreen : protected ClsScreen
{
private:
	static void _PrintDataClient(ClsBankClient C)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << C.FirstName;
		cout << "\nLastName    : " << C.LastName;
		cout << "\nFull Name   : " << C.FullName();
		cout << "\nEmail       : " << C.Email;
		cout << "\nPhone       : " << C.Phone;
		cout << "\nAcc. Number : " << C.AccountNumber();
		cout << "\nPassword    : " << C.PinCode;
		cout << "\nBalance     : " << C.AccountBalance;
		cout << "\n___________________\n";

	}
	static string _ReadAccountNumber()
	{
		string AccountNumber = ClsInputValidate::ReadString();
		return AccountNumber;
	}

public:
	static void ShowDepositScreen()
 {
		_DrawScreenHeader("Deposit Screen");
		
		cout << "Enter Account Number That Deposit Amount To It..?\n";
		string AcountNumber = _ReadAccountNumber();

		while (!ClsBankClient::IsClientExist(AcountNumber))
		{
			cout << "Account Number ["<< AcountNumber  <<
				"] Not Exist, Enter Another Account Number..? ";
			AcountNumber = _ReadAccountNumber();
		}

		ClsBankClient Client1 = ClsBankClient::Find(AcountNumber);
 
		_PrintDataClient(Client1);

		float Amount=0;
		
		cout << "Please Enter Deposit Amount?\n";
		Amount = ClsInputValidate::ReadFloNumber();
		
		char Op;
		cout << "Are You Sure To Perform This Transaction?\n";
		cin >> Op;

		if (toupper(Op) == 'Y')
		{
			Client1.Deposit(Amount);
			
			cout << "Amount Deposit Successfully\n";

			cout << "Your Balance Become After Deposit Operation "
				<< Client1.AccountBalance << endl;
		}
		else
		{
			cout << "Error ,Not Deposit Amount\n";
		}
	}
};

