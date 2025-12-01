#include <stdio.h>   
#include <stdlib.h>  
#include <locale.h>  
#include <time.h>
#include "array.h"

#define SIZE 100

int main() {
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    puts("Лабораторные работы 11, 14, 16: Работа с массивами ===\n");

    int size;
    puts("Укажите размер массива");
    scanf("%d", &size);

    puts("\nЛабораторная работа 11");
    printf("Сумма индексов элементов, равных введенному A: %d\n", task11(size));

    puts("\nЛабораторная работа 14");
    printf("Количество изменений знака: %d\n", task14(size));

    puts("\nЛабораторная работа 16");
    task16(size);

    return 0;
}

int task11(int size) {
    int sum = 0;
    double A = 0;
    double* ptr_array = (double*)malloc(size * sizeof(double));

    printf("Введите %d целых чисел (положительных и отрицательных):\n", size);
    for (int i = 0; i < size; i++) 
        scanf("%lf", &ptr_array[i]);

    printf("Введите число A: ");
    scanf("%lf", &A);

    for (int i = 0; i < size; i++) 
        if (are_equal(ptr_array[i], A)) 
            sum += i;

    return sum;
}

int task14(int size) {

    double array[SIZE];

    // Задание 1. Заполнение массива

    full_elements(array, size);
    put_elements(array, size);

    // Задание 2. Преобразование массива

    calc_elements(array, size);
    put_elements(array, size);

    // Задание 3. Индивидуальное задание (дз)
    return countSignChanges(array, size);
}

int task16(int size) {
    double* ptr_array;

    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }

    int choice = -1;
    puts("1) Обработка элементов массива");
    puts("2) Печать массива");
    puts("3) Удалить элемент функци");
    puts("4) Вставить `-999` в массив");
    puts("5) Выполнение домашнего задания");

    full_elements(ptr_array, size);

    while (choice != 0) {
        puts("Введите действие: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Результат обработки массива: \n");
                put_elements(calc_elements(ptr_array, size), 1);
                break;
            case 2:
                put_elements(ptr_array, size);
                break;
            case 3:
                printf("Введите индекс для удаления: ");
                int k;
                scanf("%d", &k);

                double* new_array = delete_k(ptr_array, size, k);
                ptr_array = new_array;
                size--;
                break;
            case 4:
                puts("Эллемент вставлен");
                double* new_array2 = insert(ptr_array, size);
                ptr_array = new_array2;
                size += 1;
                break;
            case 5: {
                int nD = 0;
                int nA = 10 + rand() % 41;
                int nB = 10 + rand() % 41;
                int nC = 10 + rand() % 41;

                double* A = (double*)malloc(nA * sizeof(double));
                double* B = (double*)malloc(nB * sizeof(double));
                double* C = (double*)malloc(nC * sizeof(double));

                full_elements(A, nA);
                full_elements(B, nB);
                full_elements(C, nC);

                printf("Массив A (%d элементов):\n", nA);
                put_elements(A, nA);

                printf("Массив B (%d элементов):\n", nB);
                put_elements(B, nB);

                printf("Массив C (%d элементов):\n", nC);
                put_elements(C, nC);

                double* D = make_new_array(A, nA, B, nB, C, nC, &nD);

                if (D == NULL) {
                    printf("\nМассив D пуст.\n");
                }
                else {
                    printf("\nМассив D (%d элементов):\n", nD);
                    put_elements(D, nD);
                }

                free(D);
                break;
            }
        }
    }
}

