/*
                TWO PLAYER TIC TAC TOE GAME

  Created by : VIGNESH PANDIAN T ,
               Student, Thiagarajar College of Engineering.
  Date : 25-02-2023.

*/

#include<bits/stdc++.h>
#include<windows.h> // To change Text Color
using namespace std;
#define N 3

// Function to change text color //
// 7 -> White
// 11-> Blue
// 12-> Red
// 14-> Yellow
void changeColor(int desiredColor){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

class TicTacToe{
    char TTT[N][N];  // Initialize the Tic Tac Toe Board
    int i, j, k, row, col;
    bool flag = false;

 public:
    TicTacToe(){
        changeColor(10);

        cout<<"\n\t\t\t TWO PLAYER TIC TAC TOE GAME \n";
        changeColor(12);
        cout<<"\n\t\t X -> ";changeColor(7);cout<<" PLAYER 1";
        changeColor(11);
        cout<<"\t\t    Y -> ";changeColor(7);cout<<" PLAYER 2";
        changeColor(7);
        cout<<"\n\n   ";
    }
    int game_length_count=9;
    int movecount = game_length_count-8;

    void declare(); //function to initialize the board
    void display(); //function to display TicTacToe board
    void getmoves(); //function to get input for the moves
    void notvalid_display(); //if invalid move, then display "invalid"

    bool check_winner();
    bool top_left_to_bottom_right(); // (\)
    bool top_right_to_bottom_left(); // (/)
    bool top_to_bottom_one();   // (|  )
    bool top_to_bottom_two();   // ( | )
    bool top_to_bottom_three(); // (  |)
    bool left_to_right_top();   // top row
    bool left_to_right_middle();// middle row
    bool left_to_right_bottom();// bottom row

    void play_again();
};

void TicTacToe::declare(){
    memset(TTT, '\0', sizeof(TTT));
}
void TicTacToe::display()
{
    cout<<"\t\t\t\t ";

    // To display column numbers above the board
    for(i=0; i<N ;i++)
        cout<<i<<"     ";
    cout<<"\n\t\t\t      ";
    for(i=0; i<N ;i++)
        cout<<"------";
    cout<<"-";

    // Inner Board
    for(i=0 ; i<N ; i++){
        cout<<"\n\t\t\t    "<<i<<" |"; // Row numbers
        for(j=0 ; j<N ; j++){
            if(TTT[i][j] == 'X'){
                changeColor(12);
                cout<<"  "<<TTT[i][j]<<"  ";
                changeColor(7); cout<<"|";
            }
            else{
                changeColor(11);
                cout<<"  "<<TTT[i][j]<<"  ";
                changeColor(7); cout<<"|";
            }
        }
        cout<<"\n\t\t\t      ";
        for(k=0; k<N ;k++)
            cout<<"------";
        cout<<"-";
    }

}

// Function to get moves
void TicTacToe::getmoves(){

    if(movecount%2 != 0 ){
        changeColor(12);
        cout<<"\n\n\t\t\t\tPLAYER 1's MOVE \n"; changeColor(7);
        cout<<"\n\t\tEnter the ROW index where you want to mark ";
        changeColor(12);cout<<"X ";changeColor(7); cout<<" : ";

        cin>>row;

        cout<<"\t\tEnter the COL index where you want to mark ";
        changeColor(12);cout<<"X ";changeColor(7); cout<<" : ";

        cin>>col; cout<<endl;

        // Check if the move is invalid
        if(row<0 || col<0 || row>3 || col>3 || TTT[row][col]!='\0')
            notvalid_display();

        else{
            TTT[row][col] = 'X';
            display();  //display the board
            if(movecount > game_length_count-5){
                if(check_winner()){
                    changeColor(12);
                    cout<<"\n\n\n\t\t\t\tPLAYER 1 ";
                    changeColor(7); cout<<"WINS! ";
                    play_again();
                }
            }
            movecount++;
        }
    }
    else{
        changeColor(11);
        cout<<"\n\n\t\t\t\tPLAYER 2's MOVE \n"; changeColor(7);
        cout<<"\n\t\tEnter the ROW index where you want to mark ";
        changeColor(11);cout<<"Y ";changeColor(7); cout<<" : ";

        cin>>row;

        cout<<"\t\tEnter the COL index where you want to mark ";
        changeColor(11);cout<<"Y ";changeColor(7); cout<<" : ";

        cin>>col; cout<<endl;
        if(row<0 || col<0 || row>3 || col>3 || TTT[row][col]!='\0')
            notvalid_display();
        else{
            TTT[row][col] = 'Y';
            display();  //display the board

            if(movecount > game_length_count-5){
                if(check_winner()){
                    changeColor(11);
                    cout<<"\n\n\n\t\t\t\tPLAYER 2 ";
                    changeColor(7);
                    cout<<"WINS!";

                    play_again();
                }
            }
            movecount++;
        }
    }
}

bool TicTacToe::check_winner(){

    //Center location
    if(row==1 && col==1)
    {
        // Condition to check in 8 directions ( X and + )
        if(top_left_to_bottom_right() || top_right_to_bottom_left() ||
           top_to_bottom_one() || top_to_bottom_two() || top_to_bottom_three()
           || left_to_right_top() || left_to_right_middle() || left_to_right_bottom())
            return true;
    }

    // Top Left Location
    else if (row==0 && col==0){
        if(top_left_to_bottom_right() || top_to_bottom_one() || left_to_right_top())
            return true;
    }

    // Top Right Location
    else if (row==0 && col==2){
        if(top_right_to_bottom_left() || top_to_bottom_three() || left_to_right_top())
            return true;
    }

    // Bottom Left Location
    else if (row==2 && col==0){
        if(top_right_to_bottom_left() || top_to_bottom_one() || left_to_right_bottom())
            return true;
    }

    // Bottom Right Location
    else if (row==2 && col==2){
        if(top_left_to_bottom_right() || top_to_bottom_three() || left_to_right_bottom())
            return true;
    }

    // Top-Row Middle Location
    else if (row==0 && col==1){
        if(top_to_bottom_two() || left_to_right_top())
            return true;
    }

    // Middle-Row Left Location
    else if (row==1 && col==0){
        if(top_to_bottom_one() || left_to_right_middle())
            return true;
    }

    // Middle-Row Right Location
    else if (row==1 && col==2){
        if(top_to_bottom_three() || left_to_right_middle())
            return true;
    }

    // Bottom-Row Middle Location
    else if (row==2 && col==1){
        if(top_to_bottom_two() || left_to_right_bottom())
            return true;
    }

    return false;
}

// To traverse top left to bottom right
bool TicTacToe::top_left_to_bottom_right(){
    int count=0;
    for(i=0 ; i<N-1 ; i++){
        if(TTT[i][i] == TTT[i+1][i+1]) count++;
    }
    if(count == 2) return true;
    return false;
}

// To traverse top right to bottom left
bool TicTacToe::top_right_to_bottom_left(){
    int count=0;
    for(i=0, j=2 ; i<N-1 ; i++, j--){
        if(TTT[i][j] == TTT[i+1][j-1]) count++;
    }
    if(count == 2) return true;
    return false;
}

// To traverse top to bottom one
bool TicTacToe::top_to_bottom_one(){
    int count=0;
    for(i=0 ; i<N-1 ; i++){
        if(TTT[i][0] == TTT[i+1][0]) count++;
    }
    if(count == 2) return true;
    return false;
}

// To traverse top to bottom two
bool TicTacToe::top_to_bottom_two(){
    int count=0;
    for(i=0 ; i<N-1 ; i++){
        if(TTT[i][1] == TTT[i+1][1]) count++;
    }
    if(count == 2) return true;
    return false;
}

// To traverse top to bottom three
bool TicTacToe::top_to_bottom_three(){
    int count=0;
    for(i=0 ; i<N-1 ; i++){
        if(TTT[i][2] == TTT[i+1][2]) count++;
    }
    if(count == 2) return true;
    return false;
}

// To traverse left to right - top row
bool TicTacToe::left_to_right_top(){
    int count=0;
    for(i=0 ; i<N-1 ; i++){
        if(TTT[0][i] == TTT[0][i+1]) count++;
    }
    if(count == 2) return true;
    return false;
}

// To traverse left to right - middle row
bool TicTacToe::left_to_right_middle(){
    int count=0;
    for(i=0 ; i<N-1 ; i++){
        if(TTT[1][i] == TTT[1][i+1]) count++;
    }
    if(count == 2) return true;
    return false;
}

// To traverse left to right - bottom row
bool TicTacToe::left_to_right_bottom(){
    int count=0;
    for(i=0 ; i<N-1 ; i++){
        if(TTT[2][i] == TTT[2][i+1]) count++;
    }
    if(count == 2) return true;
    return false;
}

//function to display that the input is invalid !
void TicTacToe::notvalid_display()
{
    changeColor(10);
    cout<<"\n\t\t\t   PLEASE ENTER A VALID MOVE !! \n\n";
    changeColor(7);
}

//function to ask the user if they want to play again?
void TicTacToe::play_again()
{
    int play_choice;
    cout<<"\n\n\n  Do you want to play another game?";
    cout<<"\n  1 -> Yes\n  2 -> No";
    cout<<"\n  Enter your choice : ";
    while(!(cin>>play_choice) || (play_choice!=1 && play_choice!=2))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\n\t\t\t  Please enter a ";changeColor(11);
        cout<<"valid ";changeColor(7);cout<<"choice !!";
        cout<<"\n\n  Enter your choice correctly : ";
    }
    if(play_choice==1)
    {
        game_length_count++;

        //separator line
        cout<<endl<<"  ";
        for(int i=0;i<13;i++)
            cout<<"--------";
        cout<<endl;

        changeColor(10);
        cout<<"\n\n\t\t\t\t   NEW GAME! \n\n";
        changeColor(7);

        declare(); // declare a new board
        movecount=game_length_count-9;
        display(); //display the newly declared board
    }
    else
    {
        cout<<"\n\t\t\t THANKS FOR ";changeColor(10);
        cout<<"PLAYING TIC TAC TOE !!\n\n";changeColor(7);

        cout<<"\n\n Developed by : T. VIGNESH PANDIAN \n";
        cout<<"\n Follow me @ \n Github -> https://github.com/Vignesh227/ ";
        cout<<"\n LinkedIn -> https://www.linkedin.com/in/vignesh-pandian-858547229/ \n";
        //separator line
        cout<<endl;
        for(int i=0;i<14;i++)
            cout<<"--------";
        cout<<endl;
        exit(0); //exits the program
    }
}

int main()
{
    TicTacToe obj;
    obj.declare();
    obj.display();
    while(true){
        if(obj.movecount<=obj.game_length_count)
            obj.getmoves();
        else{
            changeColor(10);
            cout<<"\n\n\t\t\t\t   MATCH DRAW ";
            changeColor(7);
            obj.play_again();
        }
    }
    return 0;
}
