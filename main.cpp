/*****************************                     *****************************
*	MUHAMMED TUAHA RIZWAN	 *                     *	    ARHAM ADNAN        *
*	   FA21-BSCS-0066	     *                     *	   FA21-BSCS-0063	   *
*	     SECTION-AM          *                     *	     SECTION-AM        *
******************************                     ****************************/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "classes.h"

void madeby(){

    cout<<"\n\n\n\n\n\t\t\t             Made BY:-"<<endl;
    cout<<"**********************************\t\t**********************************"<<endl;
    cout<<"*\tMUHAMMED TUAHA RIZWAN  \t * \t\t*\t  ARHAM ADNAN \t\t *"<<endl;
    cout<<"*\tFA21-BSCS-0066  \t * \t\t*\tFA21-BSCS-0063  \t *"<<endl;
    cout<<"*\t   SECTION-AM  \t\t * \t\t*\t   SECTION-AM  \t\t *"<<endl;
    cout<<"**********************************\t\t**********************************"<<endl;
}
void intro(){
    cout<<"\n\n\t\t==============Welcome to Tic-Tac-Toe=============="<<endl;
    madeby();
    getch();

}

void instructions(){
    system("CLS");
    cout<<"\n\n============\nINSTRUCTIONS:-\n============\n";
    cout<<"\n1)Your tiles are represented by your number on the board.\n";
    cout<<"\n2)The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n";
    cout<<"\n3)When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n";
    cout<<"\n\nPress any key to continue.....";
    madeby();
    getch();
}
int main()
{
    ticTacToe game;
    char a;
    int i,play,temp,match=1;
    intro();
    instructions();
    system("CLS");
    cout<<"\n\t\t\t\t---Select Mode---\n\n"<<endl;
    cout<<"\t\tPress 1 for MultiPlayer (2 Players)"<<endl;
    cout<<"\t\tPress 2 for SinglePlayer (Against Computer)"<<endl;
    cout<<"\t\tAny other key to quit"<<endl;
    cin>>temp;
    if(temp==1){
        Player player1(1);
        Player player2(2);
        while(match){
            play=1;
            i=1;
            game.reset();
            game.printBoard();
            while(play==1){
                if(i%2){
                    cout<<"Player 1 enter position for next move: ";
                    cin>>temp;
                    while(game.checkMove(temp)==0){
                        cout<<"Invalid position. Player 1 please re-enter valid position: ";
                        cin>>temp;
                    }
                    player1.Move(temp,game);
                    game.printBoard();
                    if(player1.checkWin(game,player1.getnum())){
                        cout<<endl<<"YooHoo!!! Player 1 has won the game!!!"<<endl;
                        play=0;
                        cout<<"Press 1 to play again, 0 to quit";
                        cin>>match;
                    }
                    else if(i==9){
                        cout<<endl<<"Match is a tie"<<endl;
                        play=0;
                        cout<<"Press 1 to play again, 0 to quit";
                        cin>>match;
                    }
                }
                else{
                    cout<<"Player 2 enter position for next move: ";
                    cin>>temp;
                    while(game.checkMove(temp)==0){
                        cout<<"Invalid position. Player 2 please re-enter valid position: ";
                        cin>>temp;
                    }
                    player2.Move(temp,game);
                    game.printBoard();
                    if(player2.checkWin(game,player2.getnum())){
                        cout<<endl<<"YooHoo!!! Player 2 has won the game!!!"<<endl;
                        play=0;
                        cout<<"Press 1 to play again, 0 to quit";
                        cin>>match;
                    }

                }

                i++;
            }
        }
    }
    else if(temp==2){
        system("CLS");
        cout<<"\n\t\t\t---Select Difficulty:---\n\n"<<endl;
        cout<<"\t\t1 Easy"<<endl;
        cout<<"\t\t2 Hard"<<endl;
        cin>>temp;
        if(temp==1){
            system("CLS");
            cout<<"Do you want to go first? (y/n)"<<endl;
            cin>>a;
            if(a=='y' || a=='Y'){
                Player player1(1);
                EzComputer comp(2);
                while(match){
                    play=1;
                    i=1;
                    game.reset();
                    game.printBoard();
                    while(play==1){
                        if(i%2){
                            cout<<"Player enter position for next move: ";
                            cin>>temp;
                            while(game.checkMove(temp)==0){
                                cout<<"Invalid position. Player 1 please re-enter valid position: ";
                                cin>>temp;
                            }
                            player1.Move(temp,game);
                            game.printBoard();
                            if(player1.checkWin(game,player1.getnum())){
                                cout<<endl<<"YooHoo!!! You have won the game!!!"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }
                            else if(i==9){
                                cout<<endl<<"Match is a tie"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }
                        }
                        else{
                            temp=comp.gRandPos(game);
                            comp.Move(temp,game);
                            game.printBoard();
                            if(comp.checkWin(game,comp.getnum())){
                                cout<<endl<<"Computer has won the game!!!"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }

                        }

                        i++;
                    }
                }
            }
            else{
                Player player1(2);
                EzComputer comp(1);
                while(match){
                    play=1;
                    i=1;
                    game.reset();
                    game.printBoard();
                    while(play==1){
                        if(i%2){
                            temp=comp.gRandPos(game);
                            comp.Move(temp,game);
                            game.printBoard();
                            if(comp.checkWin(game,comp.getnum())){
                                cout<<endl<<"Computer has won the game!!!"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }
                            else if(i==9){
                                cout<<endl<<"Match is a tie"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }
                        }
                        else{
                            cout<<"Player enter position for next move: ";
                            cin>>temp;
                            while(game.checkMove(temp)==0){
                                cout<<"Invalid position. Player 1 please re-enter valid position: ";
                                cin>>temp;
                            }
                            player1.Move(temp,game);
                            game.printBoard();
                            if(player1.checkWin(game,player1.getnum())){
                                cout<<endl<<"YooHoo!!! You have won the game!!!"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }
                        }

                        i++;
                    }
                }
            }
        }
        else if(temp==2){
            system("CLS");
            cout<<"Do you want to go first? (y/n)"<<endl;
            cin>>a;
            if(a=='y' || a=='Y'){
                Player player1(1);
                HdComputer comp(2);
                while(match){
                    play=1;
                    i=1;
                    game.reset();
                    game.printBoard();
                    while(play==1){
                        if(i%2){
                            cout<<"Player enter position for next move: ";
                            cin>>temp;
                            while(game.checkMove(temp)==0){
                                cout<<"Invalid position. Player 1 please re-enter valid position: ";
                                cin>>temp;
                            }
                            player1.Move(temp,game);
                            game.printBoard();
                            if(player1.checkWin(game,player1.getnum())){
                                cout<<endl<<"YooHoo!!! You have won the game!!!"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }
                            else if(i==9){
                                cout<<endl<<"Match is a tie"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }
                        }
                        else{
                            comp.setbestMove(game,true);
                            temp=comp.getBestMove();
                            comp.Move(temp,game);
                            game.printBoard();
                            if(comp.checkWin(game,comp.getnum())){
                                cout<<endl<<"Computer has won the game!!!"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }

                        }

                        i++;
                    }
                }
            }

        else{
                Player player1(2);
                HdComputer comp(1);
                while(match){
                    play=1;
                    i=1;
                    game.reset();
                    game.printBoard();
                    while(play==1){
                        if(i%2){
                            comp.setbestMove(game,true);
                            temp=comp.getBestMove();
                            comp.Move(temp,game);
                            game.printBoard();
                            if(comp.checkWin(game,comp.getnum())){
                                cout<<endl<<"Computer has won the game!!!"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }
                            else if(i==9){
                                cout<<endl<<"Match is a tie"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }
                        }
                        else{
                            cout<<"Player enter position for next move: ";
                            cin>>temp;
                            while(game.checkMove(temp)==0){
                                cout<<"Invalid position. Player 1 please re-enter valid position: ";
                                cin>>temp;
                            }
                            player1.Move(temp,game);
                            game.printBoard();
                            if(player1.checkWin(game,player1.getnum())){
                                cout<<endl<<"Player 1 has won the game!!!"<<endl;
                                play=0;
                                cout<<"Press 1 to play again, 0 to quit";
                                cin>>match;
                            }
                        }

                        i++;
                    }
                }
            }
        }

    }
    cout<<"\n\n\t\t\t\t----Thanks for Playing----";
    madeby();
    return 0;
}
