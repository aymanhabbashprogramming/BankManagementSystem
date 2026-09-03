#include <iostream>
#include <fstream>
#include "clsBankClient.h"

using namespace std;

int main()
{  
    cout << clsBankClient::IsClientExist("A101");

    return 0;
}