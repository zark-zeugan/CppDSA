#include <iostream>


void print_arr(int array[], int size_arr)
{
	for(int i=0; i < size_arr; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "" << std::endl; 

}


void rotate(int arr[], int size_arr)
{
	int last_elem = arr[size_arr-1];

	for(int i = size_arr-1; i > 0; i--)
	{
		arr[i] = arr[i-1];

	}
	arr[0] = last_elem;
	print_arr(arr, size_arr);
}

int main()
{
	int a[] = {1,2,3,4,5};
	int size = sizeof(a)/sizeof(a[0]);
	print_arr(a,size);
	rotate(a,size);


}