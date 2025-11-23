#pragma once
#include"ClsUser.h"
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include<iomanip>

class ClsUpdateUserScreen:protected ClsScreen
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
	static void _ReadUserInfo(ClsUser& User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = ClsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = ClsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = ClsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = ClsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = ClsInputValidate::ReadString();

		cout << "\nEnter Perimissions: ";
		User.Permissions = _ReadPermissrtion();
	}
	static int _ReadPermissrtion()
	{
		int Permissions = 0;



		cout << "\nDo you want to give full access? y/n? ";

		if (ClsInputValidate::ReadYesOrNo())
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";

		if (ClsInputValidate::ReadYesOrNo())
		{


			Permissions += ClsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";

		if (ClsInputValidate::ReadYesOrNo())
		{
			Permissions += ClsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";

		if (ClsInputValidate::ReadYesOrNo())
		{
			Permissions += ClsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";

		if (ClsInputValidate::ReadYesOrNo())
		{
			Permissions += ClsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client? y/n? ";

		if (ClsInputValidate::ReadYesOrNo())
		{
			Permissions += ClsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";

		if (ClsInputValidate::ReadYesOrNo())
		{
			Permissions += ClsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";

		if (ClsInputValidate::ReadYesOrNo())
		{
			Permissions += ClsUser::enPermissions::pManageUsers;
		}

		return Permissions;

	}


public:

	static void ShowUpdateUserScreen()
	{
  	_DrawScreenHeader("\tUpdate User Screen");
  	
  	string UserName;
  	cout << "User Name Number That Want Upda7te It\n";
  	UserName = ClsInputValidate::ReadString();
  
  	while (!ClsUser::IsClientExist(UserName))
  	{
  		cout << "This User  Exist,Enter Another User Name\n";
  		UserName = ClsInputValidate::ReadString();
  	}
  
  	ClsUser User = ClsUser::Find(UserName);
  	
  	_PrintDataUser(User);
  	cout << "Are You Want To Update This User\n?";
  	
  	if (ClsInputValidate::ReadYesOrNo())
  	{
  		_ReadUserInfo(User);
  
  	}
  
  	ClsUser::EnSaveDataMode SaveMode;
  	SaveMode = User.Save();
  
  	switch (SaveMode)
  	{
  	case ClsUser::EnSaveDataMode::enSuccessfullySave:
  		cout << "\nUpdate User Successfully..\n";
  		_PrintDataUser(User);
  
  		break;
  	case ClsUser::EnSaveDataMode::enFailedEmptyObject:
  		cout << "faild Save, Because The User Data Is Empty!..\n";
  		break;
  
  	}
  
  
  }
};

