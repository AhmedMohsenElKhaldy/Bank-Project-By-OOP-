#pragma once
#include<iostream>
#include"ClsUser.h"
#include"ClsScreen.h"
#include<iomanip>

using namespace std;

class ClsUsersListScreen :protected ClsScreen
{
private:
		static void _showDataClient(ClsUser U1)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << U1.FullName();
		cout << "| " << left << setw(15) << U1.Email;
		cout << "| " << left << setw(10) << U1.Phone;
		cout << "| " << left << setw(10) << U1.UserName;
		cout << "| " << left << setw(8) << U1.Password;
		cout << "| " << left << setw(9) << U1.Permissions;
		cout << endl;
	}

public:
	static void ShowClientList()
	{
		vector<ClsUser> DataUsers;
		DataUsers = ClsUser::GetDataUsers();

		string Titel = "\t  Users List Screen";
		string SubTitel = "\t  (" + to_string(DataUsers.size()) + ") User(s).";
		_DrawScreenHeader(Titel, SubTitel);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n";

		cout << setw(8) << left << "" << "| " << left << setw(30) << "First Name";
		cout << "| " << left << setw(15) << "Email";
		cout << "| " << left << setw(10) << "Phone";
		cout << "| " << left << setw(10) << "User Name";
		cout << "| " << left << setw(8) << "Password";
		cout << "| " << left << setw(9) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n";

		

		if (DataUsers.size() == 0)
		{
			cout << "\t\t\t\t\t No Client Available In the System\n";
		}
		else
		{
	
			for (ClsUser& U : DataUsers)
			{

				_showDataClient(U);

			}
		}

		cout << setw(8) << left << "" << "___________________________________________________________";
		cout << "_____________________________________\n" << endl;

	}

		

};

