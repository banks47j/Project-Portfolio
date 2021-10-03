/******************************************************************************
Caesar Cipher
Johnathan Banks (9/22/21)
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //declare variables
    int cipherType = 0;
    bool cipherType_bool = false;
    
    int codeOrDecode = 0;
    bool codeOrDecode_bool = false;
    
    int count = 0;
    int length;
    
    int shiftValue = 0;
    bool shift_bool = false;
    
    string userString;
    
    
    //Add welcome message and ask if using basic cipher or cipher+
    cout    << "Welcome the cipher generator delux!" << endl
            << "**Warning: If letters are entered when asked for numbers,"
            << " the program will abort**" << endl;
    while (cipherType_bool == false)
    {
        cout    << endl << "Enter 1 to use the basic cipher." << endl 
                << "-or-" << endl
                << "Enter 2 to use cipher+." << endl;
        
        cin     >> cipherType;
        cout    << endl;
    
        //added program abort if non-number was entered to prevent an endless loop.
        if (cipherType == isalpha(cipherType))
        return 0;
        
        if (cipherType == 1)
        {
            cipherType_bool = true;
        }
        if (cipherType == 2)
        {
            cipherType_bool = true;
        }
    }
    
    
    //user specify encode or decode
    while (codeOrDecode_bool == false)
    {
    cout << "Enter 1 to encode a message." << endl 
         << "-or-" << endl 
         << "Enter 2 to decode a message." << endl;
         
    cin >> codeOrDecode;
    cout << endl;
    
    //added program abort if non-number was entered to prevent an endless loop.
    if (codeOrDecode == isalpha(codeOrDecode))
    return 0;
    
    if (codeOrDecode == 1)
        {
            codeOrDecode_bool = true;
        }
    if (codeOrDecode == 2)
        {
            codeOrDecode_bool = true;
        }
    }
    
    //user specify number of characters to shift 
    while (shift_bool  == false)
    {
    cout << "Please specify the number of characters to shift for this cipher."
         << endl << "From: (1-25)"<< endl;
         
    cin >> shiftValue;
        if (shiftValue > 0 && shiftValue < 26)
        {
            shift_bool = true;
        }
        
        //added program abort if non-number was entered to prevent an endless loop.
        if (shiftValue == isalpha(shiftValue))
        return 0;
    }
    
    //user enter message to encode/decode
    if (codeOrDecode == 1)
    {
        cout << "Please enter the message you would like to encode." << endl;
        // Remove trailing whitespace left over from cin.
        // See Notes in https://en.cppreference.com/w/cpp/string/basic_string/getline
        // for more detail.
        cin >> std::ws;
        getline(cin, userString);
    }
    if (codeOrDecode == 2)
    {
        cout << "Please enter the message you would like to decode." << endl;
        // Remove trailing whitespace left over from cin.
        // See Notes in https://en.cppreference.com/w/cpp/string/basic_string/getline
        // for more detail.
        cin >> std::ws;
        getline(cin, userString);
    }

    //Change variable 'length' to length of userString.
    length = (int)userString.length();

    //use 1 for 1 substitution to replace each letter with 'n' letters to the left
    if (cipherType == 1)
    {
        if (codeOrDecode == 1)
        {
            for (count = 0; count < length; count++)
            {
                if (isalpha(userString[count]))
                {
                    userString[count] = tolower(userString[count]);
                    for (int i = 0; i < shiftValue; i++)
                    {
                        if (userString[count] == 'a')
                        {
                            userString[count] = 'z';
                        }
                        else
                        {
                            userString[count]--;
                        }
                    }
                }
            }
        }
    
    
    //decode by reversing process
        if (codeOrDecode == 2)
        {
            for (count = 0; count < length; count++)
            {
                if (isalpha(userString[count]))
                {
                    userString[count] = tolower(userString[count]);
                    for (int i = 0; i < shiftValue; i++)
                    {
                        if (userString[count] == 'z')
                        {
                            userString[count] = 'a';
                        }
                        else
                        {
                            userString[count]++;
                        }   
                    }
                }
            }
        }
    }
    
    
    //Code/Decode variation
    //intended variation is to adjust the shift value based on count value
    //  within the phrase (ie if shift is 1 & code is aaa: it would read zyx)
    if (cipherType == 2)
    {
        if (codeOrDecode == 1)
        {
            for (count = 0; count < length; count++)
            {
                if (isalpha(userString[count]))
                {
                    userString[count] = tolower(userString[count]);
                    for (int i = 0; i < (shiftValue + count); i++)
                    {
                        if (userString[count] == 'a')
                        {
                            userString[count] = 'z';
                        }
                        else
                        {
                            userString[count]--;
                        }
                    }
                }
            }
        }
    
    
    //decode by reversing process
        if (codeOrDecode == 2)
        {
            for (count = 0; count < length; count++)
            {
                if (isalpha(userString[count]))
                {
                    userString[count] = tolower(userString[count]);
                    for (int i = 0; i < (shiftValue + count); i++)
                    {
                        if (userString[count] == 'z')
                        {
                            userString[count] = 'a';
                        }
                        else
                        {
                            userString[count]++;
                        }   
                    }
                }
            }
        }
    }  
    
    //print encoded/decoded message
    cout << userString << endl;
}
