#include <iostream>
using namespace std;


class SudokuGame {
    //Private Member Variables
private:
    int grid[9][9];
    int gridSol[9][9];
public:
    // constructor that initializes the grid with zeros (empty cells)
    SudokuGame() {
        // Initialize the grid with zeros (empty cells)
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                grid[i][j] = 0;
            }
        }
        // clues for the game
        grid[0][0] = 1; grid[0][1] = 3; grid[0][4] = 2; grid[0][5] = 4; grid[0][6] = 7; grid[0][7] = 9;
        grid[1][0] = 8; grid[1][3] = 3; grid[1][4] = 6; grid[1][5] = 7; grid[1][6] = 1; grid[1][8] = 4;
        grid[2][1] = 2; grid[2][2] = 4; grid[2][4] = 8; grid[2][5] = 1; grid[2][7] = 5; grid[2][8] = 6;
        grid[3][0] = 5; grid[3][1] = 8; grid[3][2] = 3; grid[3][3] = 6; grid[3][5] = 9; grid[3][8] = 1;
        grid[4][0] = 2; grid[4][1] = 6; grid[4][2] = 1; grid[4][6] = 9; grid[4][7] = 4; grid[4][8] = 5;
        grid[5][0] = 4; grid[5][3] = 1; grid[5][5] = 2; grid[5][6] = 6; grid[5][7] = 8; grid[5][8] = 3;
        grid[6][0] = 6; grid[6][1] = 4; grid[6][3] = 7; grid[6][4] = 1; grid[6][6] = 5; grid[6][7] = 3;
        grid[7][0] = 9; grid[7][2] = 7; grid[7][3] = 4; grid[7][4] = 3; grid[7][5] = 6; grid[7][8] = 2;
        grid[8][1] = 1;grid[8][2] = 8; grid[8][3] = 2;grid[8][4] = 9; grid[8][7] = 6; grid[8][8] = 7;

//SOLUTION
        gridSol[0][0] = 1;gridSol[0][1] = 3;gridSol[0][2] = 6;gridSol[0][3] = 5;gridSol[0][4] = 2;gridSol[0][5] = 4;
        gridSol[0][6] = 7;gridSol[0][7] = 9;gridSol[0][8] = 8;gridSol[1][0] = 8;gridSol[1][1] = 9;gridSol[1][2] = 5;
        gridSol[1][3] = 3;gridSol[1][4] = 6;gridSol[1][5] = 7;gridSol[1][6] = 1;gridSol[1][7] = 2;gridSol[1][8] = 4;
        gridSol[2][0] = 7;gridSol[2][1] = 2;gridSol[2][2] = 4;gridSol[2][3] = 9;gridSol[2][4] = 8;gridSol[2][5] = 1;
        gridSol[2][6] = 3;gridSol[2][7] = 5;gridSol[2][8] = 6;gridSol[3][0] = 5;gridSol[3][1] = 8;gridSol[3][2] = 3;
        gridSol[3][3] = 6;gridSol[3][4] = 4;gridSol[3][5] = 9;gridSol[3][6] = 2;gridSol[3][7] = 7;gridSol[3][8] = 1;
        gridSol[4][0] = 2;gridSol[4][1] = 6;gridSol[4][2] = 1;gridSol[4][3] = 8;gridSol[4][4] = 7;gridSol[4][5] = 3;
        gridSol[4][6] = 9;gridSol[4][7] = 4;gridSol[4][8] = 5;gridSol[5][0] = 4;gridSol[5][1] = 7;gridSol[5][2] = 9;
        gridSol[5][3] = 1;gridSol[5][4] = 5;gridSol[5][5] = 2;gridSol[5][6] = 6;gridSol[5][7] = 8;gridSol[5][8] = 3;
        gridSol[6][0] = 6;gridSol[6][1] = 4;gridSol[6][2] = 2;gridSol[6][3] = 7;gridSol[6][4] = 1;gridSol[6][5] = 8;
        gridSol[6][6] = 5;gridSol[6][7] = 3;gridSol[6][8] = 9;gridSol[7][0] = 9;gridSol[7][1] = 5;gridSol[7][2] = 7;
        gridSol[7][3] = 4;gridSol[7][4] = 3;gridSol[7][5] = 6;gridSol[7][6] = 8;gridSol[7][7] = 1;gridSol[7][8] = 2;
        gridSol[8][0] = 3;gridSol[8][1] = 1;gridSol[8][2] = 8;gridSol[8][3] = 2;gridSol[8][4] = 9;gridSol[8][5] = 5;
        gridSol[8][6] = 4;gridSol[8][7] = 6;gridSol[8][8] = 7;
    }

