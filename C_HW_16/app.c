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
        }
    }
}

