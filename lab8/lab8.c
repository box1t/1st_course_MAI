#include <stdio.h>

int main() {

    int kolvo = 0; 
    int chislo = 0; 
    int kolvo62 = 0;
    int numb62 = 0;
    int numb31 = 0;
    int numb2 = 0;
    int numb0 = 0;
    int i = 0;

    scanf("%d", &kolvo);

    for (int i = 0; i < kolvo; ++i) {
        scanf("%d", &chislo);
        if (chislo % 62 == 0) {
            numb62 += 1;
            }
            else if (chislo % 31== 0) {
                    numb31 += 1;
            }
            else if (chislo % 2 == 0) {
                    numb2 += 1;
            }
            else {
                numb0 += 1;
            }
    }
    kolvo62 = numb62 * numb0 + numb31 * numb2 + numb62*numb31 + numb62*numb2 + (numb62 * (numb62 - 1) ) ;
            printf("%d", kolvo62);
}



