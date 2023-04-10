//
// Created by artem on 10.04.2023.
//

#ifndef UNTITLED19_VECTORVOID_H
#define UNTITLED19_VECTORVOID_H

#include <stdio.h>
#include <limits.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef struct vectorVoid {
    void *data;             // указатель на нулевой элемент вектора
    size_t size;            // размер вектора
    size_t capacity;        // вместимость вектора
    size_t baseTypeSize;    // размер базового типа:
    // например, если вектор хранит int -
    // то поле baseTypeSize = sizeof(int)
    // если вектор хранит float -
    // то поле baseTypeSize = sizeof(float)
} vectorVoid;

vectorVoid createVectorV(const size_t n, const size_t baseTypeSize);

void reserveV(vectorVoid *v, const size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);

#endif
