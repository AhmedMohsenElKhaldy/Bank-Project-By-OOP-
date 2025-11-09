#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"ClsString.h"
#include"ClsDate.h"
#include"ClsPerson.h"
class ClsBankClient : public ClsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewClientMode = 2};

    enMode _Mode;
	
    string _AccountNumber;
	string _PinCode;
	float  _AccountBalance;
    bool DeleteMark = false;

  static ClsBankClient _ConvertLineToObject(string Line , string Seprator = "/##/")
    {
        vector<string>DataClient;
        DataClient = ClsString::Split(Line, "#//#");

      return ClsBankClient(enMode::UpdateMode,DataClient[0],
      DataClient[1], DataClient[2], DataClient[3],
          DataClient[4], DataClient[5], stof(DataClient[6]));
    }
 
  static string _ConvertObjectToLine(ClsBankClient Client , string Separator = "#//#")
   {
      string Line;

      Line = Client.FirstName +Separator +
             Client.LastName + Separator+
             Client.Email + Separator +
             Client.Phone + Separator +
             Client.AccountNumber() + Separator +
             Client.PinCode + Separator +
             to_string(Client.AccountBalance);

      return Line;
   }

  static vector<ClsBankClient>_LoadClientsDateFromFile()
   {
       vector<ClsBankClient>_Clients;

       fstream Myfile;
       Myfile.open("Clients.txt", ios::in);
       string Line;
       if (Myfile.is_open())
       {
           while (getline(Myfile, Line))
           {
               ClsBankClient Client = _ConvertLineToObject(Line);
               _Clients.push_back(Client);
           }
           Myfile.close();
       }
   
       return _Clients;
   }
   
  static void _SaveDateClientsTofile(vector<ClsBankClient>Clients)
  {
      fstream Myfile;
      Myfile.open("Clients.txt", ios::out);
      
      if (Myfile.is_open())
      {
          string Line;
          for (ClsBankClient& C : Clients)
          {
              if(C.DeleteMark == false)

              {
                  Line = _ConvertObjectToLine(C);
                  Myfile << Line << endl;
              }
          }
        
          Myfile.close();
      }
      
  }
 
  void _Update()
   {
       vector <ClsBankClient>_Vclients;
       _Vclients = _LoadClientsDateFromFile();


       for (ClsBankClient& C : _Vclients)
       {
           if (C.AccountNumber() == AccountNumber())
           {
               C = *this;
           }
       }
       _SaveDateClientsTofile(_Vclients);
   }
 
  void _AddNew()
  {
      _AddDataLineToFile(_ConvertObjectToLine(*this));
  }
 
  void _AddDataLineToFile(string StDataLine)
  {
      fstream Myfile;
      Myfile.open("Clients.txt", ios::out | ios::app);
     
      if (Myfile.is_open())
      {
          Myfile << StDataLine << endl;
      }
      Myfile.close();
  }

public:
    ClsBankClient(enMode Mode, string FirstName, string LastName,
    string Email ,string Phone ,string AccountNumber , string PinCode,
    float AccountBalance)
	:ClsPerson(FirstName, LastName, Email, Phone)

    
    {
		_Mode = Mode;
		_PinCode = PinCode;
		_AccountNumber = AccountNumber;
        _AccountBalance = AccountBalance;
	}
	
    
    string AccountNumber()
    {
        return _AccountNumber;
    }

        
    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }
    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    
    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }
    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    
  /*  void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }*/

  static ClsBankClient _GetEmptyClientOpject()
   {
       return ClsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
   }
  
  bool ISEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
  
  static ClsBankClient Find(string AccNumber)
    {
        vector<ClsBankClient>Clients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode
        if (MyFile.is_open())
        {
            string Line = "";
            while (getline(MyFile, Line))
            {
            ClsBankClient Client = _ConvertLineToObject(Line);
            if (Client.AccountNumber() == AccNumber)
            {
                MyFile.close();
                return Client;
            }
            Clients.push_back(Client);
            }

        }
        
        MyFile.close();

        return _GetEmptyClientOpject();
    }

  static ClsBankClient Find(string AccNumber , string Pass)
    {
        vector<ClsBankClient>Clients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode
        if (MyFile.is_open())
        {
            string Line = "";
            while (getline(MyFile, Line))
            {
                ClsBankClient Client = _ConvertLineToObject(Line);
                if (Client.AccountNumber() == AccNumber&&
                    Client.PinCode == Pass)
                {
                    MyFile.close();
                    return Client;
                }
                Clients.push_back(Client);
            }

        }
        MyFile.close();
        return _GetEmptyClientOpject();

    }
   
  enum EnSaveDataMode { enFailedEmptyObject = 0, enSuccessfullySave = 1, enFaildSaveExsistAcountNumber};
   
  static bool IsClientExist(string AccNumber)
    {
        ClsBankClient Client = ClsBankClient::Find(AccNumber);
        return (!Client.ISEmpty());
    }
  
  EnSaveDataMode Save()
{
        switch (_Mode)
        {
        case enMode::EmptyMode:
            if (ISEmpty())
            {
                return enFailedEmptyObject;

            }
       
        
        case enMode::UpdateMode:
            _Update();
            return enSuccessfullySave;

        case enMode::AddNewClientMode:
            if (ClsBankClient::IsClientExist(_AccountNumber))
            {
                return enFaildSaveExsistAcountNumber;
            }
            else  
            {
                _AddNew();
                return enSuccessfullySave;
            }
        }
        
}
  
  bool Delete()
    {
        vector<ClsBankClient>_VClient;
        _VClient = _LoadClientsDateFromFile();

        for (ClsBankClient& C: _VClient)
        {
        if (C.AccountNumber() == _AccountNumber)
      {
        C.DeleteMark = true;
        break;
      }
    
        }
        
        _SaveDateClientsTofile(_VClient);
       
        *this = _GetEmptyClientOpject();

return true;
    }
 
  static vector<ClsBankClient> GetDataClient()
    {
        return _LoadClientsDateFromFile();
    }
 
  static double GetTotalBalancese(vector<ClsBankClient>B)
   {
       double TotoalBalances = 0.0;

       for (ClsBankClient& C : B)
       {
           TotoalBalances += C.AccountBalance;
       }
       return TotoalBalances;
   }
 
  static  ClsBankClient	GetAddNewClientObject(string AccNumber)
    {
        return ClsBankClient(enMode::AddNewClientMode
            , "", "", "", "", AccNumber, "",0);
    }
};

