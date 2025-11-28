#pragma once
#include<iostream>
#include<fstream>
#include"ClsUser.h"
#include"ClsDate.h"
#include"Global.h"
#include<ctime>


using namespace std;

class ClsAddDateToLockFile
{
	private:
	static string _ConverDataToLinestring(ClsUser U ,string Seprator = "#//#")
	{
		time_t t = time(0);   // get time now
		tm* now = localtime(&t); 
		
		string Time = to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":"
			+ to_string(now->tm_sec);

		string Line = ClsDate::DateToString(ClsDate()) + "-" + Time + Seprator +
		U.UserName + Seprator + U.Password + Seprator + to_string(U.Permissions);
		
		return Line;
	}
public:

	static void AddDateLoginToFile()
	{
		fstream MyLockedfile;
		MyLockedfile.open("FileLocked.txt", ios::out | ios::app);
    
	if (MyLockedfile.is_open())
	{
			string LineDateLocked = _ConverDataToLinestring(CurrentUser);
			MyLockedfile << LineDateLocked << endl;
	}
	
	}


};

