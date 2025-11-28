#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"ClsString.h"
#include"ClsDate.h"
#include"ClsPerson.h"
#include"ClsUtil.h"
using namespace std;

class ClsUser : public ClsPerson
{
private:
	enum EnModeUser
	{
		EnEmptyMode = 1,
		EnUpdateMode = 2,
		EnAddNewUserMode = 3
	};

	
	EnModeUser _Mode;
	string _UserName;
	string _Password;
	string _Time;
	int _Permissions = 0;
	bool _MarkforDelete = false;
	
	static ClsUser _ConvertLineToObject(string Line, string Seprator = "#//#")
	{
		vector<string>DataClient;
		DataClient = ClsString::Split(Line, Seprator);

		return ClsUser(EnModeUser::EnUpdateMode, DataClient[0],
			DataClient[1], (DataClient[2]), DataClient[3],
			DataClient[4], ClsUtil::DecryptText(DataClient[5],2), stoi(DataClient[6]));
	}
	
	static string _ConvertObjectToLine(ClsUser User, string Seperator = "#//#")
	{
		

		string UserRecord = "";
		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += ClsUtil::EncryptText(User.Password,2) + Seperator;
		UserRecord += to_string(User.Permissions);

		return UserRecord;

	}

	static vector<ClsUser>_LoadUsersDateFromFile()
	{
		vector<ClsUser>_User;

		fstream Myfile;
		Myfile.open("Users.txt", ios::in);
		string Line;
		if (Myfile.is_open())
		{
			while (getline(Myfile, Line))
			{
				ClsUser User = _ConvertLineToObject(Line);
				_User.push_back(User);
			}
			Myfile.close();
		}

		return _User;
	}

	static void _SaveDateUsersTofile(vector<ClsUser>Users)
	{
		fstream Myfile;
		Myfile.open("Users.txt", ios::out);

		if (Myfile.is_open())
		{
			string Line;
			for (ClsUser& U : Users)
			{
				if (U._MarkforDelete == false)

				{
					Line = _ConvertObjectToLine(U);
					Myfile << Line << endl;
				}
			}

			Myfile.close();
		}

	}

	void _AddDataLineToFile(string Line)
	{
		fstream Myfile;
		Myfile.open("Users.txt", ios::out | ios::app);
	
		if (Myfile.is_open())
		{
			Myfile << Line << endl;
		}

		Myfile.close();
	}

