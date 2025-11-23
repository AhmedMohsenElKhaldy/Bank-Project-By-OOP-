#pragma once
#include<iostream>
#include"ClsUser.h"
#include"Global.h"
#include"ClsScreen.h"
#include"ClsMainScreen.h"

using namespace std;

class ClsLoginScreen : protected ClsScreen
{
private:
	static void _Login()
	{
		string UserName, Password;

		bool FaildLogin = false;
	do
	{
		if (FaildLogin)
		{
			cout << "Invalid Data, Enter Again \n";
		}

		cout << "Enter Username: ";
		cin >> UserName;
		
		cout << "Enter Password: ";
		cin >> Password;
		
		CurrentUser = ClsUser::Find(UserName, Password);

		FaildLogin = CurrentUser.ISEmpty();
	
	} while (FaildLogin);
	
	ClsMainScreen::ShowMainMenueScreen();
	}

public:

	static void ShowLoginScreen()
	{
		_DrawScreenHeader("\tLogin Screen");
		_Login();
	}
};

