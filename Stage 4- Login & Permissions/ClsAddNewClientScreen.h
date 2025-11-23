#pragma once
#include"ClsBankClient.h"
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include<iomanip>

class ClsAddNewClientScreen : protected ClsScreen
{
private:
	static void _ReadClientInfo(ClsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = ClsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = ClsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = ClsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = ClsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = ClsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = ClsInputValidate::ReadFloNumber();
	}
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
	static void AddNewClient()
{
		if (!CheckPermissionRight(ClsUser::enPermissions::pAddNewClient))
		{
			return;
		}
	_DrawScreenHeader("Add New Client Screen");
	
	string AccountNumber;
	cout << "Enter Account Number For New Account Number\n";
	AccountNumber = ClsInputValidate::ReadString();
	
	while (ClsBankClient::IsClientExist(AccountNumber))
	{
		cout << "This Client Exist,Enter Another Account Number\n";
		AccountNumber = ClsInputValidate::ReadString();
	} 

	ClsBankClient NewClient = ClsBankClient::GetAddNewClientObject(AccountNumber);
	_ReadClientInfo(NewClient);

	ClsBankClient::EnSaveDataMode SaveMode;
	
	SaveMode = NewClient.Save();
	
	switch (SaveMode)
	{
	case ClsBankClient::EnSaveDataMode::enSuccessfullySave:
		cout << "Successfully Operation\n";
		_PrintDataClient(NewClient);
		break;
	case ClsBankClient::EnSaveDataMode::enFaildSaveExsistAcountNumber:
		cout << " This Account Number Is Already Exsist\n";
		break;
	case ClsBankClient::EnSaveDataMode::enFailedEmptyObject:
		cout << "Error did't Find Data To This Account Number\n";
		break;
	}
}

};

