#include <array>
#include <iostream>
#include <limits>

using namespace std;

const array<array<int, 3>, 8> winningLines = {{
    {{0, 1, 2}}, {{3, 4, 5}}, {{6, 7, 8}}, // Rows
    {{0, 3, 6}}, {{1, 4, 7}}, {{2, 5, 8}}, // Columns
    {{0, 4, 8}}, {{2, 4, 6}}              // Diagonals
}};

void showBoard(const array<char, 9>& board)
{
    cout << '\n';
    for (int row = 0; row < 3; ++row)
    {
        for (int column = 0; column < 3; ++column)
        {
            const int index = row * 3 + column;
            cout << ' ' << board[index] << ' ';
            if (column < 2)
            {
                cout << '|';
            }
        }
        cout << '\n';
        if (row < 2)
        {
            cout << "---|---|---\n";
        }
    }
    cout << '\n';
}

bool checkWin(const array<char, 9>& board, char player)
{
    for (const auto& line : winningLines)
    {
        if (board[line[0]] == player &&
            board[line[1]] == player &&
            board[line[2]] == player)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    array<char, 9> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player = 'X';
    int moves = 0;

    while (moves < 9)
    {
        showBoard(board);
        cout << player << " enter your position (1-9): ";

        int position;
        if (!(cin >> position))
        {
            cout << "Please enter a number from 1 to 9.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (position < 1 || position > 9)
        {
            cout << "Enter a number from 1 to 9!\n";
            continue;
        }

        const int index = position - 1;
        if (board[index] == 'X' || board[index] == 'O')
        {
            cout << "That position is already occupied!\n";
            continue;
        }

        board[index] = player;
        ++moves;

        if (checkWin(board, player))
        {
            showBoard(board);
            cout << player << " wins!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    showBoard(board);
    cout << "It's a draw!\n";
    return 0;
}
