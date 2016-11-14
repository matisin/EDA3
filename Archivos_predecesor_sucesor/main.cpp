#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <sdsl/bit_vectors.hpp>
#include <time.h>
#include "bst.h"
#include "bitmap.h"
#include "bitmap_h0.h"

using namespace std;
using namespace sdsl;

int main(int argc,char *argv[])
{
    //Tamaño inicial de arreglo de 2GB
    int N = 268435456;
    //semilla basada en el tiempo
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    //para medir el tiempo de cada operación
    clock_t comienzo;
    double fin;
    for(int j = 0 ; j < 8 ; j++)
    {
        //vector de numeros al azar
        cout << "Generando arreglo de numeros al azar" << endl;
        vector<int> numeros;
        for(int i = 0 ; i < N ; i++)
        {
            numeros.push_back(i+1);
        }
        random_shuffle(numeros.begin(), numeros.end());
        int M = N / 2 ;
        for(int i = 0 ; i < M ; i++)
        {
            numeros.pop_back();
        }
        cout << "Arreglo creado de tamaño " << numeros.size()*8 << endl;

        cout << "Generando BST a partir de arreglo " << endl;
        BinarySearchTree bst(numeros, numeros.size());
        cout << "BST creado de tamaño " << bst.size_bytes() << endl;

        cout << "Generando BitMap a partir de arreglo " << endl;
        BitMap bm = BitMap(numeros, M, N);
        cout << "BitMap creado de tamaño ";
        bm.size_bytes();

        cout << "Generando BitMap comprimido a partir de arreglo " << endl;
        BitMapH0 bmc = BitMapH0(numeros, M, N);
        cout << "BitMap comprimido creado de tamaño ";
        bmc.size_bytes();

        cout << "Calculando resultados" << endl;

        //contadores de tiempo
        double t_pred_bst = 0,t_suc_bst = 0 ,t_pred_bm = 0,t_suc_bm = 0,t_pred_bmc = 0,t_suc_bmc = 0;
        double cont = 0.0;
        int random_n;
        for(int i = 0 ; i < 10000 ; i++)
        {
            random_n = rand() % M;
            //tiempo predecesor bitmap comprimido
            comienzo=clock();
            bmc.predecesor(numeros[random_n]);
            fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
            t_pred_bmc += fin * 1000000.0;

            random_n = rand() % M;
            //tiempo sucesor bitmap comprimido
            comienzo=clock();
            bmc.sucesor(numeros[random_n]);
            fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
            t_suc_bmc += fin* 1000000.0;

            random_n = rand() % M;
            //tiempo predecesor bitmap
            comienzo=clock();
            bm.predecesor(numeros[random_n]);
            fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
            t_pred_bm += fin* 1000000.0;

            random_n = rand() % M;
            //tiempo sucesor bitmap
            comienzo=clock();
            bm.sucesor(numeros[random_n]);
            fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
            t_suc_bm += fin* 1000000.0;

            random_n = rand() % M;
            //tiempo predecesor bst
            comienzo=clock();
            bst.predecesor(numeros[random_n]);
            fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
            t_pred_bst += fin* 1000000.0;

            random_n = rand() % M;
            //tiempo sucesor bst
            comienzo=clock();
            bst.sucesor(numeros[random_n]);
            fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
            t_suc_bst += fin* 1000000.0;
        }
        t_pred_bst = t_pred_bst / 10000;
        t_suc_bst =  t_suc_bst / 10000;
        t_pred_bm = t_pred_bm / 10000;
        t_suc_bm =  t_suc_bm / 10000;
        t_pred_bmc = t_pred_bmc / 10000;
        t_suc_bmc = t_suc_bmc / 10000;

        FILE *resultados;
        resultados = fopen("exp.txt", "a");
        fprintf(resultados,"%d\t",M);
        fprintf(resultados,"%15.10f\t",t_pred_bst);
        fprintf(resultados,"%15.10f\t",t_suc_bst);
        fprintf(resultados,"%15.10f\t",t_pred_bm);
        fprintf(resultados,"%15.10f\t",t_suc_bm);
        fprintf(resultados,"%15.10f\t",t_pred_bmc);
        fprintf(resultados,"%15.10f\n",t_suc_bmc);
        fclose (resultados);
        //se reduce el tamño de N para la siguiente iteración en la mitad
        N = N / 2;

    }


}