// function, game loop row column number, player alternates,until full
    void playGame() {
        string* name, n;
        cout << "Enter player 1 name:";
        cin >> n;
        name = &n;

        string* name2, n2;
        cout << "Enter player 2 name:";
        cin >> n2;
        name2 = &n2;
        cout << "Hello, " << *name << " & " <<*name2 << "!" << " Welcome to our Sudoku Game!"<< endl;

        GameTemplate();

        while (!isFull()) {

            char choice;
            int row, col, num;
            cout << "\n" << *name << " enter the row (1-9):";
            cin >> row;
            cout << *name << " enter the column (1-9):";
            cin >> col;
            cout << *name << " enter the number (1-9):";
            cin >> num;
// calling functions to validate the move and update the grid accordingly.
            if(row > 9 || col > 9 || num > 9 ) {
                cout << "Reminder: You cannot enter a row, \ncolumn, or numbers greater than 9." << endl;
            }
            else if (isValidMove(row - 1, col - 1, num)) {
                grid[row - 1][col - 1] = num;
                cout << "Move successful!" << endl;
                GameGrid()
                        ;}
            else {
                cout << "\n\n!!!!!!!!!!ATTENTION!!!!!!!!!!!\n";
                cout << "Invalid. Try again or show solution. \n(T/S):" << endl;
                cin >> choice;
                if(choice == 'S'){
                    GameSolution();
                }
            }
            int row2, col2, num2;
            cout << *name2 << " enter the row (1-9):";
            cin >> row2;
            cout << *name2 << " enter the column (1-9):";
            cin >> col2;
            cout << *name2 << " enter the number (1-9):";
            cin >> num2;

            if(row2 > 9 || col2 > 9 || num2 > 9 ){
                cout << "Reminder: You cannot enter a row, \ncolumn, or numbers greater than 9." << endl;
            }
            else if (isValidMove(row2 - 1, col2 - 1, num2)) {
                grid[row2 - 1][col2 - 1] = num2;
                cout << "Move successful!" << endl;
                GameGrid();
            }

            else {
                cout << "\n\n!!!!!!!!!!ATTENTION!!!!!!!!!!!" << endl;
                cout << "Invalid.\nTo show solution type 'S'" << endl;
                cin >> choice;
                if(choice == 'S'){
                    GameSolution();
                }
            }
        }
        cout << "Congratulations, " << *name << " & " << *name2 << "you have completed the Sudoku Game!";
    }
