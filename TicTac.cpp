
#include <iostream>
#include <string>

using namespace std;

class TicTacToe
{
public:
    // TTT board, empty by default
    char board[3][3] =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // used for keeping track what's in each space, and what value each player has
    enum Entry
    {
        EMPTY = ' ',
        PLAYER_ONE = 'x',
        PLAYER_TWO = 'o'
    };

    // has the board been completely filled?
    bool isFull()
    {
        bool result = true;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == Entry::EMPTY)
                    result = false;
            }
        }

        return result;
    }

    // has someone won?
    bool isVictory(Entry e)
    {

        // first col
        if (board[0][0] == (char)e && board[0][1] == (char)e && board[0][2] == (char)e)
        {
            return true;
        }

        // second col
        else if (board[1][0] == (char)e && board[1][1] == (char)e && board[1][2] == (char)e)
        {
            return true;
        }

        // third col
        else if (board[2][0] == (char)e && board[2][1] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // first row
        else if (board[0][0] == (char)e && board[1][0] == (char)e && board[2][0] == (char)e)
        {
            return true;
        }

        // second row
        else if (board[0][1] == (char)e && board[1][1] == (char)e && board[2][1] == (char)e)
        {
            return true;
        }

        // third row
        else if (board[0][2] == (char)e && board[1][2] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // diagonal 1
        else if (board[0][0] == (char)e && board[1][1] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // diagonal 2
        else if (board[0][2] == (char)e && board[1][1] == (char)e && board[2][0] == (char)e)
        {
            return true;
        }

        return false;
    }

    // can specified competitor win in the next move?
    string willWin(Entry e)
    {
        //get character index and then chartoint within ai
        //string = "cr"
        //returns nowin if there are no places for character e to win in the next round

        // first col win possible
        if ( board[0][1] == (char)e && board[0][2] == (char)e)
        {
            return "00";
        }
        else if (board[0][0] == (char)e && board[0][2] == (char)e)
        {
            return "01";
        }
        else if (board[0][0] == (char)e && board[0][1] == (char)e)
        {
            return "02";
        }

        // second col
        else if (board[1][1] == (char)e && board[1][2] == (char)e)
        {
            return "10";
        }
        else if (board[1][0] == (char)e && board[1][2] == (char)e)
        {
            return "11";
        }
        else if (board[1][0] == (char)e && board[1][1] == (char)e)
        {
            return "12";
        }

        // third col
        else if (board[2][1] == (char)e && board[2][2] == (char)e)
        {
            return "20";
        }
        else if (board[2][0] == (char)e && board[2][2] == (char)e)
        {
            return "21";
        }
        else if (board[2][0] == (char)e && board[2][1] == (char)e)
        {
            return "22";
        }

        // first row 
        else if (board[1][0] == (char)e && board[2][0] == (char)e)
        {
            return "00";
        }
        else if (board[0][0] == (char)e && board[2][0] == (char)e)
        {
            return "10";
        }
        else if (board[0][0] == (char)e && board[1][0] == (char)e)
        {
            return "20";
        }

        // second row
        else if (board[1][1] == (char)e && board[2][1] == (char)e)
        {
            return "01";
        }
        else if (board[0][1] == (char)e && board[2][1] == (char)e)
        {
            return "11";
        }
        else if (board[0][1] == (char)e && board[1][1] == (char)e)
        {
            return "21";
        }

        // third row
        else if (board[1][2] == (char)e && board[2][2] == (char)e)
        {
            return "02";
        }
        else if (board[0][2] == (char)e && board[2][2] == (char)e)
        {
            return "12";
        }
        else if (board[0][2] == (char)e && board[1][2] == (char)e)
        {
            return "22";
        }

        // diagonal 1
        else if (board[1][1] == (char)e && board[2][2] == (char)e)
        {
            return "00";
        }
        else if (board[0][0] == (char)e && board[2][2] == (char)e)
        {
            return "11";
        }
        else if (board[0][0] == (char)e && board[1][1] == (char)e)
        {
            return "22";
        }

        // diagonal 2
        else if (board[1][1] == (char)e && board[2][0] == (char)e)
        {
            return "02";
        }
        else if (board[0][2] == (char)e && board[2][0] == (char)e)
        {
            return "11";
        }
        else if (board[0][2] == (char)e && board[1][1] == (char)e)
        {
            return "20";
        }

        return "nowin";//no winning moves detected
    }


    // return size of the board; mostly just in case I wanted to make the board expandable
    int getSize()
    {
        return 3;
    }


    void dump()
    {
        cout << "----------------------------------------" << endl << endl;
        for (int i = 0; i < getSize(); i++)
        {
            for (int j = 0; j < getSize(); j++)
            {
                cout << " | " << board[i][j] << " | ";
            }

            cout << endl;
        }
        cout << "----------------------------------------" << endl << endl;
    }

};

static bool getHumanMove(int maxValue, TicTacToe::Entry human, TicTacToe& t)
{
    // check if player is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    int rowChoice = 0;
    int colChoice = 0;

    do {

        do {

            cout << "Enter column number (x) : 0 ... 2 : ";
            cin >> colChoice;
            cout << endl;

        } while (colChoice > maxValue || colChoice < 0);

        do {

            cout << "Enter row number (y) : 0 ... 2 : ";
            cin >> rowChoice;
            cout << endl;

        } while (rowChoice > maxValue || rowChoice < 0);


        if (t.board[rowChoice][colChoice] == t.EMPTY)
        {
            t.board[rowChoice][colChoice] = (char)human;

            return false;
        }

        else
        {
            cout << "Not a valid option! Please try again..." << endl;
        }


    } while (t.board[rowChoice][colChoice] != t.EMPTY);

    // move complete
    return false;
}

/*https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
* https://learn.microsoft.com/en-us/cpp/cpp/enumerations-cpp?view=msvc-160
* test for instant win in one move
* test for player win in next move(block)
* grab for center
* test for future win:
* if nothing is setup to win, and center is not taken, then:
* if central side point is taken, then check if both sides are open, or one corner is also taken by ai, if not then go random
* if corner point is taken, then check central side points for occupation, and attempt to take that and corners?
*/



static bool getComputerMove(TicTacToe::Entry computer, TicTacToe& t)
{
    // check if computer is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    // handle computer's move

    int rowChoice = 0;
    int colChoice = 0;

    //will win notes:
    //p1 is human
    //get character index and then chartoint within main
    //string = "cr"
    //returns nowin if there are no places for character e to win in the next round
    string p1WillWin = t.willWin(t.PLAYER_ONE);
    string p2WillWin = t.willWin(t.PLAYER_TWO);

    //if player one is not failing to win, then they are about to win
    if (p2WillWin != "nowin")
    {//if computer is about to win, then win. ignore human

        colChoice = (p2WillWin.at(0)) - '0';//convert first index from char to int.
        rowChoice = (p2WillWin.at(1)) - '0';
        //uses the difference in positions on the ascii alphabet between "character" 0 and the character that was returned.
        //4 is 4 positions apart
        //https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
        //has caveats but complies with the current usage
    }
    else if (p1WillWin != "nowin")
    {//if player is about to win, block

        colChoice = (p1WillWin.at(0)) - '0';//convert first index from char to int
        rowChoice = (p1WillWin.at(1)) - '0';
    }
    /*
    * actually, i'm not a fan of this mindset.
    * as a player, i consider knowing exactly what my opponents first move is going to be sad, and sometimes boring.
    * most of the ai from older tictactoe games followed this religously.
    * as discussed in class, taking center has an almost equal chance of winning as it does tieing. aka good chance of not loosing, but thats it.
    * my prefernce is chaos, after consideration. try to win, otherwise chaos. at least for tic tac toe.
    * 
    else if (true)
    {//if center is occupied by comp

    }
    else if (true)
    {//if center is occupied by player

    }
    */

    else//pick a spot at random, and try to play there.
    {
        
        do {

            // choose at random until we find a space that's empty
            do {

                rowChoice = rand() % ((t.getSize() - 0) + 1) + 0;

            } while (rowChoice > t.getSize() || rowChoice < 0);

            do {

                colChoice = rand() % ((t.getSize() - 0) + 1) + 0;

            } while (colChoice > t.getSize() || colChoice < 0);


            if (t.board[rowChoice][colChoice] == t.EMPTY)
            {
                t.board[rowChoice][colChoice] = (char)computer;

                return false;//exit func
            }

            else
            {
                //cout << "Not a valid option! Please try again..." << endl;
            }


        } while (t.board[rowChoice][colChoice] != t.EMPTY);//while selected choice is not empty

    }

    // move complete
    return false;
}

// ----------------------------
// main
// ----------------------------

int main()
{
    TicTacToe t;
    TicTacToe::Entry human = TicTacToe::PLAYER_ONE;
    TicTacToe::Entry computer = TicTacToe::PLAYER_TWO;

    int maxValue = t.getSize();

    cout << "----------------------------------------" << endl;

    cout << "You are '" << (char)human << "', " <<
        "the computer is: '" << (char)computer << "'" << endl;

    cout << "----------------------------------------" << endl << endl;

    // run the game until one player isn't able to go again
    do
    {
        // show board
        t.dump();
    } while (!getHumanMove(maxValue, human, t) && !getComputerMove(computer, t));


    t.dump();

    cout << endl;

    if (t.isVictory(human))
        cout << "Human Victory" << endl;

    else if (t.isVictory(computer))
        cout << "Computer Victory" << endl;

    else if (t.isFull())
        cout << "Tie" << endl;

    return(0);
}





