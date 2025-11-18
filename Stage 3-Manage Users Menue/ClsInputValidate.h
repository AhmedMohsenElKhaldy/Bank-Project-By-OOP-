#pragma once
#include<iostream>
#include"ClsDate.h"
using namespace std;

class ClsInputValidate
{
public:
	static bool IsNumberIntBettwen(int Search, int From, int To)
	{
		return (Search >= From && Search <= To);

		// 1 --> 10  //	1 > 5 && 10 > 5 
	}
	static bool IsNumberShortBettwen(short Search, short From, short To)
	{
		return (From <= Search && To >= Search);

		// 1 --> 10  //	1 > 5 && 10 > 5 
	}
	static bool IsNumberDblBettwen(double Search, double From, double To)
	{
		return (From <= Search && To >= Search);

		// 1.5 --> 10.5  //	1.5 > 5.5 && 10.5 > 5.5 
	}
	static bool IsNumberFloatlBettwen(float Search, float From, float To)
	{
		return (From <= Search && To >= Search);

		// 1.5 --> 10.5  //	1.5 > 5.5 && 10.5 > 5.5 
	}
	static bool IsDateBettwen(ClsDate DateSearch, ClsDate DateFrom, ClsDate DateTo)
	{
		if (

			(ClsDate::IsDate1AfterDate2(DateSearch, DateFrom) ||
				ClsDate::IsDate1DEQualDate2(DateSearch, DateFrom))
			&&
			(ClsDate::IsDate1BeforeDate2(DateSearch, DateTo) ||
				!ClsDate::IsDate1DEQualDate2(DateSearch, DateTo))

			)return true;

		//                       From-> 1/10/2025 --> 29/10/2025 --> To-> 31/12/2025
		if (

			(ClsDate::IsDate1AfterDate2(DateSearch, DateTo) ||
				ClsDate::IsDate1DEQualDate2(DateSearch, DateTo))
			&&
			(ClsDate::IsDate1BeforeDate2(DateSearch, DateFrom) ||
				!ClsDate::IsDate1DEQualDate2(DateSearch, DateTo))

			)return true;
		return false;
	}

	static int ReadIntNumber(string MessageError = "Invalid Number Enter Again\n")
	{
		int Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << MessageError;
		}
		return Number;

	}
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberIntBettwen(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}
	static int ReadShortNumber(string MessageError = "Invalid Number Enter Again\n")
	{
		short Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << MessageError;
		}
		return Number;

	}
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberIntBettwen(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}
	static double ReadDouNumber(string MessageError = "Invalid Number Enter Again\n")
	{
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << MessageError;
		}
		return Number;

	}
	static double ReadDouNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDouNumber();

		while (!IsNumberDblBettwen(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDouNumber();
		}
		return Number;
	}
	static string ReadString()
	{
		string S1;
		getline(cin >> ws, S1);

		return S1;
	}
	
	static float ReadFloNumber(string MessageError = "Invalid Number Enter Again\n")
	{
		float Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << MessageError;
		}
		return Number;

	}
	
	static float ReadFloNumberBetween(float From, float To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadFloNumber();

		while (!IsNumberFloatlBettwen(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDouNumber();
		}
		return Number;
	}
	static bool ValidateDate(ClsDate DateValidate)
	{
		return ClsDate::InValedDate(DateValidate);
	}
	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

	static bool ReadYesOrNo(string ErorrMessge = "Invalid Value, Enter [Yes , No]\n")
	{
		char Answer;
		cin >> Answer;

		while (toupper(Answer) != 'Y' && toupper(Answer) != 'N')
		{
			cout << Answer << endl;
			cin >> Answer;
		}

		return toupper(Answer) == 'Y' ? true : false;
	}
};
