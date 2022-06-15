#include <algorithm>
#include <iostream>

void print_arr(int array[], int size_arr)
{
	for(int i=0; i < size_arr; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "" << std::endl; 

}




int MinDiff(int a[], int n, int k)
{
    std::sort(a,a+n); 
    print_arr(a,n);
    int i,mx,mn,ans;
    ans = a[n-1]-a[0];  // this can be one possible solution
    std::cout << "Ans - " << ans << std::endl;
    
    for(i=0;i<n;i++)
    {
    	std::cout << "---" << i << "---" << std::endl;
    	if(a[i]>=k)  // since height of tower can't be -ve so taking only +ve heights
        {
            mn = std::min(a[0]+k, a[i]-k);
            std::cout << "Min of " << "(" << a[0]+k << "," << a[i]-k << ")" << std::endl; 
            mx = std::max(a[n-1]-k, a[i-1]+k);
            std::cout << "Max of " << "(" << a[n-1]-k << "," << a[i-1]+k << ")" << std::endl;
            ans = std::min(ans, mx-mn);
            std::cout << "Ans - " << ans << std::endl;
        }
    }
    return ans;
}


int main()
{
	int a[] = {6, 1, 9, 1, 1, 7, 9, 5, 2, 10};
	int n = sizeof(a)/sizeof(a[0]);
	int k = 4;
	int min_diff = MinDiff(a,n,k);	

	std::cout << "Answer: " << min_diff << std::endl;
}

/*
> Min(a[0]+k, a[i]-k)
    We find this for all elements for which a[i]>=k this is because we wish to find the element 
    that is minimum than the a[0]th element when increased by k. To find the lower limit. 
> Max(a[n-1]-k, a[i-1]+k)
    We wish to find the maximum element when increased by k in comparision to the last element when 
    reduced by k. We find the lower limit. 
> Compare the answer of a[n-1]-a[0] and the possible max-min types.

*/
