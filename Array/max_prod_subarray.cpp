#include <iostream>
#include <vector>

int maxProduct(std::vector<int>& nums)
{
	int size_arr = nums.size();

	int curr_max = nums[0];
	int max_so_far = nums[0];
	int product = nums[0];

	for(int i = 1; i < size_arr; i++)
	{
		product = product*nums[i];
		curr_max = std::max(product, curr_max*nums[i]);
		std::cout << curr_max << std::endl;
		max_so_far = std::max(max_so_far, curr_max);
		std::cout << max_so_far << std::endl;
	}

	return max_so_far;
}


int main()
{

	//std::vector<int> v = {2,3,-2,4};
	std::vector<int> v = {-2,3,-4};

	std::cout << maxProduct(v) << std::endl;
}