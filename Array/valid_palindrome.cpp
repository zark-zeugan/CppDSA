#include <iostream>
#include <string>


// bool isNotAlnum(char c)
// {
// 	return isalnum(c) == 0;
// }

bool isPalindrome(std::string s)
{
	int size = s.size();
	bool ans;
	char low_ptr;
	char high_ptr;
	int k = 0;
	int m = size-1;

	while(k <= m)
	{
		low_ptr = tolower(s[k]);
		high_ptr = tolower(s[m]);
		if(isalnum(low_ptr) == 0)
		{
			k++; 
			continue;
		}
		else if(isalnum(high_ptr) == 0)
		{
			m--;
			continue;
		}
		else
		{
			if(low_ptr == high_ptr)
			{
				//std::cout << "low_ptr :" << low_ptr << "   high_ptr :" << high_ptr << std::endl;
 				ans = true;
				k++;
				m--;
			}
			else
			{
				ans = false;
				break;
			}
		}
	}

	return ans;
}

int main()
{
	std::string str = "A man, a plan, a canal: Panama";
    	
    std::cout << isPalindrome(str) << std::endl;

    return 0;


}