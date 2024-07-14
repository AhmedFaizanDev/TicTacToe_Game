#include <iostream>
using namespace std;

char board[3][3];

void drawBoard() 
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void initializeBoard() 
{
    board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
    board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
    board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';
}

bool insert_marker(int index, char token) 
{
    // Convert 1-based index to 0-based row and column
    int row = (index - 1) / 3;
    int col = (index - 1) % 3;

    // Check if the chosen cell is empty
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = token;
        return true; // Successfully inserted marker
    } else {
        return false; // Cell already occupied
    }
}

int winner() 
{
    // rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            cout<<board[i][0]<<" is winner";
            return;
        }
    }
    // columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            cout<<board[0][i]<<" is winner";
            return;
        }
    }
    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        cout<<board[0][0]<<" is winner";
        return;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        cout<<board[0][2]<<" is winner";
        return;
    }

    return 0;
}