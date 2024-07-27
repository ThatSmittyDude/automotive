//oil_life_reset.c
#include <stdio.h>
#include <string.h>
#include "oil_life.h"

int main(){
	char reset_input[10]; // buffer to store user input

	read_oil_life();

	while(oil_life_remaining > 0){
		printf("\n");
		printf("Oil life remaining: %d", oil_life_remaining);
		printf("\n");
		printf("Press OK to reset oil life: ");
		scanf("%s", reset_input);

		if (strcmp(reset_input, "OK") == 0){
			oil_life_remaining = 100; // reset oil life remaining
			write_oil_life(); //write the updated oil life value
			printf("\nOil life reset completed\n");
			printf("Oil life remaining: %d", oil_life_remaining);
			printf("\n\n");
			return 0;
		}else{
			printf("Invalid input\n\n");
		}
	}

	return 0;
}
