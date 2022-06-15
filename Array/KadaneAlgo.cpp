#include <iostream>


void print_arr(int array[], int size_arr)
{
	for(int i=0; i < size_arr; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "" << std::endl; 

}

int Max_sum(int arr[], int size_arr)
{
	int max_so_far = arr[0];
	int curr_max = arr[0];

	int start = 0;
	int end = 0;
	int temp = 0;

	for(int i = 1; i < size_arr; i++)
	{
		temp = curr_max + arr[i];
		curr_max = std::max(arr[i], curr_max+arr[i]);

		//max_so_far = std::max(max_so_far, curr_max);

		if(max_so_far <= curr_max)
		{
			max_so_far = curr_max;
			if(arr[i] >= temp)
 			{
				start = i;
				end = i;
			}
			end = i;
		}

	}

	std::cout << "Start - " << start << std::endl;
	std::cout << "End - " << end << std::endl;

	return max_so_far;	
}


int main()
{
	int a[] = {1,2,3,-2,5};
	//int a[] = {-2,-9,-7,-1,-8,-5,-4,-2};
	int size = sizeof(a)/sizeof(a[0]);

	int ans = Max_sum(a,size);

	std::cout << "Answer : " << ans << std::endl;
}


