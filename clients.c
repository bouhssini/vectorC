#include "clients.h"

clients * client_new()
{
    clients *c = malloc(sizeof(clients));
    client_init(c);
    return c;
}
void client_free(clients *c )
{
    if (c == NULL) return;
    if (c->isNull==false)
    {
        client_data_free(c);
    }
    free(c);
    c = NULL;
}

void client_init(clients*c)
{
    c->isNull     = false;
    c->id         = -1;
    c->sWait      = false;
    c->sCon       = false;
    c->state      = 0;
    c->sNet       = 0;
    c->sPort      = 0;
    c->RemotePort = 0;
    c->sPacket    = 0;
    c->server     = 0;
    c->channel    = 0;

    c->mount = cstr_new();
    c->head = cstr_new();
    c->skey = cstr_new();
    c->RemoteIP = cstr_new();
    c->addressIP = cstr_new();
    c->nickname = cstr_new();
    c->sByte = cstr_new();
}

void client_data_free(clients *c)
{
    c->isNull     = true;
    c->id         = -1;
    c->sWait      = false;
    c->sCon       = false;
    c->state      = 0;
    c->sNet       = 0;
    c->sPort      = 0;
    c->RemotePort = 0;
    c->sPacket    = 0;
    c->server     = 0;
    c->channel    = 0;

    cstr_free(c->mount);
    cstr_free(c->head);
    cstr_free(c->skey);
    cstr_free(c->RemoteIP);
    cstr_free(c->addressIP);
    cstr_free(c->nickname);
    cstr_free(c->sByte);
}

/*--------------------------[cstr_vector]----------------------------*/
void client_vector_delete(vector *v, int index)
{
    clients *s = vector_get(v, index);
    client_free(s);
    vector_delete(v, index);
}
void client_vector_data_free(vector*v)
{
    int i;
	clients *s;
    for (i = 0; i < vector_count(v); i++){
        s = vector_get(v, i);
        client_free(s);
    }
    vector_data_free(v);
}
void client_vector_set(vector *v, int index, void *e)
{
	clients *s;
    if (index >= v->count) return;
    s = vector_get(v, index);
    client_free(s);
    vector_set(v,index,e);
}
/*---------------------------[cstr_vector]----------------------------*/
