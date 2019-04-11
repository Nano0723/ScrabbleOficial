#include "PackTile.h"

/**
 * The constructor for creating an 'empty'PackTile
 */
PackTile::PackTile() {
    this->row = -1;
    this->column = -1;
    this->letter = '.';
    this->value = -1;

}

/**
 * The constructor for creating a complete PackTile, all of its attributes are set.
 * @param i row
 * @param j column
 * @param l letter
 * @param v value/points
 */
PackTile::PackTile(int i,int j,char l,int v) {
    this->row = i;
    this->column = j;
    this->letter = l;
    this->value = v;
}

/**
 * The simple constructor for PackTile, no coordinates are set only the letter and the value/points.
 * @param l letter
 * @param v value/points
 */
PackTile::PackTile(char l, int v) {
    this->letter = l;
    this->value = v;
}

/**
 * Gets the letter of in a PackTile.
 * @return the letter in PacTile
 */
char PackTile::getLetter() const {
    return this->letter;
}

/**
 * Gets the row of in a PackTile.
 * @return the row in PacTile
 */
int PackTile::getRow() const {
    return this->row;
}

/**
 * Gets the column of in a PackTile.
 * @return the column in PacTile
 */
int PackTile::getColumn() const {
    return this->column;
}

/**
 * Gets the value/points of in a PackTile.
 * @return the value/points in PacTile
 */
int PackTile::getValue() const {
    return this->value;
}
