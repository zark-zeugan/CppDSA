#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

bool canConstruct_brute(std::string target, std::vector<std::string> wordBank)
{
	if(target == "")
	{
		return true;
	}

	for(auto val:wordBank)
	{
		if(val == target.substr(0,val.size()))
		{
			if(canConstruct_brute(target.substr(val.size(),target.size()),wordBank) == true)
			{
				return true;
			}
		}
	}

	return false;
}

bool canConstruct_hp(std::string target, std::vector<std::string> wordBank, std::unordered_map<std::string,bool> &map)
{
	auto search = map.find(target);
	if(search != map.end())
	{
		return search->second;
	}
	if(target == "")
	{
		return true;
	}
	for(auto val : wordBank)
	{
		if(val == target.substr(0,val.size()))
		{
			if(canConstruct_hp(target.substr(val.size(),target.size()), wordBank, map) == true)
			{
				map[target] = true;
				return true;
			}
		}
	}
	map[target] = false;
	return map[target];

}

bool canConstruct(std::string target, std::vector<std::string> wordBank)
{
	std::unordered_map<std::string, bool> map;
	return canConstruct_hp(target, wordBank, map);
}

int main()
{
 	std::string s = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    std::vector<std::string> v = {"e","ee","eee","eeee","eeeee"};
    // std::string s = "enterapotentpot";
    // std::vector<std::string> v = {"a","p","ent","enter","ot", "o", "t"};


	std::cout << canConstruct(s,v) << std::endl;
	return 0;

}