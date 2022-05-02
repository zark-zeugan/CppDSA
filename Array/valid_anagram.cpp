#include <iostream>
#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t)
{

	std::unordered_map<char,int> map;

	for(auto val : s)
	{
		if(!map.count(val))
		{
			map[val] = 1;
		}
		else
		{
			map.find(val)->second++;

		}
	}

	for(auto val: t)
	{
		if(!map.count(val))
		{
			return false;
		}
		else
		{
			map.find(val)->second--;
			if(map.find(val)->second == 0)
			{
				map.erase(val);
			}
		}

	}

    if(map.empty())
    {
    	return true;
    }
    else
    {
    	return false;
    }


}


int main(int argc, char const *argv[])
{
	
	std::string s = "anagram";
	std::string t = "nagaram";


	isAnagram(s,t);


	return 0;
}