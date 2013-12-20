#ifndef VECTOR_H__
#define VECTOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct vector_ {
    void** data;
    int size;
    int count;
} vector;

vector* vector_new();
void vector_free(vector *v);

void vector_init(vector*);
int  vector_count(vector*);
void vector_add(vector*, void*);
void vector_set(vector*, int, void*);
void *vector_get(vector*, int);
void vector_delete(vector*, int);
void vector_data_free(vector*);

#endif
