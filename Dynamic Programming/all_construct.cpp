#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <deque>




std::vector<std::deque<std::string>> allConstruct_brute(std::string target, std::vector<std::string> wordBank)
{
	std::vector<std::deque<std::string>> result;
	if(target == "")
	{
		return {{}};
	}

	for(auto val : wordBank)
	{
		if(val == target.substr(0,val.size()))
		{
			std::vector<std::deque<std::string>> suffixways = allConstruct_brute(target.substr(val.size(),target.size()),wordBank);
			if(!suffixways.empty())
			{
				for(auto value : suffixways)
				{
					value.push_front(val);
					result.push_back(value);
				}

			}
		}
	}

	return result;
}

std::vector<std::deque<std::string>> all_Construct_hp(std::string target, std::vector<std::string> wordBank, std::unordered_map<std::string, std::vector<std::deque<std::string>>> & map)
{
	std::vector<std::deque<std::string>> result;
	auto search = map.find(target);
	if(search != map.end())
	{
		return search->second;
	}

	if(target == "")
	{
		return {{}};
	}

	for(auto val : wordBank)
	{
		if(val == target.substr(0,val.size()))
		{
			std::vector<std::deque<std::string>> suffixways = all_Construct_hp(target.substr(val.size(),target.size()),wordBank,map);
			if(!suffixways.empty())
			{
				for(auto value : suffixways)
				{
					value.push_front(val);
					result.push_back(value);
				}
				map[target] = result;

			}
		}
	}

	return map[target];
}


std::vector<std::deque<std::string>> all_Construct(std::string target, std::vector<std::string> wordBank)
{
	std::unordered_map<std::string, std::vector<std::deque<std::string>>> map;
	return all_Construct_hp(target, wordBank, map);	
}


int main()
{
	// std::string s = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
 //    std::vector<std::string> v = {"e","ee","eee","eeee","eeeee"};
	std::string s = "purple";
	std::vector<std::string> v = {"purp", "p", "ur", "le", "purpl"};
	// std::string s = "abcdef";
	// std::vector<std::string> v = {"ab", "abc", "cd", "def" , "abcd", "ef", "c"};
	// std::string s = "enterapotentpot";
 	// std::vector<std::string> v = {"a","p","ent","enter","ot", "o", "t"};

    //std::vector<std::deque<std::string>> result = allConstruct_brute(s,v);
    std::vector<std::deque<std::string>> result = all_Construct(s,v);

    for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++)
        std::cout << result[i][j] << " ";
    std::cout << std::endl;
	}
	
	return 0;
} 