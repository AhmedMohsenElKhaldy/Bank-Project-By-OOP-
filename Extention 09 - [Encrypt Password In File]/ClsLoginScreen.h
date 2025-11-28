#pragma once
#include<iostream>
#include"ClsUser.h"
#include"Global.h"
#include"ClsScreen.h"
#include"ClsMainScreen.h"
#include"ClsAddDateToLockFile.h"
using namespace std;

class ClsLoginScreen : protected ClsScreen
{
private:
	static bool _Login()
	{

		string UserName, Password;

		bool FaildLogin = false;
		short LoginFaildScreen = 0;
	do
	{
		
		if (FaildLogin)
		{
		  Counter++;

		  cout << "\nInvalid Data, Enter Again \n";
		  
		  cout << "You Have " << 3 - Counter << " Trials To Login\n\n";
		}
		if (Counter == 3)
		{
			cout << "\nYour Locked After 3 Faild Trials\n";
			//Status = Locked;
			return false;
		}

		cout << "Enter Username: ";
		cin >> UserName;
		
		cout << "Enter Password: ";
		cin >> Password;
		
		CurrentUser = ClsUser::Find(UserName, Password);

		FaildLogin = CurrentUser.ISEmpty();
		
	
	} while (FaildLogin);

	CurrentUser.RegisterLogin();
	ClsMainScreen::ShowMainMenueScreen();
	return true;
	}

public:

	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("\tLogin Screen");
		return _Login();
	}
};

