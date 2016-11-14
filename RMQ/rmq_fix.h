#ifndef RMQF
#define RMQF
#include <iostream>
#include <vector>
#define MAX 10000

class RangeMinimumQueryFix
{
public:
    RangeMinimumQueryFix();
    int find_minimum(std::vector<int> & array, std::vector<int>::size_type & from, std::vector<int>::size_type & to);

};
#endif
