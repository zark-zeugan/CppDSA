#include <iostream> 
#include <vector>
#include <bits/stdc++.h>



std::vector<std::vector<int>> merge_intervals (std::vector<std::vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> merged;
    for (auto interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        }
        else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;

}


int main()
{
    // using an initializer list to construct a vector of vectors
    std::vector<std::vector<int>> v {{1,9}, {2,5}, {19,20}, {10,11}, {12,20}, {0,3}, {0,1}, {0,2}};
    
    merge_intervals(v);

    return 0;
}
