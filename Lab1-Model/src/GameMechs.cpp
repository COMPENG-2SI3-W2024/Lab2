#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    // Set Default Board Size
    boardSizeX = 30;
    boardSizeY = 15;
    exitFlag = false;
    loseFlag = false;
    cmd = '\0';
    delayConst = 100000;
    playerCount = 0;

    // Allocate 2D gameboard on the Heap - distributed method
    gameBoard = new char*[boardSizeY];
    for(int i = 0; i < boardSizeY; i++)
    {
        gameBoard[i] = new char[boardSizeX];
    }

    playerList = new Player*[MAX_PLAYER_COUNT];  // up to 4 players only

    // Set up the initiali game board boarders
    setInitBoard();  
}

GameMechs::~GameMechs()
{
    // Deallocate the rows first
    for(int i = 0; i < boardSizeY; i++)
    {
        delete[] gameBoard[i];
    }

    // Then deallocate the row lookup table.
    delete[] gameBoard;

    delete playerList;
}

void GameMechs::setInitBoard()  // private helper function
{
    for(int i = 0; i < boardSizeY; i++)  // T1 = Theta(n)
    {
        for(int j = 0; j < boardSizeX; j++)  // T2 = Theta(n)
        {
            if(i == 0 || i == (boardSizeY - 1) || j == 0 || j == (boardSizeX - 1))  // T3 = Theta(1)
                gameBoard[i][j] = '#';  
            else
                gameBoard[i][j] = ' ';  
            // T4 = Theta(1)
        }
    }  
}

// T = T1 * T2 * (T3+T4) = Theta(n * n * (1+1)) = Theta(2n^2) = Theta(n^2) ##

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

bool GameMechs::getExitFlag() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlag() const
{
    return loseFlag;
}

char GameMechs::getCMD() const
{
    return cmd;  // Theta(1)
}  // Theta(1)

char** GameMechs::getBoardRef() const
{
    return gameBoard;     // Theta(1)
}    // Theta(1)

Player** GameMechs::getPlayerListRef() const
{
    return playerList;  // Theta(1)
}

int GameMechs::getPlayerCount() const
{
    return playerCount;
}



void GameMechs::setExitFlag()  // private helper method
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()  // private helper method
{
    loseFlag = true;
}

bool GameMechs::checkInput()  // private
{
    bool hasChar = MacUILib_hasChar();

    if(hasChar)
    {
        cmd = MacUILib_getChar();
    }

    return hasChar;
}

void GameMechs::processInput()
{
    checkInput();
    
    switch(cmd)
    {
        case 27:
            setExitFlag();
            break;

        default:
            break;
    }
}

void GameMechs::applyDelay()
{
    MacUILib_Delay(delayConst);
}

void GameMechs::addPlayer(Player* pl)
{
    if(playerCount >= MAX_PLAYER_COUNT) return;
    playerList[playerCount] = pl;
    playerCount++;
}

void GameMechs::setGameLost()
{
    setExitFlag();
    setLoseFlag();
}
