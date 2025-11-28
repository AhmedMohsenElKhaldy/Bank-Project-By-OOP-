#pragma once
#include"ClsBankClient.h"
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include<iomanip>

using namespace std;

class ClsUpdateClientScreen : protected ClsScreen
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

   static void UpDateClient()
{
	 if (!CheckPermissionRight(ClsUser::enPermissions::pUpdateClients))
	 {
	  return;
	 }
	_DrawScreenHeader("Update Client Screen");
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

	cout << "\n\n Update Client Date\n";
	cout << "----------------\n";

	_ReadClientInfo(Client1);

	ClsBankClient::EnSaveDataMode SaveMode;
	SaveMode = Client1.Save();

	switch(SaveMode)
	{
	case ClsBankClient::EnSaveDataMode::enSuccessfullySave:
		cout << "Done, Data Update Successfully\n";
		break;
	case ClsBankClient::EnSaveDataMode::enFailedEmptyObject:
		cout << "Error, Account Not Save Because Is Empty.\n";
		break;
	}
}


};

