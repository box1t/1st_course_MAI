/* Замена всех столбцов, содержащих минимальный элемент матрицы, на столбец с максимальным номером,
содержащий её максимальный элемент */

#include <stdio.h>
#include <limits.h>

#define MAX_N 7

int main() {

    int size;
    int matrix[MAX_N][MAX_N];

    // задаём первоначальные минимальные и максимальные элементы матрицы
    int min_matrix_elem = INT_MAX;
    int max_elem_i = -1;
    int max_elem_j = -1;
    int max_matrix_elem = INT_MIN;
    scanf("%d\n", &size); // задали размер матрицы

    // заполняем матрицу поэлементно
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // проходимся по всей матрице, чтобы найти номер наибольшего столбца
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (matrix[i][j] < min_matrix_elem) {
                min_matrix_elem = matrix[i][j];
            }
            if (matrix[i][j] >= max_matrix_elem) {
                max_matrix_elem = matrix[i][j];
                max_elem_i = i;
                max_elem_j = j;
            }
        }
    }
    // прогон по всему j-тому столбцу
    for (int j = 0; j < size; j++) { 
        int flag_is_here_min_elem = 0; 
        for (int i = 0; i < size; i++) { 
            if (matrix[i][j] == min_matrix_elem) { // если элемент является минимальным, присваиваем флагу 1
                flag_is_here_min_elem = 1;
                break;
            }
        }
        if (!flag_is_here_min_elem) {
            continue;
        }
        for (int i = 0; i < size; i++) {
            matrix[i][j] = matrix[i][max_elem_j];
        }
    }
    // вывод матрицы на экран
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
