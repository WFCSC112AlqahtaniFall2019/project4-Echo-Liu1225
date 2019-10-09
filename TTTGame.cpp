/* Class: TicTacToe
 * Author: Echo Liu
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
using namespace std;

int main() {
    //define the different parameter for the main function, which has been explained in the other two classes
    TicTacToe game;
    int currentPlayerNumber;
    int row;
    int column;


    //enter the  number of players here
    cout << "One-player or Two-player (1 or 2):";
    cin >> currentPlayerNumber;
    game.initializeBoard();
    game.printBoard();

    while (1) {
        //player 1
        if (currentPlayerNumber == 1) {
            cout << "Player :" << endl;
            cout << "Enter row and column:"<<endl;
            cin >> row >> column;
            bool work = game.placeMark(row - 1, column - 1);

            //check whether the number that enter has been repeated
            while (work != true)
            {
                cout << "You entered a wrong position.(It has been taken or both it rows and columns should between 1 and 3" << endl;
                cout<<"Try again: "<< endl;
                cin >> row >> column;
                work = game.placeMark(row-1, column-1);
            }

            game.printBoard();
            game.changePlayer();


            //define the win condition
            if (game.checkForWin()) {
                cout << "You win" << endl;
                break;
            }


            //describe the draw condition
            if(game.isBoardFull()){
                cout<<"Draw"<<endl;
                cout<<"Play again"<<endl;
                return 0;
            }

            srand(int(time(0)));
            row =rand()%3 +1;
            column=rand()%3+1;
            cout<<"Player Computer:"<< endl;
            work=game.placeMark(row-1,column-1) ;

            while(work != true){
                cout<<"You entered a wrong position.(It has been taken or both it rows and columns should between 1 and 3"<< endl;
                cout<<"Please enter again:"<<endl;
                srand(int(time(0)));
                row =rand()%3 +1;
                column=rand()%3+1;
                work=game.placeMark(row-1,column-1) ;
            }
            game.printBoard();
            game.changePlayer();
            if(game.checkForWin()){
                cout<<"Computer wins!"<<endl;
                break;
            }

        }



        //two players
        else if (currentPlayerNumber == 2) {
            //player 1
            cout << "Player 1:" << endl;
            cout << "Enter row and column:" << endl;
            cin >> row >> column;
            bool work = game.placeMark(row - 1, column - 1);

        //check  whether  the numbers has been repeated
            while (work != true)
            {
                cout <<"You entered a wrong position.(It has been taken or both it rows and columns should between 1 and 3.)" << endl;
                cout<<"Please enter again:"<<endl;
                cin >> row >> column;
                work = game.placeMark(row-1, column-1);
            }
            game.printBoard();
            game.changePlayer();
            if (game.checkForWin()) {
                cout << "Player 1 can get the prize!" << endl;
                break;
            }

            if(game.isBoardFull()) {
                cout<<"Draw"<<endl;
                cout<<"Play again!"<<endl;
                return 0;
                }


    //player 2
            cout << "Player 2:" << endl;
            cout << "Enter row and column:" << endl;
            cin >> row >> column;
            bool work1 = game.placeMark(row - 1, column - 1);

            while (work1 != true)
            {
                cout << "You entered a wrong position.(It has been taken or both it rows and columns should between 1 and 3.)"<< endl;
                cout<<"Please enter again:"<<endl;
                cin >> row >> column;
                work1 = game.placeMark(row-1, column-1);
            }
            game.printBoard();
            game.changePlayer();
            if (game.checkForWin()) {
                cout << "Player 2 is the winner!" << endl;
                break;
            }

            if(game.isBoardFull()) {
                cout<<"Draw"<<endl;
            cout<<"Play again!"<<endl;
                }
            }

        }

        return 0;
    }
