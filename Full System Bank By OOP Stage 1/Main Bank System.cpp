#include <iostream>
#include"ClsMainScreen.h"

using namespace std;

void showTotalBalanceToClient(ClsBankClient C1)
{
	cout << "| " << left << setw(15) << C1.AccountNumber();
	cout << "| " << left << setw(25) << C1.FullName();
	cout << "| " << left << setw(15) << C1.AccountBalance;

	cout << endl;
}
void showTotalBalanceToClients()
{
	vector<ClsBankClient>Client;
	Client = ClsBankClient::GetDataClient();
	
    cout << "\n\t\t\t\t\t" << "Number Of Client Is [" << Client.size()<< "] (s)" << endl;

	cout << "\n-------------------------------------------------------\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(25) << "Client Name";
	cout << "| " << left << setw(15) << "Balance";
	cout << "\n-------------------------------------------------------\n";
	
	double TotalBalances = ClsBankClient::GetTotalBalancese
	(ClsBankClient::GetDataClient());
	
	if (Client.size() == 0)cout << "Errer";
	
	else
	{
		for(ClsBankClient& C : Client)
		{
			showTotalBalanceToClient(C);
		}
	}
	cout << "\n-------------------------------------------------------\n";

	cout << "\n\t\t\tTotoal Balances Is " << TotalBalances<<endl;

	cout << "\t\t\t"<<ClsInputValidate::NumberToText(TotalBalances) << endl;
}






int main()
{
	ClsMainScreen::ShowMainMenueScreen();

   system("pause");
}
