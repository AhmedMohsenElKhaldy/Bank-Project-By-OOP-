#pragma once
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include"ClsBankClient.h"
#include<iomanip>

using namespace std;

class ClsFindclientScreen : protected ClsScreen
{
private:
	static void _PrintClientInfo(ClsBankClient C)
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

public:
	static void FindCLientScreen()
	{
		if (!CheckPermissionRight(ClsUser::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("Find Client Screen");
		string AccNumber = "";
		cout << "Please Enter The Account Number For Update Client\n";
		AccNumber = ClsInputValidate::ReadString();

		while (!ClsBankClient::IsClientExist(AccNumber))
		{
			cout << "Wrong Account Number Not Exist Please Try Again\n";
			AccNumber = ClsInputValidate::ReadString();

		}

		/*ClsBankClient Client1 = ClsBankClient::Find(AccNumber);
		while (Client1.Empty())
		{
		cout << "Wrong Account Number Not Exist Please Try Again\n";
		AccNumber = ClsInputValidate::ReadString();
		} */

		ClsBankClient Client1 = ClsBankClient::Find(AccNumber);
		if (!Client1.ISEmpty())
		{
			cout << "Client Found:-)\n";
		}
		else
		{
			cout << "Clinet Was Not Find\n";
		}
			_PrintClientInfo(Client1);
	
	}
};

