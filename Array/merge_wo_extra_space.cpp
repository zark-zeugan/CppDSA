#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

void print_arr(int array[], int size_arr)
{
	for(int i=0; i < size_arr; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "" << std::endl; 

}


void gap_method(int arr1[], int arr2[], int n, int m)
{
	int gap = ceil(double(n+m)/2);
	while(gap != 0)
	{
		int i = 0;
		int j = gap;
		while(j < n+m)
		{
			if(j < n && arr1[i] > arr1[j])
				std::swap(arr1[i],arr1[j]);
			else if(j >= n && i >= n && arr2[i-n] > arr2[j-n])
				std::swap(arr2[i-n],arr2[j-n]);
			else if(j >= n && i < n && arr1[i] > arr2[j-n])
				std::swap(arr1[i], arr2[j-n]);

			j++;
			i++;
		}
		if(gap == 1)
		{
			break;
		}
		else
		{
			gap = ceil(double(gap)/2);
		}

	}
	
}


void insert_sort(int arr1[], int arr2[], int size_arr1, int size_arr2)
{
	int temp;
	for(int i = 0; i < size_arr1; i++)
	{
		if(arr1[i] > arr2[0])
		{
			temp = arr2[0];
			arr2[0] = arr1[i];
			arr1[i] = temp;
			std::sort(arr2, arr2 + size_arr2);
		}
	}



}


int main()
{
	int a1[] = {1,3,5,7};
	int a2[] = {0,2,6,8,9};

	int n = sizeof(a1)/sizeof(a1[0]);
	int m = sizeof(a2)/sizeof(a2[0]);

	//auto comp = [](int a, int b){return std::max(a,b);};
	// if(n > m)
	// 	insert_sort(a1,a2,n,m);
	// else
	// 	insert_sort(a2,a1,m,n);

	gap_method(a1,a2,n,m);

	print_arr(a1, n);
	print_arr(a2, m);


	return 0;

}