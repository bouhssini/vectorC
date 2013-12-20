#ifndef CSTRING_H
#define CSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

#define maxstr 1024    //1 kb
#define true 1
#define false 0
typedef int bool;

typedef struct cstring_ {
    char* data;
    int   size;
    int   max;
} cstring;

void cstr_init(cstring*);
void cstr_data_free(cstring*);
void cstr_add(cstring*, char*);
void cstr_add_l(cstring*, char*,int);
void cstr_add_c(cstring*,cstring*);
void cstr_set(cstring*, char*);
void cstr_set_l(cstring*, char*,int);
void cstr_set_c(cstring*,cstring*);
void cstr_mid(cstring*,int,int);
void cstr_mid_d(cstring*,int);
int  cstr_find(cstring*,int,char*);
int  cstr_find_l(cstring*,int,char*,int);
int  cstr_find_c(cstring*,int,cstring*);
void cstr_replace_c(cstring*,cstring*,cstring*);
void cstr_replace(cstring*,char*,char*);
void cstr_replace_l(cstring*,char*,int,char*,int);
void cstr_split_c(cstring*,cstring*,vector*);
void cstr_split_l(cstring*,char*,int,vector*);
void cstr_split(cstring*,char*,vector*);
int  cstr_split_count(cstring*,char*);
int  cstr_split_count_c(cstring*,cstring*);
int  cstr_split_count_l(cstring*,char*,int);

cstring* cstr_new();
void cstr_free(cstring*);
void cstr_vector_delete(vector*, int);
void cstr_vector_data_free(vector*);
void cstr_vector_set(vector*, int, void*);

#endif // CSTRING_H
