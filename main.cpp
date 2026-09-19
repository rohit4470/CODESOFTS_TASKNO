#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<char>& board) {
    cout << "\n";
    cout << "     |     |     " << endl;
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(const vector<char>& board, char currentPlayer) {
    // Winning combinations (Rows, Columns, Diagonals)
    int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (board[winPatterns[i][0]] == currentPlayer &&
            board[winPatterns[i][1]] == currentPlayer &&
            board[winPatterns[i][2]] == currentPlayer) {
            return true;
        }
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false; // Found an empty spot, so not a draw
        }
    }
    return true; // All spots filled without a winner
}

void playGame() {
    vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentPlayer = 'X';
    bool gameEnded = false;

    while (!gameEnded) {
        displayBoard(board);

        int choice;
        cout << "Player " << currentPlayer << ", enter a position (1-9): ";
        cin >> choice;

        // Input Validation
        if (cin.fail() || choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid move! Please try again with an available position (1-9).\n";
            continue;
        }

        // Update Board
        board[choice - 1] = currentPlayer;

        // Check Win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "🎉 Congratulations! Player " << currentPlayer << " wins!\n";
            gameEnded = true;
        } 
        // Check Draw
        else if (checkDraw(board)) {
            displayBoard(board);
            cout << "🤝 It's a Draw! Well played both players.\n";
            gameEnded = true;
        } 
        // Switch Player
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    char playAgain;

    cout << "=======================================" << endl;
    cout << "         TIC-TAC-TOE GAME              " << endl;
    cout << "=======================================" << endl;

    do {
        playGame();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing Tic-Tac-Toe! Goodbye.\n";

    return 0;
}