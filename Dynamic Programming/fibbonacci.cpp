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

// Other method - 

long long int fibbo_tabulation(int n)
{
   long long int v[n+1] = { 0 };
   v[1] = 1;

   for(int i = 0; i < n+1; i++)
   {
      v[i+1] = v[i+1] + v[i];
      v[i+2] = v[i+2] + v[i]; 
   }

   return v[n];
}

int main()
{
	std::cout << fibbo_tabulation(50) << std::endl;
	return 0;
}	

