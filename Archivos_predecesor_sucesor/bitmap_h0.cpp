#include "bitmap_h0.h"
#include <sdsl/bit_vectors.hpp>
#include <iostream>

using namespace std;
using namespace sdsl;

BitMapH0::BitMapH0(vector<int> datos, int n, int max)
{

    bit_vector bitmap(max, 0);
    this->max = max;
    min = max;
    for(int i = 0 ; i < n ; i++)
    {
        bitmap[datos[i] - 1] = 1;
        if((datos[i] - 1) < min)
        {
            min = datos[i];
        }
    }
    bm = rrr_vector<>(bitmap);
    bm_rank = rrr_vector<>::rank_1_type(&bm);
    bm_select = rrr_vector<>::select_1_type(&bm);
}

int BitMapH0::sucesor(int data)
{
    if(data >= max || data < min)
    {
        return -1;
    }else
    {
        return bm_select(bm_rank(data) + 1) + 1;
    }
}

int BitMapH0::predecesor(int data)
{
    if(data > max || data <= min)
    {
        return -1;
    }else
    {
        return bm_select(bm_rank(data - 1)) + 1;
    }

}
void BitMapH0::imprimir()
{
    cout << bm << endl;
}

void BitMapH0::size_bytes()
{
    cout << size_in_bytes(bm) << endl;
}
