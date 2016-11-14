#include <iostream>
#include <vector>
#include <algorithm>
#include "rmq_fix.h"
using namespace std;


RangeMinimumQueryFix::RangeMinimumQueryFix()
{

}

int RangeMinimumQueryFix::find_minimum(vector<int> & array, vector<int>::size_type & from, vector<int>::size_type & to)
{
    vector<vector<int> > mins;
    for (vector<int>::size_type i = 0; i < array.size(); i++) {
        mins.push_back(vector<int>());
        mins[i].push_back(array[i]);
    }

    for (vector<int>::size_type j = 1; (1U << j) <= array.size(); j++) {
        for (vector<int>::size_type i = 0; i+(1 << j)-1 < array.size(); i++) {
            int val = min(mins[i][j-1], mins[i+(1<<(j-1))][j-1]);
            mins[i].push_back(val);
        }
    }

    vector<int>::size_type shifts = 0;
    vector<int>::size_type val = to-from+1;
    for (; val != 1; val >>= 1, shifts++);


    vector<int>::size_type l = shifts;
    return min(mins[from][l], mins[to+1-(1<<l)][l]);
}
