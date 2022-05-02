#include<iostream>
// Arrange all the negative numbers behind the positive numbers. 
// Order is not really important. 
void print_arr(int array[], int size_arr)
{
	for(int i=0; i < size_arr; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "" << std::endl; 

}


void move_neg(int arr[], int size_arr)
{
	int low = 0;
	int high = size_arr-1;
	int temp;

	while(low != high)
	{
		if(arr[low] < 0)
		{
			low++;

		}else
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
			high--;
		}
	}
}
  
int main()
{
	int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
	int size = sizeof(arr)/sizeof(arr[0]);


	move_neg(arr,size);
	print_arr(arr, size);
}