#include <iostream>
#include <vector>
#include <unordered_map>


void print_arr(std::vector<int> array)
{
    for(int i=0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "" << std::endl; 

}


// std::vector<int> howSum_hp(int target, std::vector<int> nums, std::unordered_map<int,int> &map)
// {

// }


// std::vector<int> howSum(int target, std::vector<int> nums)
// {

// }

std::vector<int> howSum_brute(int target, std::vector<int> nums)
{
	std::vector<int> result;

	if(target == 0)
		return {};
	if(target < 0)
	{
		return {-1};
	}

	for(auto val : nums)
	{
		int remainder = target - val;
		result = howSum_brute(remainder, nums);
		if(result.empty() || result.back() != -1)
		{
			result.push_back(val);
			std::cout << val << std::endl;
			return result;
		}
		else
		{
			result.pop_back();
		} 
	}

	return {-1};	
}


int main()
{
	std::vector<int> v = {2,4,3};
	v = howSum_brute(7,v);
	std::cout << "- - - " << std::endl;
	print_arr(v);


	return 0;
}