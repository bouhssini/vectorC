#include "vector.h"

vector* vector_new()
{
    vector *v = malloc(sizeof(vector));
    vector_init(v);
    return v;
}
void vector_free(vector *v)
{
    vector_data_free(v);
    free(v);
    v = NULL;
}
void vector_data_free(vector *v)
{
    if (v->count == 0) return;
    free(v->data);
    //v->data = NULL;
    v->size = 0;
    v->count = 0;
}
//-----------------------------------------------------------------------------------
void vector_init(vector *v)
{
    v->data = NULL;
    v->size = 0;
    v->count = 0;
}

int vector_count(vector *v)
{
    return v->count;
}

void vector_add(vector *v, void *e)
{
    if (v->size == 0) {
        v->size = 10;
        v->data = (void**)malloc(sizeof(void*) * v->size);

        memset(v->data, '\0', sizeof(void*) * v->size);
    }

    // condition to increase v->data:
    // last slot exhausted
    if (v->size == v->count) {
        v->size += 10;
        v->data = (void**)realloc(v->data, sizeof(void*) * v->size);
    }
    v->data[v->count] = e;
    v->count++;
}

void vector_set(vector *v, int index, void *e)
{
    if (index >= v->count) return;
    v->data[index] = e;
}

void *vector_get(vector *v, int index)
{
    if (index >= v->count)  return NULL;
    return v->data[index];
}

void vector_delete(vector *v, int index)
{
	int i, j;
	void **newarr;
    if (index >= v->count)  return;
    //v->data[index] = NULL;
    
    newarr = (void**)malloc(sizeof(void*) * v->count - 1);
    for (i = 0, j = 0; i < v->count; i++) {
        if (i != index) {
            newarr[j] = v->data[i];
            j++;
        }
    }
    free(v->data);
    v->data = newarr;
    v->count--;
}



