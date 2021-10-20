//#include<iostream>
#include<stdio.h>

#define SIZE 5

int main()
{

	int arr[SIZE];
	int max ;

	for (int i = 0; i < size; i++)
	{
		printf("arr[%d"] = ",i);
		scanf("%d", &arr[i]);
         }
         
        max = arr[0]; 
	for (int i = 1; i < size; i++)
	{
		
		if (max < arr[i])
			max = arr[i];

	}
	cout << "Max: " << max << endl;

}
