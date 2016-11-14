#include "rmq.h"
#include "rmq_fix.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <math.h>
#include <iostream>
#include <sdsl/rmq_support.hpp>
using namespace std;
using namespace sdsl;


int main(int argc, char const *argv[]) {

  rmq_succinct_sct<> rmq;
  RangeMinimumQuery re;
  RangeMinimumQueryFix fi;
  vector<int> v;
  int t,rand_value,range_minimum;
  vector<int>::size_type l, h;
  std::clock_t start;
  double duration;
  double total_duration = 0;
  int g = 1000000;
    for (int i = 0; i < g; i++) {
      rand_value = rand() % g;
      v.push_back(rand_value);
    }

    l = 0;
    h = rand() % g;
    start = clock();
    //range_minimum = fi.find_minimum(v,l,h);
    //range_minimum = fi.find_minimum(v,l,h);
    rmq = rmq_succinct_sct<>(&v);
    auto min_idx = rmq(l,h);
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    total_duration+=duration;
    v.clear();

  std::cout << "total: "<<total_duration << std::endl;


  return 0;
}
