#ifndef GAME_H
#define GAME_H

#include <QTimer>
#include <QFile>
#include <fstream>
#include <QVector>
#include <QString>
#include "include/boost.h"
#include "include/tank.h"
#include "include/npc.h"
#include "include/block.h"

#define NUM_OF_LEVELS 3

/*!
 * \brief Game::Game
 * \details This is the class with information about current game.
 * Purpose: always knows which level is active and display it to mainWindow.
 */
class Game
{
public:
    Game();
    void initializeGame();

    QVector<QVector<int>> matrixOfLevel;

private:
    //TODO: consider making class for adding new  levels
    QFile levelsPath[NUM_OF_LEVELS];
    //MatricaNivoa matrixOfLevel[13][13]; TODO Nenad: napraviti klasu

    /*!
     * \brief loadLevel opens file for activeLevel
     * and fill the matrixOfLevel acording to that file.
         TODO: Generate vector of npcs .
     *
     * \details Function should be called at the begining of every level
     * which is when npcs vector become empty. The file should have
     * the number of every type of npc that will be in that level. Sum
     * of all numbers should be equal to 20
     */
    void loadLevel(int levelNum);

    QVector<Npc> _npcs;

    //Player players[2]; //TODO Ivana: napravi klasu
    int _numOfLifes;
    int _activeLevel;
    QScopedPointer<Tank> _player;
    QVector<Boost> _powerups;

    QScopedPointer<QTimer> _levelTicker;
};

#endif // GAME_H