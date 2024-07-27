//oil_life.c
#include <stdio.h>
#include "oil_life.h"

int oil_life_remaining = 10;

void read_oil_life(){
	FILE *file = fopen("oil_life.dat", "r");
	if (file == NULL){
		oil_life_remaining = 10; //default value if file doesnt exhist 
	}else{
		fscanf(file, "%d", &oil_life_remaining);
		fclose(file);
	}
}

void write_oil_life(){
	FILE *file = fopen("oil_life.dat", "w");
	if (file != NULL){
		fprintf(file, "%d", oil_life_remaining);
		fclose(file);
	}
}
