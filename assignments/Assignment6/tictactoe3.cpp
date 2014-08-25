#include <iostream>
using namespace std;

char board[10] = {'o','1','2','3','4','5','6','7','8','9'};

int isWon();
void drawBoard();
char getMark(int p);
int getCurrentPlayer(int player);
int main()
{
    int currentPlayer = 1;
    int won = -1;
    int input;
    char mark;
    while (won == -1) {
        drawBoard();

        cout << "Enter a number Player " << currentPlayer<< ":";
        cin >> input;
        mark = getMark(currentPlayer);
        if (input == 1 && board[1] == '1')
            board[1] = mark;
        else if (input == 2 && board[2] == '2')
            board[2] = mark;
        else if (input == 3 && board[3] == '3')
            board[3] = mark;
        else if (input == 4 && board[4] == '4')
            board[4] = mark;
        else if (input == 5 && board[5] == '5')
            board[5] = mark;
        else if (input == 6 && board[6] == '6')
            board[6] = mark;
        else if (input == 7 && board[7] == '7')
            board[7] = mark;
        else if (input == 8 && board[8] == '8')
            board[8] = mark;
        else if (input == 9 && board[9] == '9')
            board[9] = mark;
        else {
            cout<<"Incorrect move! Try again : ";
            currentPlayer = getCurrentPlayer(currentPlayer);

            currentPlayer--;
            cin.ignore();
            cin.get();
        }
        won=isWon();
        currentPlayer = getCurrentPlayer(currentPlayer);
    }
    drawBoard();
    if(won==1) {
        cout<<"Player "<<currentPlayer<<" wins!";
    }
    else {
        cout<<"It's a tie!";
    }
    cin.ignore();
    cin.get();
    return 0;
}

int isWon()
{
    if (board[1] == board[2] && board[2] == board[3]) {
        return 1;
    }
    else if (board[4] == board[5] && board[5] == board[6]) {
        return 1;
    }
    else if (board[7] == board[8] && board[8] == board[9]) {
        return 1;
    }
    else if (board[1] == board[4] && board[4] == board[7]) {
        return 1;
    }
    else if (board[2] == board[5] && board[5] == board[8]) {
        return 1;
    }
    else if (board[3] == board[6] && board[6] == board[9]) {
        return 1;
    }
    else if (board[1] == board[5] && board[5] == board[9]) {
        return 1;
    }
    else if (board[3] == board[5] && board[5] == board[7]) {
        return 1;
    }
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9') {
        return 0;
    }
    else {
        return -1;
    }
}


void drawBoard()
{
    for (int i = 1; i < sizeof(board)/sizeof(*board);i++) {
        cout << board[i];
        if ( (i) % 3 == 0) {
            cout << endl;
        }
        else {
            cout << "|";
        }
    }
}

char getMark(int p) {
    if (p == 1) {
        return 'X';
    }
    else {
        return 'O';
    }
}
int getCurrentPlayer(int player) {
    if (player == 1) {
        return 2;
    }
    else {
        return 1;
    }

}
