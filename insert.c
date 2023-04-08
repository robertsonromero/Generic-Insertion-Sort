#include "insert.h"

void swap(char* a, char* b, size_t width){
	char* _a = (char*)a;
	char* _b = (char*)b;
	char temp;
	for(int i = 0; i < width; i++){
        temp = _a[i];
        _a[i] = _b[i];
        _b[i] = temp;
	}
}

void iSort(void* base, size_t nel, size_t width, int (*compare)(void*,void*)) {
	//casting void pointer to a char pointer
	char* arr = base;
	for(size_t i = 1; i < nel; i++){
		size_t j = i;
		while( j > 0 && (compare(arr + (j-1) * width, arr + (j) * width) == 1)){
			swap(arr + j * width,arr + (j-1) * width, width); 
			j--;
		}
	}
	
}
		
void iPrint(void* base, size_t nel, size_t width, void (*print)(void*)) {
	for (size_t i = 0; i < nel; i++){
		print(base + i * width);
	}
	
}
