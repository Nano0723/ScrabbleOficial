//
// Created by kei98 on 09/04/19.
//

#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "Client.h"

#define PORT 8080

struct sockaddr_in address;
int sock = 0, valread;
struct sockaddr_in serv_addr;
char *hello = "Hello from client";
char buffer[1024] = {0};

void Client::recieveMessage() {
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
}

void Client::sendMessage() {
    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");

}

Client *Client::getIntance() {
    if(instance == 0){
        instance = new Client();

    }else{

    }
}

Client::Client() {

}

Client* Client:: instance = 0;

bool Client::connect1() {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return false;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return false;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return false;
    }


}
