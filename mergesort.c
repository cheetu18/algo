#include <stdio.h>
#include <stdlib.h>
void  merge(int *ptr1, int  *ptr2, int len, int len2, int *output);
void mergesort(int* arr, int size)
{
	int len, len2, *merged;
	len  = (size/2);
	len2 = size - len;
	//base case 
	if(size > 1){
		/*create space for two sorted arrays*/
		int *first = malloc(sizeof(int) * len);
		int *second = malloc(sizeof(int) * len2);


		for(int i = 0; i < len; i++)
			first[i] = arr[i];
			
		for(int j = len; j < size; j++)
			second[j - len] = arr[j];
			
		//recursive calls 	
		mergesort(first, len);
		mergesort(second,len2);

		merge(first, second, len,  len2, arr);
		free(first);
		free(second);
		
	}
		
}



void  merge(int *ptr1, int  *ptr2, int len, int len2, int *output)
{
	int i, j, idx; //assist increment  for ptr1 and ptr2 	
	int total = len + len2;

	
	i = j = idx = 0;
	while(i < len && j < len2){
		if(ptr1[i] <= ptr2[j]){
			output[idx++] = ptr1[i++];
		}
		else{
			output[idx++] = ptr2[j++];
		}
	}
	//remaining elements  
	while(i < len){
		output[idx++] = ptr1[i++];
	}

	while(j < len2){
		output[idx++] = ptr2[j++];
	}

}
int main()
{
//int bak[] = {3, 0, 4, 6, 5, 7};
int bak[] = {3323, 2320, 4, 60, 53, 7, 3, 2, 5, 6, 5, 3, 2, 1, 10, 11, 24};
for(int i = 0; i < 17; i++){
	printf(" %d ",bak[i]);
}
printf("\n");
int *ptr2 = &bak[0];
mergesort(ptr2, 17);

for(int i = 0; i < 17; i++){
	printf(" %d ",bak[i]);
}
return 0;
}

	


	


			
