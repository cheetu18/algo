#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
void quicksort(int *arr, int len);
int partition(int *arr, int len);
void pivot(int *arr, int len);

int main()
{
	int len = 8;
	int arr[] = {3, 2, 8, 5, 1, 4, 7, 6};
	int *ptr = arr;
	quicksort(ptr, len);

	for(int i = 0; i < len; i++){
		printf(" %d, ", arr[i]);
	}

	return 0;
}

void quicksort(int *arr, int len)
{
	if (len > 1){
		pivot(arr, len);
	        int idx = partition(arr, len); 
		//[0, idx) is length idx
		quicksort(arr, idx); 
		//(idx, -1] is length len - 1 - idx);
		quicksort((arr + idx + 1), len - 1 - idx);
	}

}
int partition(int *arr, int len)
{
	int val;
	int pivot = arr[0]; 
	int i = 0;
	for(int j = 1; j < len; j++){
		if (arr[j] < pivot){
			i++;
			val = arr[j];
			arr[j] = arr[i];
			arr[i] = val;
			}
	}
	val = arr[i];		
	arr[i] = arr[0];
	arr[0] = val;
	return i;
}

void pivot(int *arr, int len)
{
	srand(time(0));
	int pivot = rand() % len;
	int val = arr[0];
	arr[0] = arr[pivot];
	arr[pivot] = val;
}
