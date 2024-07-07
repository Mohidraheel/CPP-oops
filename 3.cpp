#include <iostream>
using namespace std;
class chesspiece
{
    string name;
    string color;
    char symbol;

public:
    chesspiece() : name("pawn"), color("white"), symbol('p')
    {
    }

    chesspiece(string name, string color, char symbol) : name(name), color(color), symbol(symbol) {}

    string getname()
    {
        return name;
    }

    string getcolor()
    {
        return color;
    }

    char getsymbol()
    {
        return symbol;
    }

    void setname(string name)
    {
        this->name = name;
    }

    void setcolor(string color)
    {
        this->color = color;
    }

    void setsymbol(char symbol)
    {
        this->symbol = symbol;
    }
};

class chessboard
{
    chesspiece *board[8][8];

public:
    chessboard()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = nullptr;
            }
        }
        board[0][0] = new chesspiece("rook", "black", 'R');
        board[0][1] = new chesspiece("knight", "black", 'N');
        board[0][2] = new chesspiece("bishop", "black", 'B');
        board[0][3] = new chesspiece("queen", "black", 'Q');
        board[0][4] = new chesspiece("king", "black", 'K');
        board[0][5] = new chesspiece("bishop", "black", 'B');
        board[0][6] = new chesspiece("knight", "black", 'N');
        board[0][7] = new chesspiece("rook", "black", 'R');

        for (int i = 0; i < 8; i++)
        {
            board[1][i] = new chesspiece("pawn", "black", 'P');
        }

        board[7][0] = new chesspiece("rook", "white", 'r');
        board[7][1] = new chesspiece("knight", "white", 'n');
        board[7][2] = new chesspiece("bishop", "white", 'b');
        board[7][3] = new chesspiece("queen", "white", 'q');
        board[7][4] = new chesspiece("king", "white", 'k');
        board[7][5] = new chesspiece("bishop", "white", 'b');
        board[7][6] = new chesspiece("knight", "white", 'n');
        board[7][7] = new chesspiece("rook", "white", 'r');

        for (int i = 0; i < 8; i++)
        {
            board[6][i] = new chesspiece("pawn", "white", 'p');
        }
    }

    void display()
    {
        cout<<"mohid raheel khan 23k-3000"<<endl;
        cout<<"___________________________________________________________________________"<<endl;
        cout << "\ta\tb\tc\td\te\tf\tg\th\n"
             << endl;

        for (int i = 0; i < 8; i++)
        {
            cout << 8 - i ;
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == nullptr)
                {
                    board[i][j] = nullptr;
                    cout << "\t"
                         << " ";
                }
                else
                {
                    cout << "\t" << board[i][j]->getsymbol() << " ";
                }
            }
            cout << "\t" << 8 - i<<"\n" << endl;
        }

        cout << "\ta\tb\tc\td\te\tf\tg\th" << endl;
        cout << "_______________________________________________________________________" << endl;
    }

    bool movepiece(string source, string destination)
    {

        int row = source[1] - '0' - 1;
        int column = source[0] - 'a';
        int finalrow = destination[1] - '0' - 1;
        int finalcolumn = destination[0] - 'a';

        if (board[row][column] == nullptr)
        {
            cout << "no piece at source position" << endl;
            return false;
        }

        if (board[finalrow][column] != nullptr)
        {
            cout << "destination position is occupied" << endl;
            return false;
        }

        char symbol = board[column][row]->getsymbol();
        string color = board[column][row]->getcolor();

        switch (symbol)
        {
        case 'p':
        case 'P':
        {
            if (color == "white")
            {

                if (column == finalcolumn && (row - 1 == finalrow)||(row-2==finalrow))
                {
                    
                    board[finalrow][finalcolumn] = board[row][column];
                    board[row][column] = nullptr;
                    display();
                    cout << "valid move" << endl;
                    return true;
                }
                else
                {
                    cout << "invalid move" << endl;
                    return false;
                }
            }
            else
            {

                if (column == finalcolumn && (row + 1 == finalrow)||(row+2==finalrow))
                {
                   

                    board[finalrow][finalcolumn] = board[row][column];
                    board[row][column] = nullptr;
                    display();
                     cout << "valid move" << endl;
                    return true;
                }
                else
                {
                    cout << "invalid move" << endl;
                    return false;
                }
            }
        }
        break;

        case 'N':
        case 'n':
        {
            if (color == "white")
            {
                int rowchange = abs(finalrow - row);
                int columnchange = abs(finalcolumn - column);
                if ((rowchange == 2 && columnchange == 1) || (rowchange == 1 && columnchange == 2))
                {
                     board[finalrow][finalcolumn] = board[row][column];
                    board[row][column] = nullptr;
                    display();
                    cout << "valid move" << endl;
                    return true;
                }
                else
                {
                    cout << "invalid move" << endl;
                    return false;
                }
            }
            else
            {
                int rowchange = abs(finalrow - row);
                int columnchange = abs(finalcolumn - column);
                if ((rowchange == 2 && columnchange == 1) || (rowchange == 1 && columnchange == 2))
                {
                     board[finalrow][finalcolumn] = board[row][column];
                    board[row][column] = nullptr;
                    display();
                    cout << "valid move" << endl;
                    return true;
                }
                else
                {
                    cout << "invalid move" << endl;
                    return false;
                }
            }
        }
        break;
        }
    }
};

int main()
{
    chessboard board;
    board.display();
    board.movepiece("b2", "b3");
    board.movepiece("g8","f6");
    return 0;
}
