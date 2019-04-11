#include "rack.h"
#include "PackTile.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsRectItem>
#include "gtile.h"
#include <QLabel>
#include <QMessageBox>

/**
 * @brief Rack class constructor.
 * @param scene Graphic Scene where the rack will be displayed.
 * @param window Reference to the current GameWindow window.
 */
Rack::Rack(QGraphicsScene *scene, QMainWindow* window){
    this->scene=scene;
    this->window = window;

    int x =0;
    for(int n=0; n < 7; x+=40,n++){
        QPointF pos = QPointF(x,680);
        rackPositions[n] = pos;

        rackTiles[n]=nullptr;
    }

    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            this->lockedGridSlots[i][j]=false;
        }
    }

    QLabel *scoreTitle = new QLabel(window);
    scoreTitle->setText("Scores");
    scoreTitle->setGeometry(QRect(719,60,120,120));
    scoreTitle->setAlignment(Qt::AlignCenter);
    QFont font1;
    font1.setWeight(QFont::Bold);
    font1.setPixelSize(30);
    scoreTitle->setFont(font1);
    scoreTitle->setStyleSheet("QLabel {color:white;}");
    scene->addWidget(scoreTitle);

    for(int n=0;n<7;n++) packedRack[n] = PackTile();
}

/**
 * @brief setNicknames Sets the nicknames of the players in the window.
 * @param nicknames Nicknames of all players.
 */
void Rack::setNicknames(std::string nicknames[4])
{
    QFont font2;
    font2.setWeight(QFont::DemiBold);
    font2.setPixelSize(20);

    for(int n=0;n<4;n++){

        if(nicknames[n]!=""){
            QLabel *name = new QLabel(window);
            name->setGeometry(QRect(691,201+n*50,119,40));
            name->setText(QString::fromStdString(nicknames[n]));
            name->setAlignment(Qt::AlignLeft);
            name->setFont(font2);
            name->setStyleSheet("QLabel {color:white;}");
            this->user_score[n][0] = name;

            QLabel *score = new QLabel(window);
            score->setGeometry(QRect(816,201+n*50,119,40));
            score->setText("0");
            score->setAlignment(Qt::AlignLeft);
            score->setFont(font2);
            score->setStyleSheet("QLabel {color:white;}");
            this->user_score[n][1] = score;

            scene->addWidget(name);
            scene->addWidget(score);
        }
    }
}

/**
 * @brief Verifies that the positioning of the tiles in the game board is valid,
 *        if it is, sends the move's tiles to the server for logic processing.
 */
void Rack::scrabble(){
    bool firstTurn= true;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(this->lockedGridSlots[i][j]) firstTurn=false;
        }
    }

    bool includeCenter = false;
    for(int n=0; n<7;n++){
        Gtile *tile = rackTiles[n];
        if(tile!=nullptr){
            if(tile->gridX()==7 && tile->gridY()==7){
                includeCenter = true;
            }
        }
    }

    if(firstTurn && !includeCenter){
        clear();
        QMessageBox::information(window, "Invalid Move.", "The central tile of the gameboard (dark grey) have to be used in the first word created. Please include it.");
    }else{

        setPackedRack();

        int validMove = connector->verifyMove(this->packedRack);

        if(validMove == 0){
            clear();
            QMessageBox::information(window, "Invalid Word.", "The move given doesn't correspond to a valid word in the dictionary. Try again, swapp your tiles or pass your turn.");
        }else{
            this->registerMove();
            this->setTurn(false);
            this->user_score[0][1]->setText(QString::fromStdString(std::to_string(validMove)));


        }
    }
}

/**
 * @brief Moves all the tiles that where position in the game board in the
 *        current turn back to their initial position in the rack.
 *
 */
void Rack::clear(){
    for(int n=0; n<7;n++){
        Gtile *tile = rackTiles[n];
        if(tile!=nullptr){
            tile->setPos(tile->getInitialAnchorPoint());
            tile->setAnchorPoint(tile->getInitialAnchorPoint());
            tile->resetGridPos();
        }
    }
}