private:
    bool isValidMove(int row, int col, int num) {
        // how to check if the number already exists in the same row or column
        for (int i = 0; i < 9; i++) {
            if (grid[row][i] == num || grid[i][col] == num) {
                return false;
            }
        }
        return true;
    }
    bool isFull() {
        // how to proof if there is any cell is still empty
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    void GameTemplate(){
        int AA[] = {1, 3, 0, 0, 2, 4, 7, 9, 0};
        int AB[] = {8, 0, 0, 3, 6, 7, 1, 0, 4};
        int AC[] = {0, 2, 4, 0, 8, 1, 0, 5, 6};

        int BA[] = {5, 8, 3, 6, 0, 9, 0, 0, 1};
        int BB[] = {2, 6, 1, 0, 0, 0, 9, 4, 5};
        int BC[] = {4, 0, 0, 1, 0, 2, 6, 8, 3};

        int CA[] = {6, 4, 0, 7, 1, 0, 5, 3, 0};
        int CB[] = {9, 0, 7, 4, 3, 6, 0, 0, 2};
        int CC[] = {0, 1, 8, 2, 9, 0, 0, 6, 7};

        cout << "    ---------------------------" << endl;

        cout << "1   | ";
        for (int i = 0; i < 9; i++) {
            cout << AA[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        cout << "2   | ";
        for (int i = 0; i < 9; i++) {
            cout << AB[i] << " ";
            if((i+1) % 3 == 0) {
                cout << " | ";
            }
        }
        cout << endl;

        cout << "3   | ";
        for (int i = 0; i < 9; i++) {
            cout << AC[i] << " ";
            if((i+1) % 3 == 0) {
                cout << " | ";
            }
        }
        cout << endl;

        cout << "    ----------------------------" << endl;

        cout << "4   | ";
        for (int i = 0; i < 9; i++) {
            cout << BA[i] << " ";
            if((i+1) % 3 == 0) {
                cout << " | ";
            }
        }
        cout << endl;


        cout << "5   | ";
        for (int i = 0; i < 9; i++) {
            cout << BB[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        cout << "6   | ";
        for (int i = 0; i < 9; i++) {
            cout << BC[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        cout << "    ----------------------------" << endl;

        cout <<"7   | ";
        for (int i = 0; i < 9; i++) {
            cout << CA[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        cout << "8   | ";
        for (int i = 0; i < 9; i++) {
            cout << CB[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        cout << "9   | ";
        for (int i = 0; i < 9; i++) {
            cout << CC[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;
    }

    // displays the grid after each move the player makes
    void GameGrid() {
        for (int i = 0; i < 9; ++i) {
            if (i % 3 == 0 && i != 0) {
                cout << "------------------------" <<endl;
            }
            for (int j = 0; j < 9; ++j) {
                if (j % 3 == 0 && j != 0) {
                    cout << "| ";
                }
                cout << grid[i][j] << ' ';
                if ((j + 1) % 3 == 0 && j != 8) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    bool GameSolution() {

        int firstrowA[] = {1, 3, 6, 5, 2, 4, 7, 9, 8};
        int secondrowA[] = {8, 9, 5, 3, 6, 7, 1, 2, 4};
        int thirdrowA[] = {7, 2, 4, 9, 8, 1, 3, 5, 6};

        int firstrowB[] = {5, 8, 3, 6, 4, 9, 2, 7, 1};
        int secondrowB[] = {2, 6, 1, 8, 7, 3, 9, 4, 5};
        int thirdrowB[] = {4, 7, 9, 1, 5, 2, 6, 8, 3};

        int firstrowC[] = {6, 4, 2, 7, 1, 8, 5, 3, 9};
        int secondrowC[] = {9, 5, 7, 4, 3, 6, 8, 1, 2};
        int thirdrowC[] = {3, 1, 8, 2, 9, 5, 4, 6, 7};

        for (int i = 0; i < 9; i++) {
            cout << firstrowA[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        for (int i = 0; i < 9; i++) {
            cout << secondrowA[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        for (int i = 0; i < 9; i++) {
            cout << thirdrowA[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        cout << "--------------------------" << endl;

        for (int i = 0; i < 9; i++) {
            cout << firstrowB[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        for (int i = 0; i < 9; i++) {
            cout << secondrowB[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        for (int i = 0; i < 9; i++) {
            cout << thirdrowB[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        cout << "--------------------------" << endl;

        for (int i = 0; i < 9; i++) {
            cout << firstrowC[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;


        for (int i = 0; i < 9; i++) {
            cout << secondrowC[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        cout << endl;

        for (int i = 0; i < 9; i++) {
            cout << thirdrowC[i] << " ";
            if((i+1) % 3 == 0){
                cout << " | ";
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (gridSol[i][j] == 0) {
                    return false;
                }
            }
        }
        cout << endl;

        cout << "Congratulations on completing the Sudoku Game!";
    };
};
int main() {
    SudokuGame game;
    game.playGame();

    return 0;
}
// displays the grid after each move the player makes
