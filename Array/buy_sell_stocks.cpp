#include <iostream>
#include <vector>


int maxProfit(std::vector<int>& prices)
{
    int size = prices.size();
    int min_price = prices[0];
    int max_profit = 0;

    for(int i = 0; i < size; i++)
    {
        min_price = std::min(min_price, prices[i]);
        max_profit = std::max(max_profit, prices[i] - min_price);

    }

    return max_profit;
}


int main()
{
	std::vector<int> v = {7,6,4,3,1};

	int ans = maxProfit(v);

	std::cout << "Answer - " << ans << std::endl;

	return 0;

}


