#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>



int countConstruct_brute(std::string target, std::vector<std::string> wordBank)
{
	int result = 0;
	if(target == "")
	{
		return 1;
	}

	for(auto val : wordBank)
	{
		if(val == target.substr(0,val.size()))
		{
			result = countConstruct_brute(target.substr(val.size(),target.size()), wordBank) + result;	
		}
	}
	return result;
}


int countConstruct_hp(std::string target, std::vector<std::string> wordBank, std::unordered_map<std::string, int> & map)
{
	int result = 0;
	auto search = map.find(target);
	if(search != map.end())
	{
		return search->second;
	}
	if(target == "")
	{
		return 1;
	}

	for(auto val : wordBank)
	{
		if(val == target.substr(0,val.size()))
		{
			result = countConstruct_hp(target.substr(val.size(),target.size()), wordBank, map) + result;			
		}
		map[target] = result;

	}

	return map[target];
}

int countConstruct(std::string target, std::vector<std::string> wordBank)
{
	std::unordered_map<std::string, int> map;
	return countConstruct_hp(target, wordBank, map);
}


int main()
{
	std::string s = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    std::vector<std::string> v = {"e","ee","eee","eeee","eeeee"};
	// std::string s = "purple";
	// std::vector<std::string> v = {"purp", "p", "ur", "le", "purpl"};
	// std::string s = "abcdef";
	// std::vector<std::string> v = {"ab", "abc", "cd", "def" , "abcd"};
	// std::string s = "enterapotentpot";
    // std::vector<std::string> v = {"a","p","ent","enter","ot", "o", "t"};


	std::cout << countConstruct(s,v) << std::endl;
	return 0;
} 