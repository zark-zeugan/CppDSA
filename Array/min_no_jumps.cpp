#include <iostream>



int MinJumps(int arr[], int size_arr)
{
	if(arr[0] == 0)
	{
		return -1; // No jump can be taken case.
	}
	if(size_arr <= 1)
	{
		return 0;
	}

	int remaining_steps = arr[0];
	int max_reach = arr[0];
	int jumps = 1;

	int i;
	for(i = 1; i < size_arr; i++)
	{
		if(i == size_arr-1)
		{
			return jumps;
		}
		max_reach = std::max(max_reach,i+arr[i]);    // Calculate the max reach by adding the current index and the number of jumps indicated on the respective index.
		std::cout << "Max Reach - " << max_reach << std::endl;
		remaining_steps--;
		std::cout << "Remaining Steps - " << remaining_steps << std::endl;
		if(remaining_steps == 0)
		{
			std::cout  << "------" << std::endl;
			jumps ++;
			if(i == max_reach)
			{	
				std::cout << i << "   " << max_reach << std::endl;
				return -1;
			}

			remaining_steps = max_reach-i;
			std::cout << "Remaining Steps - " << remaining_steps << std::endl;
			std::cout  << "------" << std::endl;
		}
	}


}


int main(int argc, char const *argv[])
{
	int a[] = {2,1,0,3};	
	int size = sizeof(a)/sizeof(a[0]);

	int min_jump = MinJumps(a,size);
	std::cout << "The min no. of jumps - " << min_jump << std::endl;

	return 0;
}




