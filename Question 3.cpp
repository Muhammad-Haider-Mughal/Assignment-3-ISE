#include <iostream>
using namespace std;

bool checkWinner(char grid[3][3], char current)
{
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == current && grid[i][1] == current && grid[i][2] == current)
        {
            return true;
        }

        if (grid[0][i] == current && grid[1][i] == current && grid[2][i] == current)
        {
            return true;
        }
    }

    if (grid[0][0] == current && grid[1][1] == current && grid[2][2] == current)
    {
        return true;
    }

    if (grid[0][2] == current && grid[1][1] == current && grid[2][0] == current)
    {
        return true;
    }

    return false;
}

void takeInput(char grid[3][3], char current)
{
    int r, c;
    while (true)
    {
        cout << endl << "Player " << current << ", enter row (1-3) and column (1-3) = ";
        cin >> r >> c;

        if (r < 1 || r > 3 || c < 1 || c > 3)
        {
            cout << "Invalid position! Try again." << endl;
        }
        else if (grid[r - 1][c - 1] != ' ')
        {
            cout << "Already filled." << endl;
        }
        else
        {
            grid[r - 1][c - 1] = current;
            break;
        }
    }
}

int main()
{
    int choice;

    while (true)
    {
        cout << "Enter 1 to play or 0 to exit = ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Program terminated." << endl;
            break;
        }
        else if (choice != 1)
        {
            cout << "Please enter 1 or 0." << endl;
            continue;
        }
        else
        {
            char grid[3][3];

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    grid[i][j] = ' ';
                }
            }

            char current = 'O';
            int moves = 0;
            bool win = false;

            while (true)
            {
                cout << endl << "Current Board = " << endl;

                for (int i = 0; i < 3; i++)
                {
                    cout << " ";
                    for (int j = 0; j < 3; j++)
                    {
                        cout << grid[i][j];
                        if (j < 2)
                        {
                            cout << " | ";
                        }
                    }
                    cout << endl;

                    if (i < 2)
                    {
                        cout << "---+---+---" << endl;
                    }
                }

                takeInput(grid, current);
                moves++;

                if (checkWinner(grid, current))
                {
                    cout << "Player " << current << " wins!" << endl;
                    win = true;
                    break;
                }
                else if (moves == 9)
                {
                    cout << "It's a draw." << endl;
                    break;
                }
                else
                {
                    if (current == 'O')
                    {
                        current = 'X';
                    }
                    else
                    {
                        current = 'O';
                    }
                }
            }
        }
    }

}
