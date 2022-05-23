#include <iostream>



bool isBadVersion(int n)
{
	if(n == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int firstBadVersion(int n)
{
	long long int low, mid, high;
	low = 1, high = n;
	long int position = 1;
	while(low <= high)
	{
		mid = (low+high)/2;
		bool isbadver = isBadVersion(mid);
		if(isbadver == true)
		{
			position = mid;
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	return position;

}

int main()
{
	int n = 5;
	std::cout  << firstBadVersion(n) << std::endl;

	return 0;

}