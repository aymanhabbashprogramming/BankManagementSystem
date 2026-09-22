#include <iostream>
#include "clsLoginScreen.h"

int main()

{
   /* while (true)
    {

        if (clsLoginScreen::ShowLoginScreen() == false)
        {
            break;
        }
    }*/


    fstream MyFile;
    MyFile.open("Currencies.txt", ios::out | ios::app);
    MyFile.close();
    return 0;
}