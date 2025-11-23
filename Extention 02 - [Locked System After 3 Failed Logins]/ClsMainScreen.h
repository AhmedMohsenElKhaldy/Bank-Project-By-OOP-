#pragma once
#include<iostream>
#include<iomanip>
#include"ClsInputValidate.h"
#include"ClsScreen.h"
#include"ClsClientListScreen.h"
#include"ClsAddNewClientScreen.h"
#include"CLsDeleteClinetScreen.h"
#include"ClsUpdateClientScreen.h"
#include"ClsFindclientScreen.h"
#include"ClsTransactionScreen.h"
#include"ClsManageUsersScreen.h"
#include"Global.h"

using namespace std;

class ClsMainScreen : protected ClsScreen
{
private:
	enum _EnMainMenueScreenOption {
      eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
      eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
      eManageUsers = 7, eExit = 8
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << "Choose What Do You Want To Do From 1 To 8\n";
       
        short Choose = ClsInputValidate::ReadShortNumberBetween
        (1, 8, "Invalid Number Please Enter Bettwen 1 And 8");
        
        return Choose;
    }
   
    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenueScreen();
    }
    
    static void _ShowAllClientsScreen()
    {
        //cout << "\nClient List Screen Will be here...\n";
        
        ClsClientListScreen::ShowClientList();


   }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";
        ClsAddNewClientScreen::AddNewClient();
    }

    static void _ShowDeleteClientScreen()
    {
       
        //cout << "\nDelete Client Screen Will be here...\n";
        CLsDeleteClinetScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        ClsUpdateClientScreen::UpDateClient();
    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        ClsFindclientScreen::FindCLientScreen();
        
    }

    static void _ShowTransactionsMenue()
    {
        //cout << "\nTransactions Menue Will be here...\n";
        ClsTransactionScreen::ShowTransaction();
    }

    static void _ShowManageUsersMenue()
    {

        ClsManageUsersScreen::ShowManageUsersMenue();
      
        //cout << "\nUsers Menue Will be here...\n";

    }

    /*static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }*/

    static void _Login()
    {
         CurrentUser = ClsUser::Find("","");
         
         //ClsLoginScreen::ShowLoginScreen(); Circel Reference Error
    }
    static void _PerformMainManueOption(_EnMainMenueScreenOption Option)
    {
        switch (Option)
        {
        case _EnMainMenueScreenOption::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;

        case _EnMainMenueScreenOption::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case _EnMainMenueScreenOption::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case _EnMainMenueScreenOption::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        case _EnMainMenueScreenOption::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        case _EnMainMenueScreenOption::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        case _EnMainMenueScreenOption::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case _EnMainMenueScreenOption::eExit:
            system("cls");
            _Login();
            break;
        }
    }

public:
	static void ShowMainMenueScreen()
	{
		system("cls");
		
        _DrawScreenHeader("\tMain Menue");
      
        cout << setw(37) << left << "" << " ===========================================\n";
        cout << setw(37) << left << "" << " \t\t\tMain Menue\n";
        cout << setw(37) << left << "" << " ===========================================\n";
        cout << setw(37) << left << "" << " \t[1] Show Client List.\n";
        cout << setw(37) << left << "" << " \t[2] Add New Client.\n";
        cout << setw(37) << left << "" << " \t[3] Delete Client.\n";
        cout << setw(37) << left << "" << " \t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << " \t[5] Find Client.\n";
        cout << setw(37) << left << "" << " \t[6] Transactions.\n";
        cout << setw(37) << left << "" << " \t[7] Manage Users.\n";
        cout << setw(37) << left << "" << " \t[8] Logout.\n";
        cout << setw(37) << left << "" << " ===========================================\n";

        _PerformMainManueOption((_EnMainMenueScreenOption)_ReadMainMenueOption());
	}
};

