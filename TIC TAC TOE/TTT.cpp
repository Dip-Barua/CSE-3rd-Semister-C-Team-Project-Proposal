#include<iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
bool tie = false;
string n1, n2;

void printBoard() {
    cout << "    |     |   \n";
    cout << "  " << space[0][0] << " |  " << space[0][1] << "  |  " << space[0][2] << " \n";
    cout << "____|_____|____\n";
    cout << "    |     |   \n";
    cout << "  " << space[1][0] << " |  " << space[1][1] << "  |  " << space[1][2] << " \n";
    cout << "____|_____|____\n";
    cout << "    |     |   \n";
    cout << "  " << space[2][0] << " |  " << space[2][1] << "  |  " << space[2][2] << " \n";
    cout << "    |     |   \n";
}

bool isValidMove(int digit) {
    return digit >= 1 && digit <= 9 && space[(digit - 1) / 3][(digit - 1) % 3] != 'x' && space[(digit - 1) / 3][(digit - 1) % 3] != '0';
}

void playerMove() {
    int digit;
    if (token == 'x') {
        cout << n1 << " please enter a number: ";
    } else {
        cout << n2 << " please enter a number: ";
    }
    cin >> digit;

    if (!isValidMove(digit)) {
        cout << "Invalid move! Please choose another cell." << endl;
        playerMove();
        return;
    }

    row = (digit - 1) / 3;
    column = (digit - 1) % 3;
    space[row][column] = token;
    token = (token == 'x') ? '0' : 'x';
    printBoard();
}

bool checkWin() {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) || 
            (space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
            return true;
        }
    }
    // Check diagonals for a win
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || 
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cout << "Enter the name of the first player: ";
    getline(cin, n1);
    cout << "Enter the name of the second player: ";
    getline(cin, n2);

    cout << n1 << " is player1, so he/she will play first.\n";
    cout << n2 << " is player2, so he/she will play second.\n";

    printBoard();

    while (!checkWin() && !isBoardFull()) {
        playerMove();
    }

    if (checkWin()) {
        if (token == 'x') {
            cout << n2 << " Wins!!" << endl;
        } else {
            cout << n1 << " Wins!!" << endl;
        }
    } else if (isBoardFull()) {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