	void _Update()
	{
		vector <ClsUser>_VUsers;
		_VUsers = _LoadUsersDateFromFile();


		for (ClsUser& U : _VUsers)
		{
			if (U.GetUserName() == GetUserName())
			{
				U = *this;
			}
		}
		_SaveDateUsersTofile(_VUsers);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertObjectToLine(*this));
	}
	 string _PrepareLoginRecorde( string Seprator = "#//#")
	{
		string Line = ClsDate::GetSystemDateTimestring() + Seprator +
			UserName + Seprator + ClsUtil::EncryptText(Password)+Seprator + to_string(Permissions);

		return Line;
	}
	 
	public:
	bool MarkedForDeleted()
	{
		return _MarkforDelete;
	}

	string GetUserName()
	{
		return _UserName;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;
	void SetTime(string T)
	{
		_Time = T;
	}
	string GetTime()
	{
		return _Time;
	}
	__declspec(property(get = GetTime, put = SetTime)) string Time;

	ClsUser(EnModeUser Mode , string Firstname , string Lastname
		, string Email, string Phone, string Username
	,string Password, int Permissions):ClsPerson(Firstname , Lastname,Email,Phone)
	{
		_Mode = Mode ;
		_UserName = Username;
		_Password = Password;
		_Permissions = Permissions;
		_Time = Time;
	}

	static ClsUser _GetEmptyUserOpject()
	{
		return ClsUser(EnModeUser::EnEmptyMode, "", "", "", "", "", "", -1);
	}
	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, PLoginRegisterList = 128
	};

	bool ISEmpty()
	{
		return (_Mode == EnModeUser::EnEmptyMode);
	}
	
	static ClsUser Find(string UserName)
    {
        vector<ClsUser>Users;
        fstream MyFile;

        MyFile.open("Users.txt", ios::in);//read Mode
        if (MyFile.is_open())
        {
          string Line = "";
          while (getline(MyFile, Line))
          {
          ClsUser User = _ConvertLineToObject(Line);
          if (User.UserName == UserName)
          {
              MyFile.close();
              return User;
          }
          Users.push_back(User);
            }

        }
        
        MyFile.close();

        return _GetEmptyUserOpject();
    }

    static ClsUser Find(string UserName, string Pass)
    {
        vector<ClsUser>Users;
        fstream MyFile;

        MyFile.open("Users.txt", ios::in);//read Mode
        if (MyFile.is_open())
        {
            string Line = "";
            while (getline(MyFile, Line))
            {
              ClsUser User = _ConvertLineToObject(Line);
              if (User.UserName == UserName &&
                  User.Password == Pass)
              {
                  MyFile.close();
                  return User;
              }
			  Users.push_back(User);
			  
            }

        }
        MyFile.close();

        return _GetEmptyUserOpject();

    }

	enum EnSaveDataMode { enFailedEmptyObject = 0, enSuccessfullySave = 1, enFaildSaveExsistAcountNumber };

	static bool IsClientExist(string AccNumber)
	{
		ClsUser User = ClsUser::Find(AccNumber);
		return (!User.ISEmpty());
	}
	static ClsUser GetAddNewUserObject(string UserName)
	{
		return ClsUser(EnModeUser::EnAddNewUserMode, "", "", "", "", UserName, "", 0);
	}

	EnSaveDataMode Save()
	{
		switch (_Mode)
		{
		case EnModeUser::EnEmptyMode:
			
			if (ISEmpty())
			{
				return enFailedEmptyObject;

			}


		case EnModeUser::EnUpdateMode:
			_Update();
			return enSuccessfullySave;

		case EnModeUser::EnAddNewUserMode:

			if (ClsUser::IsClientExist(UserName))
			{
				return enFaildSaveExsistAcountNumber;
			}
			else
			{
				_AddNew();
				_Mode = EnModeUser::EnUpdateMode;
				return enSuccessfullySave;
			}
		}

	}

	bool Delete()
	{
		vector<ClsUser>_VUsers;
		_VUsers = _LoadUsersDateFromFile();

		for (ClsUser& U : _VUsers)
		{
			if (U.UserName == UserName)
			{
				U._MarkforDelete = true;
				break;
			}

		}

		_SaveDateUsersTofile(_VUsers);

		*this = _GetEmptyUserOpject();

		return true;
	}

	static vector<ClsUser> GetDataUsers()
	{
		return _LoadUsersDateFromFile();
	}

   bool CheckPermissions(enPermissions Permission)
	{
		
		if (this->Permissions == enPermissions ::eAll)
		{
			return true;
		}
		
		if ((Permission & this->Permissions) == Permission)
		{
			return true;
		}

		return false;
	}

    void RegisterLogin()
   {
	  string LineDateLocked = _PrepareLoginRecorde();
	  
	  fstream MyLockedfile;
	   MyLockedfile.open("FileLocked.txt", ios::out | ios::app);

	   if (MyLockedfile.is_open())
	   {
		   MyLockedfile << LineDateLocked << endl;
	   }
	   MyLockedfile.close();

   }
	struct StDataUser
	{
		string Time;
		string UserName;
		string Password;
		int Per;
	};
	
	static StDataUser PreparstringLoginUserData(string Line , string Sep = "#//#")
	{
		vector<string> DataUsers;

		DataUsers = ClsString::Split(Line,Sep);

		StDataUser DUser;

		DUser.Time = DataUsers[0];
		DUser.UserName = DataUsers[1];
		DUser.Password = DataUsers[2];
		DUser.Per = stoi(DataUsers[3]);

		return DUser;
	}

	static vector<StDataUser> LoadUsersLoginDateFromFile()
	{
		vector<StDataUser>UserData;

		fstream MyLockedfile;
		MyLockedfile.open("FileLocked.txt", ios::in);
		string Line;
		StDataUser User;

		if (MyLockedfile.is_open())
		{
			while (getline(MyLockedfile, Line))
			{
				User = PreparstringLoginUserData(Line);
				
				UserData.push_back(User);
			}
			MyLockedfile.close();
		}

		return UserData;
	}
};

