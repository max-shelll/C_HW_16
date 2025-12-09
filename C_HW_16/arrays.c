#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"

double func(double x) {
    double i = -1 + x * 0.2;
    return i * i * i + 3 * i * i - 3;
}

double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = func(i);
    }

    return ptr_array;
}

int put_elements(double* ptr_array, int n) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        printf("%lf ", ptr_array[i]);
        counter++;
    }
    puts("");

    return counter;
}

int calc_elements(double* ptr_array, int n) {
    int res = 0;

    for (int i = 0; i < n; i += 2) {
        if (ptr_array[i] > 10) res++;
    }

    return res;
}

double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0;

    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }

    return sum;
}

int find_element(double* ptr_array, int n, double element) {

    for (int i = 0; i < n; i++) {
        if (are_equal(ptr_array[i], element))
            return i;
    }

    return -1;
}

int are_equal(double a, double b) {
    return fabs(a - b) < EPS;
}

double* delete_k(double* ptr_array, int k, int* size) {
    int new_size = *size - 1;
    double* new_array = (double*)malloc(new_size * sizeof(double));

    if (new_array == NULL) return ptr_array;

    for (int i = 0, j = 0; i < *size; i++) {
        if (i != k) {
            new_array[j] = ptr_array[i];
            j++;
        }
    }

    free(ptr_array);
    *size = new_size;
    return new_array;
}

double* insert(double* ptr_array, int* size) {
    int randIndex = rand() % (*size);

    int new_size = *size + 1;
    double* new_array = (double*)realloc(ptr_array, new_size * sizeof(double));
    if (new_array == NULL) return ptr_array;

    ptr_array = new_array;
    for (int i = new_size - 1; i > randIndex; i--) {
        ptr_array[i] = ptr_array[i - 1];
    }

    ptr_array[randIndex] = -999;
    *size = new_size;
    return ptr_array;
}

double* make_new_array(double* A, int nA, double* B, int nB, double* C, int nC, int* nD) {
    int maxSize = nA - 1;
    if (nB - 1 < maxSize) maxSize = nB - 1;
    if (nC - 2 < maxSize) maxSize = nC - 2;

    if (maxSize < 1) {
        return NULL;
    }

    int sizeD = maxSize;
    double* D = (double*)malloc(sizeD * sizeof(double));

    for (int i = 1; i <= maxSize; i++) {
        double a_val = A[i - 1];
        double b_val = B[i];
        double c_val = C[i + 1];

        double min = a_val;
        if (b_val < min) min = b_val;
        if (c_val < min) min = c_val;

        D[i - 1] = min;
    }

    *nD = sizeD;
    return D;
}

int countSignChanges(double* ptr_array, int n) {
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        double first = ptr_array[i];
        double second = ptr_array[i + 1];

        if (first > 0 && second < 0) count++;
        else if (first < 0 && second > 0) count++;
    }

    return count;
}