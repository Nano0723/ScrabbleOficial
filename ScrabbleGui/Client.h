#ifndef CLIENT_H
#define CLIENT_H

class Client {
public:
    bool connected;
    void connect1();
    void recieveMessage();
    void sendMessage();
    static Client* getIntance();
    void thSM();
    void thRM();


private:
    Client();
    static Client* instance;

};

#endif // CLIENT_H
