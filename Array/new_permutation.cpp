#include <iostream>
#include <vector>
#include <bits/stdc++.h>


void print_arr(std::vector<int>& array, int size_arr)
{
	for(int i=0; i < size_arr; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "" << std::endl; 

}

void nextPermutation(std::vector<int>& nums)
{
	int size = nums.size();
	int temp1 = 0;
	int temp2 = size-1;
	bool no_dec_no = false;
	for(int i = size-2; i >= 0; i--)
	{
		if(nums[i] < nums[i+1])
		{
			std::cout << "Decreasing element : " << nums[i] << std::endl;
			temp1 = i;
			no_dec_no = false;
			break;
		}
		else
		{
			no_dec_no = true;
		}
	}
	for(int i = size-1; i >= temp1; i--)
	{
		if(nums[i] > nums[temp1])
		{
			std::cout << "Element just greater : " << nums[i] << std::endl;
			temp2 = i;
			break;
		}
	}
	// Swapping and Reverse.
	if(!no_dec_no)
	{
		int a = nums[temp1];
		nums[temp1] = nums[temp2];
		nums[temp2] = a;

		print_arr(nums,nums.size());

		reverse(nums.begin()+temp1+1,nums.end());
	}
	else
	{
		reverse(nums.begin(), nums.end());
	}
}


int main(int argc, char const *argv[])
{
	std::vector<int> v = {9,8,7,6,5,4,3,2,1};
	//std::vector<int> v = {3,2,1};
	//std::vector<int> v = {1,3,5,4,2};

	nextPermutation(v);

	print_arr(v, v.size());

 	return 0;
}