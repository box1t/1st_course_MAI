#include <stdio.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int sign(int a) {
    if (a < 0) {
        return -1;
    }
    if (a == 0) {
        return 0;
    } else {
        return 1;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int abs(int a){
    if (a > 0) {
        return a;
    } else {
        return -a;
    }
}

int main() {
    int k, i , j, l, i0, j0, l0;
    scanf("%d %d %d", &i0, &j0, &l0);
    for (k = 0; k < 50; k++) {
        i = abs(sign(i0 - j0) * l0 - sign(j0 - l0) * i0 + (sign(i0 - l0) * j0 - k)) % 35;
        j = i0 * max(j0, l0) % 30 + j0 * min(i0, l0) % 20 - k;
        l = (i0 + k) * (j0 - k) * (l0 + k) % 25;

        if ((i-20) * (i-20) + 25 * j * j <= 100) {
            printf("Gothca!\n");
            printf("Iteration: %d\n", k);
            printf("Final coordinates: %d . %d\n", i, j);
            printf("Value of dynamic parameter motion: %d\n", l);
                return 0;
        }

    }
        printf("Unlucky man! Not this time!\n");
        printf("Iteration: %d\n", k);
        printf("Final coordinates: %d . %d\n", i, j);
        printf("Value of dynamic parameter motion: %d\n", l);
            return 0;

}


