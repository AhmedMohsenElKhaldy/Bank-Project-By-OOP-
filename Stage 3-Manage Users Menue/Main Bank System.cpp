#include <iostream>
#include"ClsMainScreen.h"
#include<fstream>
using namespace std;







int main()
{
	/*fstream Myfile;
	Myfile.open("Users.txt", ios::out);
	string Line;
	if (Myfile.is_open())
	{
		Myfile << Line << endl;
	}*/

	ClsMainScreen::ShowMainMenueScreen();

   system("pause");
}
