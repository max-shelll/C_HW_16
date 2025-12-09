#ifndef ARRAYS_H
#define ARRAYS_H
#define EPS 1e-9

/**
 * Получение уникального значения
 * @param x изменяемый параметр
 * @return уникальное значение
 */
double func(double x);

/**
 * Заполнение массива значениями
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
double* full_elements(double* ptr_array, int n);

/**
 * Печать элементов массива
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return количество выведенных элементов
 */
int put_elements(double* ptr_array, int n);

/**
 * Обработка элементов массива согласно индивидуальному варианту
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return значения после обработки массива
 */
int calc_elements(double* ptr_array, int n);

/**
 * Вычисление суммы элементов массива в диапазоне [begin, end]
 * @param ptr_array указатель на массив
 * @param begin начальный индекс (включительно)
 * @param end конечный индекс (включительно)
 * @return сумма элементов
 */
double sum_elements(double* ptr_array, int begin, int end);

/**
 * Поиск элемента в массиве
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param element искомый элемент
 * @return индекс найденного элемента или -1 если не найден
 */
int find_element(double* ptr_array, int n, double element);

/**
 * Проверяет, равны ли два числа с учётом допуска EPS
 * Сравнение выполняется по условию: |a - b| < EPS
 * @param a первое число
 * @param b второе число
 * @return 1 - элементы равны, 0 - нет
 */
int are_equal(double a, double b);

/**
 * Удаление элемента из массива
 * @param ptr_array указатель на массив
 * @param k индекс удаляемого элемента
 * @param size указатель на размер массива
 * @return указатель на обработанный массив
 */
double* delete_k(double* ptr_array, int k, int* size);

/**
 * Вставка -999 в массив на рандомную позицию
 * @param ptr_array указатель на массив
 * @param size указатель на размер массива
 * @return указатель на обработанный массив
 */
double* insert(double* ptr_array, int* size);

/**
 * Формирует новый массив D по правилу: d_i = min(a_{i-1}, b_i, c_{i+1})
 * @param A указатель на массив A
 * @param nA размер массива A
 * @param B указатель на массив B
 * @param nB размер массива B
 * @param C указатель на массив C
 * @param nC размер массива C
 * @param nD размер полученного массива
 * @return указатель на новый массив
 */
double* make_new_array(double* A, int nA, double* B, int nB, double* C, int nC, int* nD);

/**
 * Подсчет количество изменений знака
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return количество изменений
 */
int countSignChanges(double* ptr_array, int n);

#endif