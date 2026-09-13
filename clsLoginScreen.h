#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{
private:
	static bool _Login() 
	{
		short FailedLoginCount = 0;
		bool LoginFaild = false;

		string Username, Password;

		do
		{
			if (LoginFaild)
			{
				if (FailedLoginCount == 2)
				{
					cout << "\n\033[31mSystem locked due to multiple failed login attempts. Please try again later.\033[0m\n\n";
					return false;
				}

				short RemainingAttempts = 2 - FailedLoginCount;
				FailedLoginCount++;

				cout << "\nInvalid Username/Password, You have " 
					<< RemainingAttempts << (RemainingAttempts == 1 ? " attempt" : " attempts")
					<< " remaining.\n\n";
			}

			
			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}

};