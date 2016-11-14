#include "rmq.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

RangeMinimumQuery::RangeMinimumQuery()
{

}

int RangeMinimumQuery::find_minimum(vector<int> & array,int l,int h)
{
  int size = array.size();
  std::vector< vector<int> > table;
  int data;
  for (int i = 0; i < size; i++)
  {
    vector<int> foo;
    min = array[i];
    for (int j = 0; j < size; j++)
    {
      if (min<array[j]){
        foo.insert(foo.begin()+j,min);
      }else{
        foo.insert(foo.begin()+j,array[j]);
        min = array[j];
      }
    }
    table.insert(table.begin()+i,foo);
  }

  return table[l][h];

}
