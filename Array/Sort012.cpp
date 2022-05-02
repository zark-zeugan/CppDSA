#include <iostream>
// Using Dutch Flag algorithm.

void print_arr(int array[], int size_arr)
{
	for(int i=0; i < size_arr; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "" << std::endl; 

}

void sort012(int arr[], int size_arr)
{
	int low = 0;
	int mid = 0;
	int high = size_arr-1;
	int temp;

	while (mid <= high)
	{
		if(arr[mid]==0)
		{
			temp = arr[mid];
			arr[mid] = arr[low];
			arr[low] = temp;

			mid++;
			low++;
		}
		else if(arr[mid] == 1)
		{
			mid++;
		}
		else if(arr[mid] == 2)
		{
			temp = arr[mid];
			arr[mid] = arr[high];
			arr[high] = temp;
			high--;
		
		}		
	}
	
}


int main()
{
	int arr[] = {0,2,1,2,2,1,2,0};
	int size = sizeof(arr)/sizeof(arr[0]);
	sort012(arr,size);
	print_arr(arr,size);
}




/*
(0,2,1,2,2,1,2,0)  (0,0,7)
(0,2,1,2,2,1,2,0)  (1,1,7)
(0,0,1,2,2,1,2,2)  (1,1,6)
(0,0,1,2,2,1,2,2)  (2,2,6)
(0,0,1,2,2,1,2,2)  (2,3,6)
(0,0,1,2,2,1,2,2)  (2,3,5)
(0,0,1,1,2,2,2,2)  (2,3,4)
*/