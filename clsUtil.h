#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{
public:
    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        //updated this method to accept mixchars
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {

        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

};