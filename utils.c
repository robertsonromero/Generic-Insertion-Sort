#include "utils.h"
#include "stdlib.h"

int cmpr_int(void* a, void* b) {
	int a1 = *((int*)a);
	int b1 = *((int*)b);

	if (a1 > b1){
		return 1;
	}
	else if (a1 == b1){
		return 0;
	}
	else {
		return -1;
	}
}

int cmpr_float(void* a ,void* b) {
	float a1 = *((float*)a);
	float b1 = *((float*)b);

	if (a1 > b1){
		return 1;
	}
	else if (a1 == b1){
		return 0;
	}
	else {
		return -1;
	}
	
}

void print_int(void* arr) {
	int *arr1 = arr;
	printf("%d\n", *arr1);
}

void print_float(void* arr) {
	
	float *arr1 = arr;
	printf("%f\n", *arr1);
}

void* read_array(char* filename, char* format, size_t* len) {
	FILE* fp = fopen(filename,"r");
	char* line = NULL;
	size_t bufsize = 0;
	if (fp == NULL) {
        fprintf(stderr, "File failed to open.\n");
        exit(EXIT_FAILURE);
	}

	size_t counter = 0;
	
	int num_lines = 0;
	size_t nread;

    while (( nread = getline(&line, &bufsize, fp)  != -1)) {
        num_lines++;
    }

	size_t size;

    if (format[1] == 'd') {
       size = sizeof(int);
    } else if (format[1] == 'f') {
        size = sizeof(float);
	} else {
        fprintf(stderr, "Error: invalid format string\n");
        exit(EXIT_FAILURE);
    }

	void* arr = malloc(num_lines * size);
	if (arr == NULL) {
        fprintf(stderr, "Error: failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

	rewind(fp);
	while(getline(&line, &bufsize,fp) != -1){
		if (format[1] == 'd'){
			((int*)arr)[counter] = atoi(line);
		}
		else if  (format[1] == 'f'){
			((float*)arr)[counter] = atof(line);
		}
		counter++;
	}
	*len = counter;

	free(line);
	
	fclose(fp);
	return arr;
	
	
}
