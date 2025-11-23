#pragma once
#include"ClsBankClient.h"
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include<iomanip>

using namespace std;

class ClsWithdrawScreen : protected ClsScreen
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
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");

		cout << "Enter Account Number That Withdraw Amount From It..?\n";
		string AcountNumber = _ReadAccountNumber();

		while (!ClsBankClient::IsClientExist(AcountNumber))
		{
			cout << "Account Number [" << AcountNumber <<
				"] Not Exist, Enter Another Account Number..? ";
			AcountNumber = _ReadAccountNumber();
		}

		ClsBankClient Client1 = ClsBankClient::Find(AcountNumber);

		_PrintDataClient(Client1);

		float Amount = 0;

		cout << "Please Enter Withdraw Amount?\n";
		Amount = ClsInputValidate::ReadFloNumber();

		if (Client1.Wihtdraw(Amount))
		{

		char Op;
		cout << "Are You Sure To Perform This Transaction?\n";
		cin >> Op;

		if (toupper(Op) == 'Y')
		{
			cout << "Amount Deposit Successfully\n";

			cout << "Your Balance Become After Withdraw Operation "
				<< Client1.AccountBalance << endl;
		}
		else
		{
			cout << "Error ,Not Withdraw Amount\n";
		}
		}
		else
		{
			cout << "Error, The Amount Is UnSuffecient\n";
			cout << "Your Amount Is: " << Amount << endl;
			cout << "Your Account Balance Is: " << Client1.AccountBalance << endl;
		}
	}
};

