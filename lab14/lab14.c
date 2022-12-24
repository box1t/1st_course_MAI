#include <stdio.h>

#define MAX_N 7

typedef enum _type_direction // объявим перечислимый тип состояний, как в 11 лабе
{
	LEFT = 0,
	UP,
	RIGHT,
	DOWN
} type_direction;

int main()
{
	// в теле функции задали постоянный размер матрицы, ввели используемые переменные
	int square_size, matrix[MAX_N][MAX_N], i, j, k, leftIndex, rightIndex, upIndex, downIndex;
	type_direction dir;

	// 1 - булевское значение. 'пока истина', т.е. пока программа не завершена, выполняем цикл
	while (1)
	{
		printf("\nPrint square size here (1 - %d. Break - 0): ", MAX_N);
		scanf("%d", &square_size);

		if (square_size == 0){
            break;
		}

		if (square_size < 1 || square_size > MAX_N){
			printf("\nRestricted value of size!\n");
			continue;
		}

		// поэлементно заполним матрицу нашими значениями
		for (i = 0; i < square_size; i++){
			for (j = 0; j < square_size; j++){
				scanf("%d", &matrix[i][j]);
			}
		}

		// выведем поэлементно нашу матрицу на экране
		printf("Input matrix:\n");
		for (i = 0; i < square_size; i++){
			for (j = 0; j < square_size; j++){
                printf("%d ", matrix[i][j]);
                }
			printf("\n"); // выводим символ новой строки в конце первого цикла
		}

// по условию варианта направление обхода начинается из правого нижнего угла, затем влево и по краю в улиточной форме идёт вовнутрь

		dir = LEFT;
		leftIndex = 0; // верхний левый индекс зануляем
		rightIndex = square_size - 1; // правый индекс будет меньше, чем размер матрицы, на 1 (счет здесь от нуля)
		upIndex = 0;
		downIndex = square_size - 1;
		i = square_size - 1;
		j = square_size - 1;

		// выведем линейный вид матрицы
		printf("Linear form: ");
		for (k = 0; k < square_size * square_size; k++) {
			printf("%d ", matrix[i][j]);

			// дальше идут условия, когда меняем направление при обходе матрицы
			switch (dir){

				case LEFT:
				{
					if (j > leftIndex) {
                        j--;
					}
					else
					{
						i--;
						downIndex--;
						dir = UP;
					}
				}
				break;

				case UP:
				{
					if (i > upIndex){
                        i--;
					}
					else
					{
						j++;
						leftIndex++;
						dir = RIGHT;
					}
				}
				break;

				case RIGHT:
				{
					if (j < rightIndex){
                        j++;
					}
					else
					{
						i++;
						upIndex++;
						dir = DOWN;
					}
				}
				break;

				case DOWN:
				{
					if (i < downIndex){
                        i++;
					}
					else
					{
						j--;
						rightIndex--;
						dir = LEFT;
					}
				}
				break;
			}
		}

		printf("\n");
	}

	return 0;
}
