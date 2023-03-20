#include "insertion.h"
#include "utils.h"


int main(int argc, char** argv) {
	
	

	size_t len = 0;
	int* arr = read_array(argv[1], argv[2], &len);
	iSort(arr, len, sizeof(int), &cmpr_int); 
	iPrint(arr, len, sizeof(int), &print_int);
	
	free(arr);
	
	
	exit(EXIT_SUCCESS);
}


