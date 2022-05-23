#include <iostream>
#include <string>
#include <vector>


bool canConstruct(std::string target, std::vector<std::string> wordBank)
{
	if(target == "")
	{
		return true;
	}


	for(auto val:target)
	{
		if()
	}

	return false;
}



int main()
{
	std::string s = "abcdef";
	std::vector <std::string> v = {"ab","abc", "cd", "def", "abcd"};

	std::cout << canConstruct(s,v) << std::endl;

}