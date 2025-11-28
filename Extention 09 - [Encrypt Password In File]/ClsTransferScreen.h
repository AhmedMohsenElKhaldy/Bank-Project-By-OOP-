#pragma once
#include"ClsBankClient.h"
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include<iomanip>

using namespace std;
class ClsTransferScreen : protected ClsScreen

{
private:
	static void _PrintDataClient(ClsBankClient C)
	{
	cout << "\nClient Card:";
	cout << "\n___________________";
	cout << "\nFull Name   : " << C.FullName();
	cout << "\nAcc. Number : " << C.AccountNumber();
	cout << "\nBalance     : " << C.AccountBalance;
	cout << "\n___________________\n";

}

	static ClsBankClient _ReadDataClientTransferFrom()
	{
		cout << "Enter Account Number That Transfer From It..?\n";
				string AcountNumber = _ReadAccountNumber();
	
		while (!ClsBankClient::IsClientExist(AcountNumber))
		{
			cout << "Account Number [" << AcountNumber <<
				"] Not Exist, Enter Another Account Number..? ";
			AcountNumber = _ReadAccountNumber();
		}
	
		ClsBankClient ClientFrom = ClsBankClient::Find(AcountNumber);
		return ClientFrom;
	}
	
	static ClsBankClient _ReadDataClientTransferTo()
	{
		cout << "Enter Account Number That Transfer To It..?\n";
		string AcountNumber = _ReadAccountNumber();

		while (!ClsBankClient::IsClientExist(AcountNumber))
		{
			cout << "Account Number [" << AcountNumber <<
				"] Not Exist, Enter Another Account Number..? ";
			AcountNumber = _ReadAccountNumber();
		}

		ClsBankClient ClientTo = ClsBankClient::Find(AcountNumber);
		return ClientTo;
	}
	
	static string _ReadAccountNumber()

{
	string AccountNumber = ClsInputValidate::ReadString();
	return AccountNumber;
}

//static ClsBankClient _ReadDataClientTransferFrom()
//{
//		cout << "Enter Account Number That Transfer From It..?\n";
//		string AcountNumber = _ReadAccountNumber();
//
//		while (!ClsBankClient::IsClientExist(AcountNumber))
//		{
//			cout << "Account Number [" << AcountNumber <<
//				"] Not Exist, Enter Another Account Number..? ";
//			AcountNumber = _ReadAccountNumber();
//		}
//
//		ClsBankClient ClientFrom = ClsBankClient::Find(AcountNumber);
//
//		_PrintDataClient(ClientFrom);
//		return ClientFrom;
//
//
//}

//static ClsBankClient _ReadDataClientTransferTo()
//	{
//		cout << "Enter Account Number That Transfer To It..?\n";
//		string AcountNumber = _ReadAccountNumber();
//
//		while (!ClsBankClient::IsClientExist(AcountNumber))
//		{
//			cout << "Account Number [" << AcountNumber <<
//				"] Not Exist, Enter Another Account Number..? ";
//			AcountNumber = _ReadAccountNumber();
//		}
//
//		ClsBankClient ClientTo = ClsBankClient::Find(AcountNumber);
//
//		_PrintDataClient(ClientTo);
//		return ClientTo;
//
//
//	}

public:

static void ShowWithdrawScreen()
{
	_DrawScreenHeader("\tTransfer Screen");

	ClsBankClient ClientFrom = _ReadDataClientTransferFrom();
	_PrintDataClient(ClientFrom);

	ClsBankClient ClientTo = _ReadDataClientTransferTo();
	_PrintDataClient(ClientTo);

	
	float Amount = 0;
	cout << "Please Enter Transfer Amount?\n";
	Amount = ClsInputValidate::ReadFloNumber();

	char Op;
	cout << "Are You Sure To Perform This Transaction?\n";
	cin >> Op;

	if (toupper(Op) == 'Y')
	{
			
		if (ClientFrom.Transfer(Amount, ClientTo, CurrentUser.UserName))
		{
			cout << "Amount Transfer Successfully\n";

			
		}
		else
		{
			cout << "Error, The Amount Is UnSuffecient\n";
			cout << "Your Amount Is: " << Amount << endl;
			cout << "Your Account Balance Is: " << ClientFrom.AccountBalance << endl;
			
		}
	}
	else
	{
		cout << "Error ,Not Transfer Amount\n";
	}
	
	_PrintDataClient(ClientFrom);
	_PrintDataClient(ClientTo);

	
}

};

