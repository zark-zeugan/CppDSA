#include <iostream>
#include <unordered_map>
#include <string>





bool canConstruct(std::string ransom, std::string magazine) 
{

	std::unordered_map<char,int> map;
    for(auto val : ransom)
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
    for(auto val: magazine)
    {
        if(!map.count(val))
        {
            continue;     // cannot find value return false or continue in this case.
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



int main()
{
	std::string ransom = "aa";
	std::string magazine = "aab";

	std::cout << canConstruct(ransom,magazine) << std::endl;

	return 0;
}