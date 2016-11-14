#ifndef RMQ
#define RMQ
#include <iostream>
#include <vector>

class RangeMinimumQuery
{
private:
    int min;

public:
    RangeMinimumQuery();
    int find_minimum(std::vector<int> & array,int l,int h);
};
#endif
