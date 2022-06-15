#include <iostream>
#include <unordered_map>
#include <vector>
#include <boost/functional/hash.hpp>

// int gridTraveller_unopt(int n, int m)
// {
// 	if(n == 1 && m == 1)
// 	{
// 		return 1;
// 	}
// 	if(n == 0 || m == 0)
// 	{
// 		return 0;
// 	} 

// 	int down = gridTraveller_unopt(n-1,m);
// 	int right = gridTraveller_unopt(n,m-1);

// 	return down + right;
// }

template <typename Container> 
struct container_hash {
    std::size_t operator()(Container const& c) const {
        return boost::hash_range(c.begin(), c.end());
    }
};

long int gt_helper(int n, int m, std::unordered_map<std::vector<int>,long int, container_hash<std::vector<int>>> &map)
{

	auto search = map.find({n,m});
	if(search != map.end())
	{
		return search->second;
	}

	if(n == 1 && m == 1)
		return 1;
	if(n == 0 || m == 0)
		return 0;

	map[{n,m}] = gt_helper(n-1,m,map) + gt_helper(n,m-1,map);
	
	return map[{n,m}];
}

long int gridTraveller(int n, int m)
{
	std::unordered_map<std::vector<int>,long int, container_hash<std::vector<int>>> map;

	return gt_helper(n,m,map);
}


int gridTraveller_tabu(int n, int m)
{
	int arr[n+1][m+1] = {};
	arr[1][1] = 1;


	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(i+1 <= n)
			{
				arr[i+1][j] = arr[i+1][j] + arr[i][j];
			} 
			if(j+1 <= m)
			{
				arr[i][j+1] = arr[i][j+1] + arr[i][j];
			} 
		}
 	}


	

	return arr[n][m];
}

int main()
{
	std::cout << gridTraveller_tabu(3,5) << std::endl;

	return 0;
}