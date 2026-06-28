#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void initializeBoard()
{
    char position = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = position++;
        }
    }
}

void displayBoard()
{
    cout << "\n";
    cout << "-------------\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "| ";

        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }

        cout << "\n-------------\n";
    }
}

bool makeMove(int choice)
{
    if (choice < 1 || choice > 9)
        return false;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = currentPlayer;
    return true;
}

bool checkWinner()
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkTie()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

void switchPlayer()
{
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main()
{
    char playAgain;

    do
    {
        initializeBoard();
        currentPlayer = 'X';

        bool gameOver = false;

        cout << "\n=====================================\n";
        cout << "        TIC-TAC-TOE GAME\n";
        cout << "=====================================\n";
        cout << "Player 1 : X\n";
        cout << "Player 2 : O\n";
        cout << "Choose Position (1-9)\n";

        while (!gameOver)
        {
            displayBoard();

            int choice;

            cout << "\nPlayer " << currentPlayer
                 << " Turn\n";
            cout << "Enter Position : ";
            cin >> choice;

            if (!makeMove(choice))
            {
                cout << "\nInvalid Move! Try Again.\n";
                continue;
            }

            if (checkWinner())
            {
                displayBoard();
                cout << "\n********************************\n";
                cout << "Player " << currentPlayer
                     << " Wins!\n";
                cout << "********************************\n";
                gameOver = true;
            }
            else if (checkTie())
            {
                displayBoard();
                cout << "\n*******************************\n";
                cout << "Game Tied!\n";
                cout << "*******************************\n";
                gameOver = true;
            }
            else
            {
                switchPlayer();
            }
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank You for Playing!\n";

    return 0;
}