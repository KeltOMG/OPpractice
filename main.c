#include"libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"


void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 42);
    assert(v.data[0] == 42);
    assert(v.capacity == 1);
    assert(v.size == 1);
    deleteVector(&v);
}
void test_pushBack_fullVector() {
    vector v = createVector(5);
    v.size = 5;
    v.data[0] = 1;
    v.data[1] = 2;
    v.data[2] = 3;
    v.data[3] = 4;
    v.data[4] = 5;
    pushBack(&v, 42);
    assert(v.data[5] == 42);
    assert(v.size == 6);
    assert(v.capacity == 10);
}
void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}
void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    v.size = 3;
    v.data[0] = 1;
    v.data[1] = 2;
    v.data[2] = 3;
    assert(*atVector(&v, 1) == 2);
}
void test_atVector_requestToLastElement() {
    vector v = createVector(5);
    v.size = 5;
    v.data[0] = 1;
    v.data[1] = 2;
    v.data[2] = 3;
    v.data[3] = 4;
    v.data[4] = 5;
    assert(*atVector(&v, v.size - 1) == 5);
}
void test_back_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    v.data[0] = 1;
    assert(*back(&v) == 1);
}
void test_front_oneElementInVector() {
    vector v = createVector(1);v.size = 1;
    v.data[0] = 1;
    assert(*front(&v) == 1);
}
void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}


int main() {
    vectorVoid vInt = (vectorVoid) {NULL, 0, 0, sizeof(int)};
    vectorVoid vFloat = (vectorVoid) {NULL, 0, 0, sizeof(float)};
    size_t n;
    scanf("%zd", &n);
    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);
        pushBackV(&v, &x);
    }
    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);
        printf("%f ", x);
    }
    test();
    return 0;
}