/**
 * @brief Changes all the current tiles in the rack for others. It gets them
 *        by making a request to the server.
 */
void Rack::swapp(){
    clear();
    requestTiles("swapp");
    this->setTurn(false);
}

/**
 * @brief Informs to the server that the player
 *        wants to skip his turn.
 */
void Rack::pass()
{
    this->setTurn(true);
}

/**
 * @brief Checks the data of all placed tiles to verify if there
 *        is any kind of tile overlapping in the game board. Returns
 *        a empty string if there is no overlaping.
 * @return std::string Type of overlaped detected.
 */
std::string Rack::verifyMove()
{
    std::string exception = "";

    for(int i = 0; i<7; i++){
        Gtile* tile1 = rackTiles[i];

        if(tile1 != nullptr){
            if(tile1->gridX()!=-1){
                if(this->lockedGridSlots[tile1->gridY()][tile1->gridX()])exception = "inLockedSlot";

                for(int j = i+1; j<7; j++){
                    Gtile* tile2 = rackTiles[j];
                    if(tile2 != nullptr){
                        if(tile2->gridX()!=-1){
                            if((tile1->gridX() == tile2->gridX()) & (tile1->gridY() == tile2->gridY()))
                                exception="overlaping";
                        }
                    }
                }
            }
        }
    }
    return exception;
}

/**
 * @brief Sets if the player is on turn or not.
 * @param inTurn New state of player's turn.
 */
void Rack::setTurn(bool inturn)
{
    this->inturn = inturn;
    if(inturn){
        QMessageBox::information(window, "Turn.", "It's your turn.");
    }else{
        QMessageBox::information(window, "Turn.", "It's not your turn. Please wait for the other players to finish their move.");
    }
}

/**
 * @brief Returns if the player is on turn or not.
 * @return bool State of player's turn.
 */
bool Rack::inTurn()
{
    return this->inturn;
}

/**
 * @brief Registers and draws a move constisting in a group
 *        of tiles to the gameboard.
 * @param move[] Array of tiles.
 */
void Rack::registerMove()
{
    Gtile *unplacedTiles[7];

    for(int n=0;n<7;n++)unplacedTiles[n]=nullptr;
    int unplacedIndex = 0;

    for(int n=0; n<7;n++){
        Gtile *tile = this->rackTiles[n];

        if(tile != nullptr){
            if(tile->gridX() == -1){
                unplacedTiles[unplacedIndex]=tile;
                unplacedIndex++;
            }else{
                this->lockedGridSlots[tile->gridY()][tile->gridX()]=true;
                tile->deactivate();
            }
            rackTiles[n]= nullptr;
        }
    }
    for(int n=0;n<7;n++)this->rackTiles[n]=unplacedTiles[n];
    updateTiles();
}

/**
 * @brief Registers and draws the current word in the gameboard.
 */
void Rack::registerMove(PackTile* move)
{
    for(int n=0;n<7;n++){
        PackTile ptile = *(move+n);
        if(ptile.getValue() != -1){
            Gtile* gtile = getGtile(ptile,true);
            gtile->setPos(QPointF((int)(gtile->gridX()*40),(int)(gtile->gridY()*40)));

            this->lockedGridSlots[gtile->gridY()][gtile->gridX()]=true;
            gtile->deactivate();

            this->scene->addItem(gtile);
        }
    }
}

/**
 * @brief setConnector Sets the interface used for server communication.
 * @param connector Interface used for server communication.
 */
void Rack::setConnector(Connector *connector)
{
    this->connector = connector;
    requestTiles("emptyStack");
}

/**
 * @brief setUserNickname Sets the nickname of the user.
 * @param nickname User's nickname.
 */
void Rack::setUserNickname(std::string nickname)
{
    this->userNickname=nickname;
}

/**
 * @brief Updates all the tiles in the stack.
 * Used after a move is done and tiles are lock
 * into the gameboard
 */
