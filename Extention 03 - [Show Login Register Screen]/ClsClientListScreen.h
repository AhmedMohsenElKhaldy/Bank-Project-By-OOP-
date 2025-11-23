#pragma once
#include<iostream>
#include"ClsBankClient.h"
#include"ClsScreen.h"
#include<iomanip>

using namespace std;
class ClsClientListScreen : protected ClsScreen
{
private:
	static void _showDataClient(ClsBankClient C1)
{
		
	cout << setw(8) << left <<  "" << "| " << setw(15) << left << C1.AccountNumber();
	cout << "| " << left << setw(20) << C1.FullName();
	cout << "| " << left << setw(10) << C1.Phone;
	cout << "| " << left << setw(20) << C1.Email;
	cout << "| " << left << setw(10) << C1.PinCode;
	cout << "| " << left << setw(12) << C1.AccountBalance;
	cout << endl;
}
public:
static void ShowClientList()
{
	if (!CheckPermissionRight(ClsUser::enPermissions::pListClients))
	{
		return;
	}
   vector<ClsBankClient> DataClient;
   DataClient = ClsBankClient::GetDataClient();

   string Titel = "\t  Clients List Screen";
   string SubTitel = "\t  (" + to_string(DataClient.size()) + ") Client(s).";
   _DrawScreenHeader(Titel, SubTitel);

    cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n";

        cout <<  setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(10) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n";

   

   if (DataClient.size() == 0)
   {
	   cout << "\t\t\t\t\t No Client Available In the System\n";
   }
   else
   {
	   int t = 0;
	   for (ClsBankClient& C : DataClient)
	   {
		   
		   _showDataClient(C);
		
	   }
   }

   cout << setw(8) << left << "" << "___________________________________________________________";
   cout << "_____________________________________\n" << endl;

} 


};

