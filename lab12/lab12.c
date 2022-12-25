#include <stdio.h>

void convert_to_binary(int number)
{
    int j;
    for(int i = 31; i >= 0; i--) // так как знак нестрогий, получается 8 разрядов числа
                                // т.е. восьмибитное представление в условных границах (-128;127)
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
        
        if (number < -32768 || number > 32767){
			printf("\nRestricted value of size! Use between (-32768; 32767)\n");
			continue;
		}
        
        convert_to_binary(number); 
                
    }
    return 0;
}