void Rack::updateTiles()
{
    for(int n=0; n<7;n++){
        Gtile *tile = rackTiles[n];
        if(tile!=nullptr){
            tile->setPos(rackPositions[n]);
            tile->setInitialAnchorPoint(rackPositions[n]);
            tile->setAnchorPoint(rackPositions[n]);
            this->scene->addItem(tile);
        }

    }

    int size=0;
    for(int n=0;n<7;n++)
        if(rackTiles[n]!=nullptr)size++;

    this->rackSize=size;
}

/**
 * @brief Sets all the tiles placed in the grid
 *        into the class member tempPackage.
 */
void Rack::setPackedRack()
{
    for(int n=0;n<7;n++) this->packedRack[n] = PackTile();

    int index=0;
    for(int n=0;n<7;n++){
        Gtile *tile = this->rackTiles[n];

        if(tile != nullptr){
            if(tile->gridX() != -1){

            this->packedRack[index] = *(getPackTile(tile));
            index++;
            }
        }
    }
}

/**
 * @brief Transform a PackTile into Gtile.
 *        Used for server communication.
 * @param packTile An instance of PackTile.
 * @param placed Indicates if the PackTile has registered grid coordinates.
 * @return Gtile A Gtile version of the PackTile.
 */
Gtile* Rack::getGtile(PackTile tilePackage, bool placed)
{
    if(tilePackage.getValue() == -1){
        return nullptr;
    }else{
        Gtile *gtile = new Gtile();
        gtile->setData(tilePackage.getLetter(),tilePackage.getValue());
        gtile->setParent(window);
        if(placed)
            gtile->setGridPos(tilePackage.getColumn(),tilePackage.getRow());
        return gtile;
    }
}

/**
 * @brief Transform a Gtile into a PackTile.
 *        Used for server communication.
 *        This transformation doesn't manages the grid position.
 * @param gtile An instance of GTile.
 * @return PackTile A PackTile version of the Gtile.
 */
PackTile *Rack::getPackTile(Gtile *gtile)
{
    PackTile *ptile = new PackTile(gtile->getLetter(),gtile->getValue());
    return ptile;
}

/**
 * @brief Transform a Gtile into a PackTile.
 *        Used for server communication.
 *        This transformation manages the grid position.
 * @param gtile An instance of GTile.
 * @param gridY Tile's Y grid position.
 * @param gridX Tile's X grid position.
 * @return PackTile A PackTile version of the Gtile.
 */
PackTile *Rack::getPackTile(Gtile *gtile, int gridY, int gridX)
{
    PackTile *ptile = new PackTile(gridY,gridX,gtile->getLetter(),gtile->getValue());
    return ptile;
}

/**
 * @brief requestTiles Ask to the server for tiles. Used when restocking or swapping happens.
 * @param option Option used to ask tiles. Swapping or restock are expected.
 */
void Rack::requestTiles(std::string option)
{
    this->setPackedRack();

    PackTile *newTiles;

    if(option == "swapp"){

        newTiles = connector->getTiles(this->rackSize,this->packedRack);

    }else{
        newTiles = connector->getTiles(7,this->packedRack);
    }

    for(int n=0;n<7;n++)
        if(rackTiles[n]!=nullptr)scene->removeItem(rackTiles[n]);

    this->setRackTiles(newTiles);
    this->updateTiles();
}

/**
 * @brief setRackTiles Sets a group of PackTiles to the tiles of the rack.
 * @param rackTiles Group of PackTiles.
 */
void Rack::setRackTiles(PackTile *tiles)
{
    for(int n=0;n<7;n++){
        PackTile ptile = *(tiles+n);

        Gtile* gtile = this->getGtile(ptile,false);

        if(gtile != nullptr){
            gtile->setPos(rackPositions[n]);
            gtile->setInitialAnchorPoint(rackPositions[n]);
            gtile->setAnchorPoint(rackPositions[n]);
        }

        this->rackTiles[n] = gtile;
    }
}
