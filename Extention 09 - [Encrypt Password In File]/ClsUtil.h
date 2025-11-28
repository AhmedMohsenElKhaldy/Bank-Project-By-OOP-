#pragma once  
#include<iostream>  
#include<string>  
#include<vector>
#include"ClsDate.h"
#include<ctime> // Include ctime for time() function  

using namespace std;

class ClsUtil
{
public:
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static  int GetRandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From; // Replace 'srand' with 'rand()'  
    }

    enum EnTypeOfChar { Smallchar = 1, CapitalChar = 2, Numberchar = 3, SpicialChar = 4, MixChar = 5 };

    static char GetRandomChar(EnTypeOfChar Type)
    {
        if (Type == EnTypeOfChar::MixChar)
            Type = EnTypeOfChar(GetRandomNumber(1, 3));

        switch (Type)
        {
        case EnTypeOfChar::CapitalChar:
            return char(GetRandomNumber(65, 90));
            break;

        case EnTypeOfChar::Smallchar:
            return char(GetRandomNumber(97, 122));
            break;

        case EnTypeOfChar::Numberchar:
            return char(GetRandomNumber(48, 57));
            break;

        case EnTypeOfChar::SpicialChar:
            return char(GetRandomNumber(33, 47));
            break;

        default:
            return char(GetRandomNumber(65, 122));
            break;
        }

    }

    static string GenerateWord(EnTypeOfChar Type, short Size)
    {
        string Word;
        for (int w = 0;w < Size; w++)
        {
            Word += GetRandomChar(Type);
        }

        return Word;
    }

    static string Generatekey(EnTypeOfChar Type)
    {
        string GenerateKey = "";

        string Deilimetar = "-";
        for (int t = 1; t <= 4; t++)
        {
            GenerateKey += GenerateWord(Type, 4) + Deilimetar;

        }
        // sdf1-fdf5-sdf5-a2s5;
        /*GenerateKey = GenerateWord(Type, 4) + "-"
            + GenerateWord(Type, 4) + "-"
            + GenerateWord(Type, 4) + "-"
            + GenerateWord(Type, 4);*/

        return GenerateKey.substr(0, GenerateKey.size() - 1);
    }

    static void GenerateKeys(EnTypeOfChar Type, int Size)
    {
        for (int k = 1; k < Size;k++)
        {
            cout << "Key " << "[" << k << "] : " <<
                Generatekey(Type) << endl;
        }
    }

    static void Swap(int& Num1, int& Num2)
    {
        int Temp;
        Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(double& Num1, double& Num2)
    {
        double Temp;
        Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(string& S1, string& S2)
    {
        string Temp;
        Temp = S1;
        S1 = S2;
        S2 = Temp;
    }

    static void Swap(ClsDate& Date1, ClsDate& Date2)
    {
        ClsDate DateTemp;
        DateTemp = Date1;
        Date1 = Date2;
        Date2 = DateTemp;
    }

    static void shuffleArray(int Arr[], int size)
    {
        for (int i = 0;i < size - 1; i++)
        {
            Swap(Arr[i], Arr[i + 1]);

        }
    }

    static void shuffleArray(string Arr[], int size)
    {
        for (int i = 0;i < size - 1; i++)
        {
            Swap(Arr[GetRandomNumber(1, size) - 1],
                Arr[GetRandomNumber(1, size) - 1]);

        }
    }

    static void FillArrayWihtRandomNumber(int Arr[], int size, int From, int To)
    {
        for (int t = 0; t < size;t++)
        {
            Arr[t] = GetRandomNumber(From, To);
        }
    }

    static void FillArrayWihtRandomWord(string Arr[], int sizeArr, EnTypeOfChar Type, int SizeWord)
    {
        for (int t = 0; t < sizeArr;t++)
        {
            Arr[t] = GenerateWord(Type, SizeWord);
        }
    }

    static void FillArrayWihtRandomKeys(string Arr[], int sizeArr, EnTypeOfChar Type)
    {
        for (int t = 0; t < sizeArr;t++)
        {
            Arr[t] = Generatekey(Type);
        }
    }

    static string Tabs(int Size)
    {
        string val = "";
        for (int t = 0;t < Size;t++)
        {
            val += "\t";
        }
        return val;
    }

    static string  EncryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short DecryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - DecryptionKey);

        }
        return Text;

    }

};

