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

std::vector<int> bestSum_hp(int target, std::vector<int> nums, std::unordered_map<int, std::vector<int>> &map)
{
	std::vector<int> result;
	auto search = map.find(target);
	if(search != map.end())
	{
		return search->second;
	}
	if(target == 0)
	{
		return {};
	}
	if(target < 0)
	{
		return {-1};
	}

	std::vector<int> small_combi = {-1};

	for(auto val : nums)
	{
		int remainder = target - val;
		result = bestSum_hp(remainder, nums, map);
		if(result.empty() || result.back() != -1)
		{
            result.push_back(val);
            if(small_combi[0] == -1 || result.size() < small_combi.size())
            {
                small_combi = result;
            }

		}
	}

	map[target] = small_combi;
	return map[target];
}

// Using DP.
std::vector<int> bestSum(int target, std::vector<int> nums)
{
	std::unordered_map<int , std::vector<int>> map;
	return bestSum_hp(target, nums, map);
}


std::vector<int> bestSum_brute(int target, std::vector<int> nums)
{
    std::vector<int> result;

    if(target == 0)
    {
        return {};
    }
    if (target < 0)
    {
        return {-1};
    }

    std::vector<int> small_combi = {-1};   // Saperate empty case problem and null case.


    for(auto val : nums)
    {
        int remainder = target - val;
        result = bestSum_brute(remainder,nums);

        if(result.empty() || result.back() != -1)
        {
            result.push_back(val);
            if(small_combi[0] == -1 || result.size() < small_combi.size())
            {
                small_combi = result;
            }
        }
    }

    return small_combi;

}


int main()
{
	std::vector<int> v = {1,2,5,25};
	v = bestSum(100,v);
	print_arr(v);

	return 0;
}