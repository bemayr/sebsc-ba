#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10

void print_int_array(int int_array[], int length)
{
	int i;
	
	for(i = 0; i < length; i++)
	{
		printf("%d ", int_array[i]);
	}
	
	printf("\n");
}

int int_compare(const void* pA, const void* pB)
{
    int a = *((int*)pA);
    int b = *((int*)pB);
 
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

void print_string_array(char* string_array[], int length)
{
	int i;
	
	for(i = 0; i < length; i++)
	{
		printf("%s ", string_array[i]);
	}
	
	printf("\n");
}

int string_compare(const void* pA, const void* pB)
{
	/* pA is a pointer to a char* (string) */
    char* a = *((char**)pA);
    char* b = *((char**)pB);
    return strcmp(a, b);
}

int main(int argc, char* argv[])
{
	int i;
	int int_array[MAX_LEN];
	
	for(i = 0; i < MAX_LEN; i++)
	{
		int_array[i] = rand() % 20;
	}
	
	print_int_array(int_array, MAX_LEN);
	/* sort int array */
	qsort(int_array, MAX_LEN, sizeof(*int_array), int_compare);
	print_int_array(int_array, MAX_LEN);

	print_string_array(argv + 1, argc - 1);
	qsort(argv + 1, argc - 1, sizeof(*argv), string_compare);
	print_string_array(argv + 1, argc - 1);

	return 0;
}