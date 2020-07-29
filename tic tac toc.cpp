#include <iostream>
using namespace std;

char pos[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char winner;
bool game_over = false;
void design()
{
    cout << "********TIC TAC TOC GAME*********" << endl
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
bool check_row()
{

    if ((pos[0][0] != 0) && (pos[0][1] == pos[0][0]) && (pos[0][2] == pos[0][0]))
    {
        winner = pos[0][0];
        return true;
    }
    return false;
}
int main()
{
    int player_1;
    design();

    while (!game_over)
    {
        if (check_row())
        {
            cout << "winner is " << winner << endl;
            game_over = true;
        }
        else
        {

            cout << "player 1 turn(X) : " << endl;

            cin >> player_1;

            switch (player_1)
            {
            case 1:
                pos[0][0] = 'X';
                break;
            case 2:
                pos[0][1] = 'X';
                break;
            case 3:
                pos[0][2] = 'X';
                break;
            case 4:
                pos[1][0] = 'X';
                break;
            case 5:
                pos[1][1] = 'X';
                break;
            case 6:
                pos[1][2] = 'X';
                break;
            case 7:
                pos[2][0] = 'X';
                break;
            case 8:
                pos[2][1] = 'X';
                break;
            case 9:
                pos[2][2] = 'X';
                break;
            default:
                cout << "enter valid number";
                break;
            }
            design();
        }
    }

    return 0;
}