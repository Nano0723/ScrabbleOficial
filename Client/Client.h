//
// Created by kei98 on 09/04/19.
//

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H


class Client {
public:
    bool connect1();
    void recieveMessage();
    void sendMessage();
    static Client* getIntance();


private:
    Client();
    static Client* instance;

};


#endif //CLIENT_CLIENT_H
