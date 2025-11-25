#pragma once
#include"ClsUser.h"
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include<iomanip>

class ClsAddNewUserScreen : protected ClsScreen
{
private:
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

       cout << "\n Register List Screen";
       
       if (ClsInputValidate::ReadYesOrNo())
       {
         Permissions += ClsUser::enPermissions::PLoginRegisterList;
       }

        return Permissions;

    }
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
		cout << "\Perimissions : " << U.Permissions;
		cout << "\n___________________\n";

	}

public:
    static void ShowAddUserScreen()
    {
        _DrawScreenHeader("\t Add User Screen");

        string UserName;
        cout << "User Name Number That Want Adding It\n";
        UserName = ClsInputValidate::ReadString();

        while (ClsUser::IsClientExist(UserName))
        {
            cout << "This User  Exist,Enter Another User Name\n";
            UserName = ClsInputValidate::ReadString();
        }
        
        ClsUser User = ClsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(User);

        ClsUser::EnSaveDataMode SaveMode;

        SaveMode = User.Save();
        
        switch (SaveMode)
        {
        case ClsUser::EnSaveDataMode::enSuccessfullySave:
            cout << "User Adding Successfully:-)\n";
            _PrintDataUser(User);
            break;
        case ClsUser::EnSaveDataMode::enFaildSaveExsistAcountNumber:
            cout << "Faild Save The User Is Exsist..\n";
            break;

        case ClsUser::EnSaveDataMode::enFailedEmptyObject:
            cout << "Faild Save User Because The Opject Is Empty\n";
            break;
        }
    }


};

	
