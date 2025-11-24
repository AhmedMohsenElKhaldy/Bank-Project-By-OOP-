#include <iostream>
#include"ClsMainScreen.h"
#include"ClsLoginScreen.h"
#include<fstream>
#include"ClsDate.h"
#include"Global.h"

using namespace std;

int main()
{


	while(true)
	{
		if (!ClsLoginScreen::ShowLoginScreen())
		{
			break;
		}
		
	}
	



	
	
	
	system("pause");
}
