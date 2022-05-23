#include <iostream>
#include <vector>
#include <unordered_map>

int canSum_brute(int target, std::vector<int> nums)
{
	if(target == 0)
		return true;
	if(target < 0)
		return false;

	for(int i = 0; i < nums.size(); i++)
	{
		int remainder = target - nums[i];
		if(canSum_brute(remainder, nums) == true)
			return true;
	}

	return false;
}

bool canSum_hp(int target, std::vector<int> nums, std::unordered_map<int, bool> & map)
{
	auto search = map.find(target);
	if(search != map.end())
	{
		return search->second;
	}
	if(target == 0)
		return true;
	if(target < 0)
		return false;

	for(int i = 0; i < nums.size(); i++)
	{
		int remainder = target - nums[i];
		if(canSum_hp(remainder, nums, map) == true)
		{
			map[target] = true;
			return true;
		}		
	}
	map[target] = false;
	return false;
}


bool canSum(int target, std::vector<int> nums)
{
	std::unordered_map<int, bool> map;
	return canSum_hp(target, nums, map);
}

int main()
{
	std::cout << canSum(300,{7,14}) << std::endl;
	
	return 0;
}