//
// Created by kei98 on 10/04/19.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include <vector>
#include <string>

using namespace std;
class Player {
public:
    int playerN;
    string name;
    vector<string> words;
    int points;
    Player(int, string);
};


#endif //SERVER_PLAYER_H
