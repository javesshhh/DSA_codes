#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Player
{
private:
    int playerId;
    string playerName;
    string email;
    int rank;
    char symbol;

public:
    Player() {}
    Player(int id, string name, char sym) : playerId(id), playerName(name), symbol(sym) {}

    int getPlayerId() { return playerId; }
    string getPlayerName() { return playerName; }
    char getPlayerSymbol() { return symbol; }
};

class Board
{
public:
    vector<vector<char>> board;
    int size;
    queue<Player> q;

    Board(int size, Player players[]) : size(size)
    {
        board.resize(2 * size - 1, vector<char>(2 * size - 1, ' '));
        initializeBoard();
        q.push(players[0]);
        q.push(players[1]);
    }

    void initializeBoard()
    {
        for (int i = 0; i < 2 * size - 1; i++)
        {
            for (int j = 0; j < 2 * size - 1; j++)
            {
                if (i % 2 == 0 && j % 2 == 1)
                    board[i][j] = '|';
                else if (i % 2 == 1 && j % 2 == 0)
                    board[i][j] = '-';
                else if (i % 2 == 1 && j % 2 == 1)
                    board[i][j] = '+';
            }
        }
    }

    void printBoard()
    {
        for (const auto &row : board)
        {
            for (const auto &cell : row)
            {
                cout << cell;
            }
            cout << endl;
        }
    }

    void startGame()
    {
        int cnt = 0;
        while (true)
        {
            cnt++;
            if (cnt == (size * size) + 1)
            {
                cout << "Match draw" << endl;
                break;
            }
            Player p = q.front();
            q.pop();
            int position = getUserInput(p);
            int row = 2 * ((position % size == 0) ? (position / size) - 1 : (position / size));
            int col = 2 * ((position % size == 0) ? size - 1 : (position % size) - 1);
            board[row][col] = p.getPlayerSymbol();
            printBoard();
            cout << "Board after the move:" << endl;
            if (cnt >= 2 * size && check(p, row, col))
                break;
            q.push(p);
        }
    }

    int getUserInput(Player p)
    {
        printBoard();
        cout << p.getPlayerName() << ", please enter a number between 1 and " << size * size << ": ";
        int val;
        cin >> val;
        while (!validInput(val))
        {
            printBoard();
            cout << "Invalid move. Please enter a valid number: ";
            cin >> val;
        }
        return val;
    }

    bool validInput(int val)
    {
        if (val < 1 || val > (size * size))
            return false;
        int row = 2 * ((val % size == 0) ? (val / size) - 1 : (val / size));
        int col = 2 * ((val % size == 0) ? size - 1 : (val % size) - 1);
        return board[row][col] == ' ';
    }

    bool check(Player p, int row, int col)
    {
        string winString(size, p.getPlayerSymbol());

        // Check row
        string rowString;
        for (int i = 0; i < 2 * size - 1; i += 2)
        {
            rowString += board[row][i];
        }
        if (rowString == winString)
        {
            cout << p.getPlayerName() << " has won!" << endl;
            return true;
        }

        // Check column
        string colString;
        for (int i = 0; i < 2 * size - 1; i += 2)
        {
            colString += board[i][col];
        }
        if (colString == winString)
        {
            cout << p.getPlayerName() << " has won!" << endl;
            return true;
        }

        // Check diagonals
        if (row == col)
        {
            string diagonalString;
            for (int i = 0; i < 2 * size - 1; i += 2)
            {
                diagonalString += board[i][i];
            }
            if (diagonalString == winString)
            {
                cout << p.getPlayerName() << " has won!" << endl;
                return true;
            }
        }

        if (row + col == 2 * size - 2)
        {
            string revDiagonalString;
            for (int i = 0; i < 2 * size - 1; i += 2)
            {
                revDiagonalString += board[i][2 * size - 2 - i];
            }
            if (revDiagonalString == winString)
            {
                cout << p.getPlayerName() << " has won!" << endl;
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Player p1(1, "Albert", 'X');
    Player p2(2, "Pinto", 'O');
    Player players[] = {p1, p2};
    Board gameBoard(3, players); // Tic-tac-toe is typically a 3x3 game
    gameBoard.startGame();

    return 0;
}
