#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

char* getRandomWord()
{
    ifstream file("words.txt");
    char temp[50];
    int totalWords = 0;

    while (file >> temp)
    {
        totalWords++;
    }

    if (totalWords == 0)
    {
        cout << "No words found in file!" << endl;
        return nullptr;
    }

    file.close();

    srand(time(0));
    int randomIndex = rand() % totalWords + 1;

    ifstream file2("words.txt");
    int currentWord = 0;

    while (file2 >> temp)
    {
        currentWord++;
        if (currentWord == randomIndex)
        {
            int length = 0;
            while (temp[length] != '\0')
            {
                length++;
            }

            char* word = new char[length + 1];
            for (int i = 0; i < length; i++)
            {
                word[i] = temp[i];
            }
            word[length] = '\0';

            file2.close();
            return word;
        }
    }

    file2.close();
    return nullptr;
}

int getWordLength(char* word)
{
    int len = 0;
    while (word[len] != '\0')
    {
        len++;
    }
    return len;
}

void showWord(char* display, int length)
{
    cout << endl << "Word: ";
    for (int i = 0; i < length; i++)
    {
        cout << display[i] << " ";
    }
    cout << endl;
}

bool allLettersGuessed(char* display, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (display[i] == '_')
        {
            return false;
        }
    }
    return true;
}

bool updateWord(char* word, char* display, char guess)
{
    bool found = false;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == guess)
        {
            display[i] = guess;
            found = true;
        }
    }
    return found;
}

int main()
{
    char* word = getRandomWord();

    if (word == nullptr)
    {
        return 0;
    }

    int length = getWordLength(word);
    char* display = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        display[i] = '_';
    }
    display[length] = '\0';

    int mistakesLeft = 7;
    bool win = false;

    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "        HANGMAN GAME         " << endl;
    cout << "-----------------------------" << endl;

    while (true)
    {
        showWord(display, length);
        cout << "Remaining mistakes = " << mistakesLeft << endl;

        char guess;
        cout << "Enter a letter = ";
        cin >> guess;

        bool found = updateWord(word, display, guess);

        if (found)
        {
            cout << "Good guess!" << endl;
        }
        else
        {
            mistakesLeft--;
            cout << "Wrong guess!" << endl;
            cout << "Mistakes left = " << mistakesLeft << endl;
        }

        if (allLettersGuessed(display, length))
        {
            win = true;
            break;
        }
        else if (mistakesLeft == 0)
        {
            break;
        }
    }

    cout << endl;

    if (win)
    {
        cout << " You guessed the word correctly = " << word << endl;
    }
    else
    {
        cout << " lost! The correct word was = " << word << endl;
    }
             
    cout << "-----------------------------" << endl;
    cout << "         GAME OVER           " << endl;
    cout << "-----------------------------" << endl;

    delete[] word;
    delete[] display;

}

