#include <iostream>
#include <vector>


void print_arr(std::vector<int> &array, int size_arr)
{
	for(int i=0; i < size_arr; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "" << std::endl; 

}

void mergeSort(std::vector<int> &arr)
{
	// Base Case:
	if (arr.size() <= 1)
	{
		return;
	}
	// Sicing a vector in half. 
	int mid = arr.size()/2; // Get the middle element. 
	std::vector<int> left(arr.begin(), arr.begin()+mid);
	std::vector<int> right(arr.begin()+mid, arr.end());

	mergeSort(left);
	mergeSort(right);

	int i1 = 0;    // Index into left
	int i2 = 0;    // Index into right

	for (int i = 0; i < arr.size(); i++)
	{
		// Take from left if ....
		// Nothing remains on right and 
		// thing on left is smaller. 
		// haven't taken everything from the left. 
		if(i2 >= right.size() || (i1 < left.size() && left[i1] < right[i2])) // Compare the left and right elements and check if i1 < left.size()
		{
			arr[i] = left[i1];
			i1++;
		}else
		{
			arr[i] = right[i2];
			i2++;
		}
	}
	
	//print_arr(arr, arr.size());

}



int main()
{
	//std::vector<int> v = {2,43,25,15,8,75,42,18,11,1};
	std::vector<int> v = {0,2,1,2,0};

	int N = 7; // Third smallest element.

	mergeSort(v);

	print_arr(v,v.size());

	//std::cout << v[N-1] << std::endl;

	return 0;

}