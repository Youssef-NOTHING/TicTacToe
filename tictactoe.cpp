#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char currentPlayer = 'X';
bool gameOver = false;

// Draw the board
void drawBoard() {
    cout << endl;
    cout << "-------------" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "| ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Player move
void playerMove() {
    int choice;
    cout << "\nPlayer " << currentPlayer << ", choose a position (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(choice < 1 || choice > 9) {
        cout << "❌ Invalid choice! Try again.\n";
        playerMove();
    }
    else if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
    }
    else {
        cout << "❌ Position already taken! Try again.\n";
        playerMove();
    }
}

// Check win
bool checkWin() {
    // Rows & Columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    cout << "🎮 TIC TAC TOE GAME 🎮\n";

    while(!gameOver) {
        drawBoard();
        playerMove();

        if(checkWin()) {
            drawBoard();
            cout << "\n🏆 Player " << currentPlayer << " wins!\n";
            gameOver = true;
        }
        else if(checkDraw()) {
            drawBoard();
            cout << "\n🤝 It's a draw!\n";
            gameOver = true;
        }
        else {
            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
