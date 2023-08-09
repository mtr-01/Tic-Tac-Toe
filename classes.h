
using namespace std;


class ticTacToe{
    static int board[3][3];
    static int validMove[9];

    friend class Player;
    friend class EzComputer;
    friend class HdComputer;
public:
    ticTacToe(){
        int i,j;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                board[i][j]=0;
                validMove[(i*3)+j]=1;
            }
        }
    }

    int checkMove(int num){
        return validMove[num];
    }
    void reset(){
        int i,j;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                board[i][j]=0;
                validMove[(i*3)+j]=1;
            }
        }
    }
    void printBoard(){
        system("CLS");
        int i,j;
        cout<<"---Positions---"<<endl;
        for(i=0;i<3;i++){
            cout<<"     ";
            for(j=0;j<3;j++){
                cout<<((i*3)+j);
                if(j<2){
                    cout<<'|';
                }
            }
            cout<<endl;
        }
        cout<<"\n\n";
        cout<<"---Current Board---"<<endl;
        for(i=0;i<3;i++){
            cout<<"     ";
            for(j=0;j<3;j++){
                cout<<board[i][j];
                if(j<2){
                    cout<<'|';
                }
            }
            cout<<endl;
        }
        cout<<endl<<endl<<endl<<endl;
    //    madeby();
    }

};

class Player{
    int num;
public:
    Player(int i){
        num=i;
    }
    int getnum(){
        return num;
    }
    void Move(int pos,ticTacToe b){
            int i,j;
            i=pos/3;
            j=pos%3;
            b.board[i][j]=num;
            b.validMove[pos]=0;
        }
    int checkWin(ticTacToe b, int n){
        int win=0;
        if(b.board[0][0]==n){
            if(b.board[0][1]==n && b.board[0][2]==n){
                win=1;
            }
            if(b.board[1][1]==n && b.board[2][2]==n){
                win=1;
            }
            if(b.board[1][0]==n && b.board[2][0]==n){
                win=1;
            }
        }
        if(b.board[0][2]==n){
            if(b.board[1][1]==n && b.board[2][0]==n){
                win=1;
            }
            if(b.board[1][2]==n && b.board[2][2]==n){
                win=1;
            }
        }
        if(b.board[1][0]==n && b.board[1][1]==n && b.board[1][2]==n){
            win=1;
        }
        if(b.board[2][0]==n && b.board[2][1]==n && b.board[2][2]==n){
            win=1;
        }
        if(b.board[0][1]==n && b.board[1][1]==n && b.board[2][1]==n){
            win=1;
        }
        return win;
    }

};

class EzComputer:public Player{
public:
    EzComputer(int i):Player(i){}

    int gRandPos(ticTacToe b){
        int pos;
        srand (time(0));
        for(int i=1;i<10;i--){
            pos= rand()% 9;
            if(b.validMove[pos]==1){
                break;
            }
        }
        return pos;
    }
};
class HdComputer:public Player{
    int other;
    int bestMove;
public:
    HdComputer(int i):Player(i){
        if(i==1){
            other=2;
        }
        else{
            other=1;
        }
    }

    int noMove(ticTacToe b){
        for(int i=0;i<9;i++){
            if(b.board[i/3][i%3]==0){
                return 0;
            }
        }
        return 1;
    }
    int getBestMove(){
        return bestMove;
    }
int setbestMove(ticTacToe b,bool flag)
{

    int maxVal=-1000,minVal=1000;
    int i,j,value = 1;
    if(checkWin(b,getnum()) == 1)
        {return 10;}
    else if(checkWin(b,other) == 1)
        {return -10;}
    else if(noMove(b)== 1)
        {return 0;}
    int score[9] = {1,1,1,1,1,1,1,1,1};

        for(i=0;i<9;i++)
            {
                 if(b.board[i/3][i%3] == 0)
                {
                    if(minVal>maxVal)
                  {
                      if(flag == true)
                   {
                     b.board[i/3][i%3] = getnum();
                     value = setbestMove(b,false);
                   }
                    else
                    {
                      b.board[i/3][i%3] = other;
                      value = setbestMove(b,true);
                    }
                  b.board[i/3][i%3] = 0;
                  score[i] = value;
                 }
               }
            }

        if(flag == true)
        {
                 maxVal = -1000;
                 for(j=0;j<9;j++)
                {
                    if(score[j] > maxVal && score[j] != 1)
                    {
                        maxVal = score[j];
                        bestMove = j;
                    }
                }
                return maxVal;
        }
        if(flag == false)
        {
                minVal = 1000;
                for(j=0;j<9;j++)
                {
                    if(score[j] < minVal && score[j] != 1)
                    {
                        minVal = score[j];
                        bestMove = j;
                    }
                }
            return minVal;
        }
    }

};

int ticTacToe::board[3][3];
int ticTacToe::validMove[9];
