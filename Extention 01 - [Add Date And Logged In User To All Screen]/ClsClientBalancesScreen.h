#pragma once
#include"ClsBankClient.h"
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include<iomanip>

using namespace std;
class ClsClientBalancesScreen : protected ClsScreen
{
private:
static void _showTotalBalanceToClient(ClsBankClient C1)
	{
	cout << setw(17) << left << "";
		cout << "| " << left << setw(15) << C1.AccountNumber();
		cout << "| " << left << setw(25) << C1.FullName();
		cout << "| " << left << setw(15) << C1.AccountBalance;

		cout << endl;
	}
public:
static void showTotalBalanceToClients()
	{
		vector<ClsBankClient>Client;
		Client = ClsBankClient::GetDataClient();
		
		string Titel = "\t Client Balances Screen";
		string SubTitel = "\t (" + to_string(Client.size()) + ") Client(s)";

        _DrawScreenHeader(Titel, SubTitel);
		
		cout << setw(17) << left << "" << "\n\t\t_______________________________________________________";
		cout << "___________________\n";

		
		cout << setw(17) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(25) << "Client Name";
		cout << "| " << left << setw(15) << "Balance";
		cout << setw(17) << left << "" << "\n\t\t________________________________________________________";
		cout << "__________________\n";

		double TotalBalances = ClsBankClient::GetTotalBalancese
		(ClsBankClient::GetDataClient());

		if (Client.size() == 0)cout << "Error, Empty CLient..";

		else
		{
			for (ClsBankClient& C : Client)
			{
				_showTotalBalanceToClient(C);
			}
		}
		cout << setw(17) << left << "" << "\n\t\t-------------------------------------------------------";
		cout << "-------------------\n" << endl;

		cout << "\n\t\t\tTotal Balances Is " << TotalBalances << endl;

		cout << "\t\t\t" << ClsInputValidate::NumberToText(TotalBalances) << endl;
	}

};

