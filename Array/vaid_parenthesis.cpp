#include <iostream>
#include <bits/stdc++.h>
#include <string>


bool isValid(std::string s)
{
	std::stack<char> par;
	int k = 0;
	bool valid;


	while(k < s.size())
	{
		if(par.empty() && (s[k] == ')' || s[k] == '}' || s[k] == ']'))
		{
			return false;
		}
		if(s[k] == '(' || s[k] == '{' || s[k] == '[')
		{
			std::cout << s[k] << std::endl;
			par.push(s[k]);
		}

        else if((s[k] ==')' && par.top() == '(') || (s[k] == '}' && par.top() == '{') || (s[k] == ']' && par.top() == '['))
		{
			std::cout << s[k] << std::endl;
			par.pop();
		}
		else
		{
			valid = false;
			break;
		}

		k++;
	}
	if(par.empty())
	{
		valid = true;
	}
	else
	{
		valid = false;
	}

	return valid;
}


int main()
{
	std::string str = "(){}}{";

	std::cout << isValid(str) << std::endl;
 
	return 0;
}