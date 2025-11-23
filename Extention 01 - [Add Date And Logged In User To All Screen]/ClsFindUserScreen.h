#pragma once

#include"ClsUser.h"
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include<iomanip>

class ClsFindUserScreen :protected ClsScreen
{
private:
	static void _PrintDataUser(ClsUser U)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << U.FirstName;
		cout << "\nLastName    : " << U.LastName;
		cout << "\nFull Name   : " << U.FullName();
		cout << "\nEmail       : " << U.Email;
		cout << "\nPhone       : " << U.Phone;
		cout << "\nUser Name   : " << U.UserName;
		cout << "\nPassword    : " << U.Password;
		cout << "\nPerimissions : " << U.Permissions;
		cout << "\n___________________\n";

	}
public:

	static void ShowFindScreen()
	{
		_DrawScreenHeader("\tFind User Screen");

		string UserName;
		
		cout << "User Name Number That Want Find It\n";
		UserName = ClsInputValidate::ReadString();

		while (!ClsUser::IsClientExist(UserName))
		{
			cout << "This User Name Not Found,Enter Another User Name\n";
			UserName = ClsInputValidate::ReadString();
		}

		ClsUser User = ClsUser::Find(UserName);

		if (!User.ISEmpty())
		{
			cout << "User Is Found\n";
			_PrintDataUser(User);
		}
		else
		{
			cout << "User Was Not Found\n";
		}
	}
};

