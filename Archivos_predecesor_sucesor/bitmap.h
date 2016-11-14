#ifndef BITMAP
#define BITMAP
#include <iostream>
#include <sdsl/bit_vectors.hpp>

class BitMap
{
private:
    sdsl::bit_vector bm;
    sdsl::rank_support_v<1> bm_rank;
    sdsl::select_support_mcl<1> bm_select;
    int max;
    int min;

public:
    BitMap(std::vector<int> datos, int n, int max);
    void imprimir();
    int sucesor(int data);
    int predecesor(int data);
    void size_bytes();
};
#endif
