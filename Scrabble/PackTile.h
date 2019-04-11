#ifndef QUEUE_USING_OOP_PACKTILE_H
#define QUEUE_USING_OOP_PACKTILE_H

/**
 * Pack tile is simpler way to represent a tile  used for communication, it is send between server and client
 */
class PackTile {
private:

    char letter; /**< Tile's letter. */

    int row; /**< Tile's row position. */

    int column; /**< Tile's column position. */

    int value; /**< Tile's value. */

public:
    /**
     * The constructor for creating an 'empty'PackTile
     */
    PackTile();

    /**
     * The constructor for creating a complete PackTile, all of its attributes are set.
     * @param i row
     * @param j column
     * @param l letter
     * @param v value/points
     */
    PackTile(int row,int column,char letter,int points);

    /**
     * The simple constructor for PackTile, no coordinates are set only the letter and the value/points.
     * @param l letter
     * @param v value/points
     */
    PackTile(char letter,int points);

    /**
     * Gets the letter of in a PackTile.
     * @return the letter in PacTile
     */
    char getLetter() const;

    /**
     * Gets the row of in a PackTile.
     * @return the row in PacTile
     */
    int getRow() const;

    /**
     * Gets the column of in a PackTile.
     * @return the column in PacTile
     */
    int getColumn() const;

    /**
     * Gets the value/points of in a PackTile.
     * @return the value/points in PacTile
     */
    int getValue() const;
};

#endif //QUEUE_USING_OOP_PACKTILE_H
