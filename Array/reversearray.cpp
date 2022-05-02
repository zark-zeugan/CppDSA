#include <iostream>
#include <bits/stdc++.h>

template <typename T>
void print_arr(T *fin_arr, int size_arr)
{
	for(int i=0; i < size_arr; i++)
	{
		std::cout << fin_arr[i] << " ";
	}
	std::cout << "" << std::endl; 

}

template <typename T>
void reverse_array(T *arr, int size_arr)
{
	int start = 0;
	int end = size_arr-1;
	while(start < end)
	{
		T temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	std::cout << "Output : ";
	print_arr(arr,size_arr);
}

int main()
{
	int a[] = {1,2,4,5,6,7,8,10};
	int size = sizeof(a)/sizeof(a[0]); 

	std::cout << "Input : ";
	print_arr(a,size);

	//std::cout << "Size of the array - " << size << std::endl;

	reverse_array(a, size);

}