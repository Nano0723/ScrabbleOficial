#include "gameboard.h"
#include "main.cpp"
#include "slot.h"
#include <string>
#include <QDebug>

/**
 * @brief Default constructor of GameBoard class.
 * @param scene Reference to the QGraphicsScene object used for visual display.
 */
GameBoard::GameBoard(QGraphicsScene* scene){
    this->scene=scene;

    QBrush myBrush(Qt::darkGray, Qt::Dense5Pattern);

    int gridX = 0;
    int gridY = 0;
    int displayX = 0;
    int displayY = 0;

    while(gridY < 15){

        Slot *slot = new Slot();
        slot->registerPos(gridX,gridY);
        slot->setPos(displayX,displayY);
        slot->setMultiplier(getMultiplier(gridX, gridY));
        this->scene->addItem(slot);

        this->grid[gridY][gridX]=slot;

        displayX+=40;
        if(displayX == 600){
            displayX =0;
            displayY+=40;
        }

        gridX++;
        if(gridX == 15){
            gridX = 0;
            gridY++;
        }
    }
}

/**
 * @brief Returns the word multiplier of a specific grid slot.
 * @param x Slot's x coordinate.
 * @param y Slot's y coordinate.
 * @return int Slot's multiplier.
 */
int GameBoard::getMultiplier(int x, int y)
{
    std::string strx = std::to_string(x);
    std::string stry = std::to_string(y);
    std::string xy = strx+","+stry;

    if(xy == "1,1" || xy == "13,1" || xy == "1,13" || xy == "13,13"){
        return 5;

    }else if(xy == "2,2" || xy == "2,12" || xy == "12,2" || xy == "12,12"){
        return 4;

    }else if(xy == "2,4" || xy == "2,7" || xy == "2,10" || xy == "4,2" ||
             xy == "4,12" || xy == "7,2" || xy == "7,12" || xy == "10,2"
             || xy == "10,12" || xy == "12,4" || xy == "12,7" || xy == "12,10"){
        return 3;

    }else if(xy == "6,3" || xy == "8,3" || xy == "5,4" || xy == "9,4" ||
             xy == "4,5" || xy == "10,5" || xy == "3,6" || xy == "11,6" ||

             xy == "3,8" || xy == "11,8" || xy == "4,9" || xy == "10,9" ||
             xy == "5,10" || xy == "9,10" || xy == "6,11" || xy == "8,11"
             ){
        return 2;

    }else{
        return 1;
    }
}
