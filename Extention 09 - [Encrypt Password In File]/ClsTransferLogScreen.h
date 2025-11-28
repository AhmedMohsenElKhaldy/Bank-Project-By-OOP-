#pragma once
#include<iostream>
#include"ClsBankClient.h"
#include"ClsScreen.h"
#include<iomanip>

using namespace std;

class ClsTransferLogScreen:protected ClsScreen
{
 private:

	 static void _PrintDataUsersLogin(ClsBankClient::StDataTransfer C)

	 {
	
		 cout << setw(8) << left << "" << "| " << setw(18) << left << C.Date;
		 cout << "| " << left << setw(10) << C.AccFrom;
		 cout << "| " << left << setw(10) << C.AccTo;
		 cout << "| " << left << setw(12) << C.Amount;
		 cout << "| " << left << setw(12) << C.AccFromAfterTrasfer;
		 cout << "| " << left << setw(12) << C.AccToAtferTrasfer;
		 cout << "| " << left << setw(6) << C.UserName;
		 cout << endl;
}
public:


	static void ShowListLoginUsersScreen()

  
	{
	
	if (!CheckPermissionRight(ClsUser::enPermissions::PLoginRegisterList))
	
	{
	
	  return;
	
	}
	
	vector<ClsBankClient::StDataTransfer>ClientData = ClsBankClient::LoadDataTransferFromFile();

	
	string Titel = "\t  Transfer Log List Screen";
	
	string SubTitel = "\t  (" + to_string(ClientData.size()) + ") Client(s).";
	
	_DrawScreenHeader(Titel, SubTitel);

	
	cout << setw(8) << left << "" << "\n\t_______________________________________________________";
	cout << "_________________________________________\n";
	cout << setw(8) << left << "" << "| " << left << setw(18) << "Time/Date";
	cout << "| " << left << setw(10)  << "F.Account";
	cout << "| " << left << setw(10)  << "T.Account";
	cout << "| " << left << setw(12) << "Amount";
	cout << "| " << left << setw(12) << "F.Account.A";
	cout << "| " << left << setw(12) << "T.Account.A";
	cout << "| " << left << setw(6)  << "User";
	cout << setw(8) << left << "" << "\n\t_______________________________________________________";
	cout << "_________________________________________\n";

	if (ClientData.size() == 0)
	{
		cout << "\t\t\t\t\t No Client Available In the System\n";
	}
	else
	{

		for (ClsBankClient::StDataTransfer& U : ClientData)
		{

			_PrintDataUsersLogin(U);

		}
	}

	cout << setw(8) << left << "" << "___________________________________________________________";
	cout << "_____________________________________\n" << endl;

}
};

