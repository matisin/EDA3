#ifndef BITMAPH0
#define BITMAPH0
#include <iostream>
#include <sdsl/bit_vectors.hpp>

class BitMapH0
{
private:
    sdsl::rrr_vector<> bm;
    sdsl::rrr_vector<>::select_1_type bm_select;
    sdsl::rrr_vector<>::rank_1_type bm_rank;
    int max;
    int min;

public:
    BitMapH0(std::vector<int> datos, int n, int max);
    void imprimir();
    int sucesor(int data);
    int predecesor(int data);
    void size_bytes();
};
#endif
