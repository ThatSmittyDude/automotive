//init_oil_life.c
#include <stdio.h>

int main() {
    FILE *file = fopen("oil_life.dat", "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    int initial_oil_life = 10; // Initial value for oil life
    fprintf(file, "%d", initial_oil_life);
    fclose(file);

    printf("oil_life.dat initialized with oil life value: %d\n", initial_oil_life);
    return 0;
}
