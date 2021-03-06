#include "cstring.h"
#include "clients.h"

void test_vector();
void test_cstring();
void test_client();

int main(void)
{
    cstring *a,*b,c,d;
    a = cstr_new();
    b = cstr_new();
    cstr_init(&c);
    cstr_init(&d);

    cstr_add(a,"aaaa");
    cstr_add(b,"bbbb");
    cstr_add(&c,"cccc");
    cstr_add(&d,"dddd");

    cstr_data_free(&c);
    cstr_data_free(&d);
    cstr_free(a);
    cstr_free(b);

    return 0;
}
void test_client()
{
    vector v;
    clients *cls;
    int i;

    vector_init(&v);

    cls = client_new();
    cstr_add(cls->addressIP,"81.19.200.15");
    vector_add(&v,cls);

    cls = client_new();
    cstr_add(cls->addressIP,"40.192.30.105");
    vector_add(&v,cls);


    cls = client_new();
    cstr_add(cls->addressIP,"140.12.30.105");
    vector_add(&v,cls);

    cls = client_new();
    cstr_add(cls->addressIP,"30.92.130.255");
    vector_add(&v,cls);

    printf("\nfirst round:\n");

    for (i = 0; i < vector_count(&v); i++) {
        clients *s;
        s = vector_get(&v, i);
        printf("vector %s\n", s->addressIP->data);
    }
    client_vector_delete(&v, 1);
    client_vector_delete(&v, 2);

    printf("\nsecond round:\n");
    for (i = 0; i < vector_count(&v); i++) {
        clients *s;
        s = vector_get(&v, i);
        printf("vector %s\n", s->addressIP->data);
    }
    client_vector_data_free(&v);
}
void test_cstring()
{
    int i;
    vector v;
    cstring *st;

    st = cstr_new();

    cstr_init(st);
    cstr_add(st,"youssef");
    cstr_set(st,"bouhssini");
    cstr_mid(st,2,4);
    cstr_set(st,"bouhssini");
    cstr_add(st,"youssef");

    i=cstr_find(st,0,"ss");
    i=cstr_find(st,i+1,"ss");
    cstr_replace(st,"iy","i y");

    vector_init(&v);
    cstr_set(st,"aa bb  cc");
    cstr_set(st,"");

    i = cstr_split_count(st," ");
    cstr_split(st," ",&v);
    cstr_vector_data_free(&v);

    cstr_free(st);
    //cstr_data_free(st);
    //free(st);
}
void test_vector()
{
    int i = 0;
    vector *v;
    cstring *s,*st;

    v = vector_new();
    //vector_init(v);
    st = cstr_new();
    cstr_add(st,"emil");vector_add(v,st);

    st = cstr_new();
    cstr_add(st,"hannes");vector_add(v,st);

    st = cstr_new();
    cstr_add(st,"lydia");vector_add(v,st);

    st = cstr_new();
    cstr_add(st,"olle");vector_add(v,st);

    st = cstr_new();
    cstr_add(st,"erik");vector_add(v,st);

    printf("\nfirst round:\n");
    for (i = 0; i < vector_count(v); i++) {
        s = vector_get(v, i);
        printf("vector %s\n", s->data);
    }
    cstr_vector_delete(v, 1);
    cstr_vector_delete(v, 3);

    printf("\nsecond round:\n");
    for (i = 0; i < vector_count(v); i++) {
        s = vector_get(v, i);
        printf("vector %s\n", s->data);
    }
    cstr_vector_data_free(v);
    vector_free(v);
}
