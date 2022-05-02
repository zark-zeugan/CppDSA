#include<iostream>
#include <bits/stdc++.h>


void doUnion(int a[], int n, int b[], int m)
{
	
	std::set<int> s;
	for(int i = 0; i < n; i++)
	{
		s.insert(a[i]);
	}
	for(int i = 0; i < m; i++)
	{
		s.insert(b[i]);
	}

	for(auto i = s.begin(); i != s.end(); i++)
		std::cout << *i << " ";
	
}


int main()
{
	int a[] = {1,2,3,4,5};
	int n = sizeof(a)/sizeof(a[0]);

	int b[] = {1,2,3,4,5,6};
	int m = sizeof(b)/sizeof(b[0]);

	if(n < m)
	{
		sort(a,a+n);
	}
	else
	{
		sort(b,b+m);
	}

	doUnion(a,n,b,m);
	std::cout << "" << std::endl;
}