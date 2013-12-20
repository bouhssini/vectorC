#ifndef CLIENTS_H
#define CLIENTS_H

#include "cstring.h"

typedef struct clients_ {
    bool isNull;
    int  id;
    bool sWait;
    bool sCon;
    int  state;
    int  sNet;
    int  sPort;
    int  RemotePort;
    int  sPacket;
    int  server;
    int  channel;

    cstring *mount;
    cstring *head;
    cstring *skey;
    cstring *RemoteIP;
    cstring *addressIP;
    cstring *nickname;
    cstring *sByte;
} clients;

clients * client_new();
void client_free(clients*);
/*---------------------------------------------------------------*/
void client_init(clients*);
void client_data_free(clients*);
/*----------------------[cstr_vector]----------------------------*/
void client_vector_delete(vector*, int);
void client_vector_data_free(vector*);
void client_vector_set(vector*, int, void*);
/*----------------------[cstr_vector]----------------------------*/

#endif // CLIENTS_H
