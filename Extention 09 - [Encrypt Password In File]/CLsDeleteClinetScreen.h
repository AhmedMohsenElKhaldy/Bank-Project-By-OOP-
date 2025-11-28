#pragma once
#include"ClsBankClient.h"
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include<iomanip>

class CLsDeleteClinetScreen : protected ClsScreen
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

public:
	static void ShowDeleteClientScreen()
{
	if (!CheckPermissionRight(ClsUser::enPermissions::pDeleteClient))
	{
		return;
	}
	string AccountNumber;
	cout << "Enter Account Number That Want Delete It\n";
	AccountNumber = ClsInputValidate::ReadString();

	while (!ClsBankClient::IsClientExist(AccountNumber))
	{
		cout << "This Client Exist,Enter Another Account Number\n";
		AccountNumber = ClsInputValidate::ReadString();
	}

	ClsBankClient Client = ClsBankClient::Find(AccountNumber);
	_PrintDataClient(Client);
	char Op;
	cout << "Do You Want Delete This Client From List\n";
	cin >> Op;
	if (toupper(Op) == 'Y')
	{
		if (Client.Delete())
		{
		cout << "Delete Operation Is Delete Successfully\n";
		_PrintDataClient(Client);
		}
		else
		{
			cout << "Not Delete Client Find Error\n";
		}
	}
	
}

};

