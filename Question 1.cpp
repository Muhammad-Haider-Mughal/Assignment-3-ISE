#include <iostream>
#include <conio.h>
using namespace std;
 
//_getch() reads one character immediately without pressing Enter
bool takeInput(string& str)
{
    cout << "Enter string to check (Esc for exit) =  ";
    char ch = _getch();

    if (ch == 27)
    {
        return false;
    }

    cin >> str;
    return true;
}

int getLength(string str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

bool isPalindrome(string str)
{
    int len = getLength(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    while (true)
    {
        string str;
        if (!takeInput(str))
        {
            cout << endl << "Exiting program" << endl;
            break;
        }

        if (isPalindrome(str))
        {
            cout << "Palindrome" << endl;
        }
        else
        {
            cout << "Not Palindrome" << endl;
        }
    }

    return 0;
}

