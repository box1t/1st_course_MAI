#include <stdio.h>

void convert_to_binary(int number)
{
    int j;
    for(int i = 31; i >= 0; i--) // так как знак нестрогий, получается 32 разряд числа
                                // т.е. восьмибитное представление в условных границах (-2 147 483 648;2 147 483 647)
    {
        j = number >> i; // делаем битовый сдвиг вправо, и так для каждого разряда в цикле.
        
        if(j & 1) // конъюнкция разряда сравнивает с 1 или 0
            printf("1");
        else
            printf("0");
    }
} // когда сдвинутся все разряды, получится 'негативная' форма, или дополнительный код

int main() {
    while (1) {
        
        int number;
        
        printf("\nEnter the number to convert or 404 to end:  ");
        scanf("%d", &number);
        
        if (number == 404){
            break;
		}
        
        if (number < -2147483648 || number > 2147483647){
			printf("\nRestricted value of size! Use between (-2147483648; 2147483647)\n");
			continue;
		}
        
        convert_to_binary(number); 
                
    }
    return 0;
}
