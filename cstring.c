#include "cstring.h"

cstring * cstr_new()
{
    cstring *st;
    st = malloc(sizeof(cstring));
    cstr_init(st);
    return st;
}
void cstr_free(cstring *c )
{
    cstr_data_free(c);
    free(c);
    //cstr_init(c);
}

/*----------------------[cstr_vector]----------------------------*/
void cstr_vector_delete(vector *v, int index)
{
    cstring *s = vector_get(v, index);
    cstr_free(s);
    vector_delete(v, index);
}
void cstr_vector_data_free(vector*v)
{
    int i;
	cstring *s;
    for (i = 0; i < vector_count(v); i++){
        s = vector_get(v, i);
        cstr_free(s);
    }
    vector_data_free(v);
}
void cstr_vector_set(vector *v, int index, void *e)
{
	cstring *s;
    if (index >= v->count) return;
    s = vector_get(v, index);
    cstr_free(s);
    vector_set(v,index,e);
}
/*----------------------[cstr_vector]----------------------------*/

void cstr_init(cstring *c)
{
    c->data = NULL;
    c->max = 0;
    c->size = 0;
}
void cstr_data_free(cstring *c )
{
    if (c->max > 0)
    {
        free(c->data);
    }
    c->max = 0;
    c->size = 0;
}

void cstr_add(cstring *c, char *e)
{
    cstr_add_l(c,e,strlen(e));
}
void cstr_add_c(cstring *c,cstring *c2)
{
    cstr_add_l(c,c2->data,c2->size);
}
void cstr_add_l(cstring *c, char *e,int len)
{
    if(len < 1) return;
    if (c->max == 0) {
        if (len < maxstr)
           c->max = maxstr;
        else
           c->max = len;

        c->data = (char *)malloc(c->max);
        memset(c->data, '\0', c->max);
    }

    if (c->max < c->size + len) {
        if (len < maxstr)
           c->max += maxstr;
        else
           c->max += len;

        c->data = (char*)realloc(c->data, c->max);
    }
    memmove (c->data+c->size,e+0,len);
    c->size+=len;
}

void cstr_set(cstring*c,char*e)
{
    cstr_set_l(c,e,strlen(e));
}
void cstr_set_c(cstring*c,cstring*c2)
{
    cstr_set_l(c,c2->data,c2->size);
}
void cstr_set_l(cstring*c,char*e,int len)
{
    char *data = (char *)malloc(len);
    memset(data, '\0', len);
    memcpy(data,e,len);

    cstr_data_free(c);
    cstr_add_l(c,data,len);
    free(data);
}

void cstr_mid(cstring*c,int pos,int len)
{
    cstr_set_l(c,c->data+pos,len);
}
void cstr_mid_d(cstring*c,int pos)
{
    int len = c->size - pos;
    cstr_mid(c,pos,len);
}

int cstr_find(cstring*c,int pos,char*txt)
{
    return cstr_find_l(c,pos,txt,strlen(txt));
}
int cstr_find_c(cstring*c,int pos,cstring*c2)
{
    return cstr_find_l(c,pos,c2->data,c2->size);
}
int cstr_find_l(cstring*c,int pos,char*txt,int len)
{
    int i,j,n;
    bool t;
    for (i = pos; i< c->size; i++)
    {
        n = i;
        for(j = 0;j< len;j++)
        {
            if(n > c->size-1) return -1;
            if (c->data[n] == txt[j]){
                t = true;
                n++;
                continue;
            }else{
                t = false;
                break;
            }
        }
        if (t) return i;
    }
    return -1;
}

void cstr_replace(cstring*c,char*data,char*data2)
{
    cstr_replace_l(c,data,strlen(data),data2,strlen(data2));
}
void cstr_replace_c(cstring*c,cstring*c2,cstring*c3)
{
    cstr_replace_l(c,c2->data,c2->size,c3->data,c3->size);
}
void cstr_replace_l(cstring*c,char*data,int size,char*data2,int size2)
{
    int n,len;
    cstring tx;
    cstr_init(&tx);
    while(1){
        n = cstr_find_l(c,0,data,size);
        if (n > -1){
            cstr_add_l(&tx,c->data,n);
            cstr_add_l(&tx,data2,size2);
            len = n+size;
            cstr_add_l(&tx,c->data+len,c->size-len);
            cstr_set_c(c,&tx);
            cstr_data_free(&tx);
        }else
            break;
    }
}

void cstr_split(cstring*c,char*data,vector *v)
{
    cstr_split_l(c,data,strlen(data),v);
}
void cstr_split_c(cstring*c,cstring*c2,vector *v)
{
    cstr_split_l(c,c2->data,c2->size,v);
}
void cstr_split_l(cstring*c,char*data,int size,vector *v)
{
    int n,len=0;
    cstring *st,*tx;

    tx = cstr_new();
    cstr_set_c(tx,c);

    while(1){
        n = cstr_find_l(tx,0,data,size);
/*
         if (n == 0){
            len = n+size;
            cstr_set_l(tx,tx->data+len,tx->size-len);
            continue;
        }else if (n > -1){
*/
        if (n > -1){
            st = cstr_new();
            cstr_add_l(st,tx->data,n);
            vector_add(v,st);
            len = n+size;
            cstr_set_l(tx,tx->data+len,tx->size-len);
        }else{
            st = cstr_new();
            cstr_add_l(st,tx->data,tx->size);
            vector_add(v,st);
            break;
        }
    }
    cstr_free(tx);
}

int cstr_split_count(cstring*c,char*data)
{
    return cstr_split_count_l(c,data,strlen(data));
}
int cstr_split_count_c(cstring*c,cstring*c2)
{
    return cstr_split_count_l(c,c2->data,c2->size);
}
int cstr_split_count_l(cstring*c,char*data,int size)
{
    int n,len=0,cnt=0;
    cstring *tx;

    tx = cstr_new();
    cstr_set_c(tx,c);

    while(1){
        cnt++;
        n = cstr_find_l(tx,0,data,size);
        if (n > -1){
            len = n+size;
            cstr_set_l(tx,tx->data+len,tx->size-len);
        }else
            break;
    }
    cstr_free(tx);
    return cnt;
}

