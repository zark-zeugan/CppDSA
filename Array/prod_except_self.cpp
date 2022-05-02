#include <iostream>
#include <vector>

void print_arr(std::vector<int>& array, int size_arr)
{
	for(int i=0; i < size_arr; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "" << std::endl; 
}

std::vector<int> prodExceptSelf(std::vector<int>& nums)
{
	int size_arr = nums.size();
	std::vector<int> output = nums;
	int product = 1;
	
	for(int i = 1; i < size_arr; i++)
	{
		output[i] = output[i-1]*output[i];
	}
	for(int i = size_arr-1; i >= 0; i--)
	{
		if (i == 0)
		{
			output[i] = product;
		}
		else
		{
			output[i] = output[i-1]*product;
			product =  product*nums[i];
		}

	}


	return output;

} 


int main()
{
	std::vector<int> v = {-1,-1,0,-3,-3};

	v = prodExceptSelf(v);
	print_arr(v, v.size());

	return 0;
}