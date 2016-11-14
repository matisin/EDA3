#include "bitmap.h"
#include <sdsl/bit_vectors.hpp>
#include <iostream>

using namespace std;
using namespace sdsl;

BitMap::BitMap(vector<int> datos, int n, int max)
{
    bm = bit_vector(max, 0);
    this->max = max;
    min = max;
    for(int i = 0 ; i < n ; i++)
    {
        bm[datos[i] - 1] = 1;
        if((datos[i] - 1) < min)
        {
            min = datos[i];
        }
    }
    bm_rank =rank_support_v<1>(&bm);
    bm_select = select_support_mcl<1>(&bm);
}

int BitMap::sucesor(int data)
{
    if(data >= max || data < min)
    {
        return -1;
    }else
    {
        return bm_select(bm_rank(data) + 1) + 1;
    }
}

int BitMap::predecesor(int data)
{
    if(data > max || data <= min)
    {
        return -1;
    }else
    {
        return bm_select(bm_rank(data - 1)) + 1;
    }

}
void BitMap::imprimir()
{
    cout << bm << endl;
}

void BitMap::size_bytes()
{
    cout << size_in_bytes(bm) << endl;
}
