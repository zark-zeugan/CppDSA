#include <iostream>
#include <vector>

void print_arr(std::vector<int> &array, int size_arr)
{
	for(int i=0; i < size_arr; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "" << std::endl; 

}

int floydDuplicates(std::vector<int> &arr)
{
	int slow = arr[0];
	int fast = arr[0];
	print_arr(arr,arr.size());

	do
	{
		slow = arr[slow];
		fast = arr[arr[fast]];                      // Double speed. 

		std::cout << "Slow - " << slow << std::endl;
		std::cout << "Fast - " << fast << std::endl;
	}while(slow != fast);

	slow = arr[0];
	// Second Phase: 
	while(slow != fast)
	{
		slow = arr[slow];
		fast = arr[fast];
	}

	return fast;

}

int binarySearch(std::vector<int> &arr)
{
	
}


int findDuplicates(std::vector<int> &arr)
{
	if(arr.size() <= 1)
	{
		return 0;
	}

	int mid = arr.size()/2;
	std::vector<int> left(arr.begin(), arr.begin()+mid);
	std::vector<int> right(arr.begin()+mid,arr.end());

	findDuplicates(left);
	findDuplicates(right);

	int i1 = 0;
	int i2 = 0;

	for(int i = 0; i < arr.size(); i++)
	{
		if(i2 >= right.size() || (i1 < left.size() && left[i1] < right[i2]))
		{
			arr[i] = left[i1];
			i1++;
		}else
		{
			arr[i] = right[i2];
			i2++;
		}
		if(i>0 && (arr[i] == arr[i-1]))
		{
			return arr[i];
		}
	}
}



int main(int argc, char* argv[])
{
	std::vector<int> nums = {2,5,9,6,9,3,8,9,7,1};

	int ans = floydDuplicates(nums);
	std::cout << "Answer : " << ans << std::endl; 
	//print_arr(nums,nums.size());

	return 0;
}