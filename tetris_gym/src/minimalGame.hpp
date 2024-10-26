#ifndef GAME_HPP
#define GAME_HPP

#include <algorithm>
#include <deque>
#include <optional>
#include <random>
#include "board.hpp"
#include "block.hpp"

#define BAG_SIZE 7

struct GameStats
{
    float timeElapsed = 0;
    int droppedBlockCount = 0;
    int clearedLineCount = 0;
    int tSpinCount = 0;
    int tetrisCount = 0;
    int fullClearCount = 0;
    int comboCount = -1;
    int b2bChain = -1;
    int level = 1;
    int score = 0;
};

class Game
{
public:
    Game();

    void Reset();

    void HoldBlock();
    int PlaceBlock(int col, RotateState rotateState);
    bool IsGameOver();

    Board board;
    deque<Block> currentBag;
    optional<Block> currentBlock;
    optional<Block> holdBlock;
    bool usedHold;
    GameStats stats;
private:
    bool gameOver;
    bool tSpinDetected;
    bool normalTspin;

    random_device rd;
    mt19937 rng;

    //Internal
    void GenerateBag(deque<Block> &bag);
    Block NextBlock();
    void LockBlock();

    int GetHardDropPos();
    bool CheckValidPos(int offsetX, int offsetY);
};

#endif /* GAME_HPP */