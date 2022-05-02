// Input integer array and number of elements. 
// Output the maximum and minimum element. 

#include <iostream>

struct Pair 
{
	int min;
	int max;
};

struct Pair getMinMax(int arr[], int size_arr)    // Return type is "struct Pair"
{
	struct Pair minmax;
	int i;

	if(size_arr % 2 == 0)
	{
		if (arr[0] > arr[1])
		{
			minmax.min = arr[1];
			minmax.max = arr[0];
		}
		else
		{
			minmax.min = arr[0];
			minmax.max = arr[1];
		}
		i = 2;
	}
	else
	{
		minmax.min = arr[0];
		minmax.max = arr[0];
		i = 1;
	}

	while(i < size_arr - 1)
	{
		if(arr[i] > arr[i+1])
		{
			if(arr[i] > minmax.max)
				minmax.max = arr[i];
			if(arr[i+1] < minmax.min)
				minmax.min = arr[i+1];
		}
		else
		{
			if(arr[i+1] > minmax.max)
				minmax.max = arr[i+1];
			if(arr[i] < minmax.min)
				minmax.min = arr[i];
		}
		i += 2;
	}

	return minmax;

}

int main(int argc, char const *argv[])
{
	int arr[] ==  {22, 11, 34, 2, 54, 8, 15, 12, 2};
	int size = sizeof(arr)/sizeof(arr[0]);
	Pair minmax = getMinMax(arr, size);

	std::cout << "Minimum Value - " << minmax.min << std::endl;
	std::cout << "Maximum Value - " << minmax.max << std::endl;


	return 0;
}