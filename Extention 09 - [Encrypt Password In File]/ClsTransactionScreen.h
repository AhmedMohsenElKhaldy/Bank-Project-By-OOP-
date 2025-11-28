#pragma once
#include"CLsScreen.h"
#include <iostream>
#include"ClsInputValidate.h"
#include"ClsBankClient.h"
#include<iomanip>
#include"ClsMainScreen.h"
#include"ClsDepositScreen.h"
#include"ClsWithdrawScreen.h"
#include"ClsClientBalancesScreen.h"
#include"ClsTransferScreen.h"
#include"ClsTransferLogScreen.h"

using namespace std;

class ClsTransactionScreen : protected ClsScreen
{
private:
    enum _EnTransactionOption {
        enDeposit = 1, enWithdraw = 2,
        enTotlaBalances = 3,enTransfarMenue = 4, enTransferLog = 5, enMainMenue = 6
        
    };
    static short _ReadTransactionOption()
    {
        cout << setw(37) << "Choose What Do You Want To Do From 1 To 4\n";

        short Choose = ClsInputValidate::ReadShortNumberBetween
        (1, 6, "Invalid Number Please Enter Bettwen 1 And 4");
        return Choose;
    }
    static void _ShowDepositScreen()
    {
        ClsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithdrawScreen()
    {
        //cout << "Withdraw, I'm Here\n";

        ClsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTotalBalancesScreen()
    {
        //cout << "Total Balances, I'm Here\n";

        ClsClientBalancesScreen::showTotalBalanceToClients();
    }
    static void _ShowMainMenueScreen()
    {
        cout << "Main Menue, I'm Here\n";
    }

    static void _ShowTransferScreen()
    {
        ClsTransferScreen::ShowWithdrawScreen();
        //cout << "Hi, Im Here\n";
    }
    static void _ShowTransferLogScreen()
    {
        ClsTransferLogScreen::ShowListLoginUsersScreen();
    }
    static void _BackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowTransaction();
    }
 
    static void PerformTransactionMenueScreen(_EnTransactionOption Optriontransaction)
    {
        switch (Optriontransaction )
        {
        case _EnTransactionOption::enDeposit:
            
            system("cls");
            _ShowDepositScreen();
            _BackToMainMenue();
            break;

        case _EnTransactionOption::enWithdraw:

            system("cls");
            _ShowWithdrawScreen();
            _BackToMainMenue();
            break;
        
        case _EnTransactionOption::enTotlaBalances:

            system("cls");
            _ShowTotalBalancesScreen();
            _BackToMainMenue();
            break;
        
        case _EnTransactionOption::enTransfarMenue:
            system("cls");
            _ShowTransferScreen();
            _BackToMainMenue();
            break;
   
        case _EnTransactionOption::enTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _BackToMainMenue();
            break;

        case _EnTransactionOption::enMainMenue:
            _BackToMainMenue();
           //Do Anythig In Here.. 
            break;
        }
    }

public:

    static void ShowTransaction()
{
    if (!CheckPermissionRight(ClsUser::enPermissions::pTranactions))
    {
       return;
    }
    system("cls");
	_DrawScreenHeader("Transaction Screen");
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] Deposit.\n";
    cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
    cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
    cout << setw(37) << left << "" << "\t[4] Trnasfer.\n";
    cout << setw(37) << left << "" << "\t[5] Trnasfer Log.\n";
    cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
    cout << setw(37) << left << "" << "===========================================\n";
    
    PerformTransactionMenueScreen((_EnTransactionOption)_ReadTransactionOption());
}
};

