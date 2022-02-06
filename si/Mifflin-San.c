#include <stdio.h>

int main(void) {

    int age, height, weight;
    double bov_m, bov_f;
    char sex;
    scanf("%c%d%d%d", &sex, &age, &height, &weight);

    switch (sex) {
    case 'm':
        bov_m = 10 * weight + 6.25 * height - 5 * age + 5;
        printf("|  BMR  |\n");
        printf("|%7.2f|\n", bov_m);
        break;
    case 'f':
        bov_f = 10 * weight + 6.25 * height - 5 * age - 161;
        printf("|  BMR  |\n");
        printf("|%7.2f|\n", bov_f); 
        break;
    default:
        printf("ERROR!");
        break;
    }
    return 0;
}