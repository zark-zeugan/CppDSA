#include <iostream>
#include <unordered_map>

long long int fib(long long int n)
{

   long long int f[n + 2];
   int i;
   f[0] = 0;
   f[1] = 1;
 
   for(i = 2; i <= n; i++)
   {
    f[i] = f[i - 1] + f[i - 2];
   }
   return f[n];
}



int main()
{
	std::cout << fib(50) << std::endl;
	return 0;
}	

