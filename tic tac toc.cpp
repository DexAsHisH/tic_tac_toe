#include <iostream>
using namespace std;

char pos[3][3] ={ { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
char winner;
int row=0, col=0;
char player;
bool game_over = false;
void board()
{
    system("cls");
    cout << "TIC TAC TOE" << endl
        << endl;

    cout << " " << pos[0][0] << " "
        << "|"
        << " " << pos[0][1] << " "
        << "|"
        << " " << pos[0][2] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << pos[1][0] << " "
        << "|"
        << " " << pos[1][1] << " "
        << "|"
        << " " << pos[1][2] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << pos[2][0] << " "
        << "|"
        << " " << pos[2][1] << " "
        << "|"
        << " " << pos[2][2] << " " << endl;
}
//for choosing a player
void start() {

    cout<<"press [X] for player 1 : "<<endl<<"press [O] for player 2 :"<<endl;
    cin>>player;
    if (player=='x')
    {
        cout<<"you are now --> X "<<endl;
        player;
    }
    else if (player=='o')
    {
        cout<<"you are now --> O "<<endl;
        player;
    }
    else
    {
        cout<<"incorrect choice :( "<<endl;
    }

}
//for player turn
void play() {
    int choice;
    if (player=='x')
    {
        cout<<"player 1 turn [X] :"<<endl;
    }
    else if (player = 'o')
    {
        cout<<"player 2 turn [O] :"<<endl;
    }

    cin >> choice;
    switch (choice)
    {
    case 1:
        row=0; col=0;
        break;
    case 2:
        row=0; col=1;
        break;
    case 3:
        row=0; col=2;
        break;
    case 4:
        row=1; col=0;
        break;
    case 5:
        row=1; col=1;
        break;
    case 6:
        row=1; col=2;
        break;
    case 7:
        row=2; col=0;
        break;
    case 8:
        row=2; col=1;
        break;
    case 9:
        row=2; col=2;
        break;
    default:
        cout << "incorrect choice :( "<<endl;
        break;
    }
    if (player == 'x' && pos[row][col] !='x' && pos[row][col]!= 'o')
    {
        pos[row][col] = 'x';
        player = 'o';
    }
    else if (player == 'o' && pos[row][col] !='x' && pos[row][col]!= 'o')
    {
        pos[row][col] = 'o';
        player = 'x';
    }
    else {
        cout<<" box already filled, please choose another :"<<endl;
        play();
    }
}

//for checking the rows
bool check_row()
{
    for (int i=0; i<3; i++)
    {
        if (pos[i][0]!=' ' && pos[i][0]==pos[i][1] && pos[i][0]==pos[i][2])
        {
            winner = pos[i][0];
            return true;
        }

    }
  return false;
}
//for checking the columns
bool check_col()
{
    for (int i=0; i<3; i++)
    {
        if (pos[0][i]!=' ' && pos[0][i]==pos[1][i] && pos[0][i]==pos[2][i])
        {
            winner = pos[0][i];
           return true;
        }

    }
    return false;

}
//for checking the diagonals
bool check_dia()
{
    if ((pos[0][0]!=' ') && (pos[1][1] == pos[0][0]) && (pos[2][2] == pos[0][0]))
    {
        winner = pos[0][0];
        return true;
    }
    if ((pos[0][2]!=' ') && (pos[1][1] == pos[0][2]) && (pos[2][0] == pos[0][2]))
    {
        winner = pos[0][2];
        return true;
    }
    return false;
}
//for checking the Draw
bool check_draw()
{
     bool draw = true;

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (pos[i][j]==' ')
            {
                draw = false;
                break;
            }
            
        }
         if(draw == false)
            {
                break;
            }
    }
    return draw;
}

int main()
{
    board();
    start();

    while (!game_over)
    {
        if (check_row())
        {
            cout << "winner is X" << winner << endl;
            game_over = true;
        }
        else if (check_col())
        {
            cout << "winner is O" << winner << endl;
            game_over = true;
        }
        else if (check_dia())
        {
            cout << "winner is ashu " << winner << endl;
            game_over = true;
        }
        else if (check_draw())
        {
            cout << "its a Draw!!!, Play again" << endl;
            game_over = true;
        }
        else
        {
            play();
            board();
        }
    }

    return 0;
}