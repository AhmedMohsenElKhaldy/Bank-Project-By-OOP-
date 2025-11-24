#pragma once
#include<iostream>
#include"ClsScreen.h"
#include"ClsDate.h"
#include<vector>
#include"ClsUser.h"
#include<iomanip>

using namespace std;

class ClsUsersLoginData : protected ClsScreen
{
	private:

	
	static void _PrintDataUsersLogin(ClsUser::StDataUser U)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << U.Time;
		cout << "| " << left << setw(20) << U.UserName;
		cout << "| " << left << setw(10) << U.Password;
		cout << "| " << left << setw(20) << U.Per;
		
		cout << endl;
	}
public:
	
	static void ShowListLoginUsersScreen()

	{
		vector<ClsUser::StDataUser>UsersData = ClsUser::LoadUsersLoginDateFromFile();

		string Titel = "\t  Users Login List Screen";
		string SubTitel = "\t  (" + to_string(UsersData.size()) + ") Client(s).";
		_DrawScreenHeader(Titel, SubTitel);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n";

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Time/Date";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(20) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n";
	
		if (UsersData.size() == 0)
		{
			cout << "\t\t\t\t\t No Client Available In the System\n";
		}
		else
		{

			for (ClsUser::StDataUser& U : UsersData)
			{

				_PrintDataUsersLogin(U);

			}
		}

		cout << setw(8) << left << "" << "___________________________________________________________";
		cout << "_____________________________________\n" << endl;
	
	}

};

