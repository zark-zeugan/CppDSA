#include <iostream>
#include <vector>





int search_target(std::vector<int>& nums, int target, int low, int mid, int high)
{
  	std::cout << "{" << low << "," << mid << "," << high << "}" << std::endl;

  	if(mid == low)
  	{
  		if(nums[low] != target && nums[high] != target)
  		{
  			return -1;
  		}
  	}

	if(target > nums[mid])
	{
		low = mid + 1 ;
		mid = (high+low)/2 ;
		return search_target(nums, target, low, mid, high);
	}
	else if(target < nums[mid])
	{
		high = mid - 1 ;
		mid = (high+low)/2;
		return search_target(nums,target, low, mid, high);
	}
	else
	{
		return mid;
	}

}



int search(std::vector<int>& nums, int target)
{


	if(nums.empty())
	{
		return -1;
	}
	
	int size_arr = nums.size();
	int low = 0;
	int mid = (size_arr-1)/2;
	int high = size_arr-1;

	int ans = search_target(nums, target, low, mid, high);
	return ans;
}


int main()
{					//	  0 1 2 3 4  5  6  7  8  9  10 11 12 13  14	
	std::vector<int> v = {1,5,7,8,10,14,15,23,44,56,76,82,99,102,112};
	int tar = 76;
	int ans = search(v,tar);


	std::cout << "Answer - " << ans << std::endl;

	return 0;

}


