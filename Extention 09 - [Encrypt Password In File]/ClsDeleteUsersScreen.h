#pragma once
#include"ClsUser.h"
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include<iomanip>

class ClsDeleteUsersScreen : protected ClsScreen
{
private:
	static void _PrintDataClient(ClsUser U)
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
		cout << "\nPermissions     : " << U.Permissions;
		cout << "\n___________________\n";

	}

public:
	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("Delete User Screen");
		string UserName;
	cout << "User Name Number That Want Delete It\n";
	UserName = ClsInputValidate::ReadString();

	while (!ClsUser::IsClientExist(UserName))
	{
		cout << "This User  Exist,Enter Another User Name\n";
		UserName = ClsInputValidate::ReadString();
	}

	ClsUser User = ClsUser::Find(UserName);
	_PrintDataClient(User);
	char Op;
	cout << "Do You Want Delete This User From List\n";
	cin >> Op;
	if (toupper(Op) == 'Y')
	{
		if (User.Delete())
		{
			cout << "Delete Operation Is Successfully\n";
			_PrintDataClient(User);
		}
		else
		{
			cout << "Not Delete Client Find Error\n";
		}
	}

}
};

