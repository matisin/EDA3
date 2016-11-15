#include "sdsl/bit_vectors.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>       
#include <functional> 
#include <utility> 
#include <fstream>

using namespace std;
using namespace sdsl;





int main(){
	srand(time(NULL));
	int cant_claves=100000; // ejeplo claves[1...n]
	int cant_elementos;
	FILE *resultados_suc;
	resultados_suc = fopen("resultados_sucintos", "w+");
	FILE *resultados;
	resultados = fopen("resultados_original", "w+");
	FILE *tam_suc;
	tam_suc = fopen("tam_sucintos", "w+");
	FILE *tam;
	tam = fopen("tam_original", "w+");

	for(int cant_elementos = 100; cant_elementos<= cant_claves; cant_elementos+=200){
	//·············PREPROCESAMIENTO················	
	int t=cant_elementos; //# elementos
	int elementos[cant_claves];
	vector<pair<int,int>> list;
	for (int i = 0; i < cant_claves; ++i)
	{
		elementos[i]=-1;
	}
	int random;
	for (int i = 0; i < t; ++i)
	{	random=rand()%cant_claves;

		while(true){
			if(elementos[random]!=-1)
				random=rand()%cant_claves;
			else break;
		}
		list.push_back(make_pair(random,rand()));
		elementos[random]=50;
		
		
	}

	sort(list.begin(),list.end());

	//·············PREPROCESAMIENTO················	

	bit_vector B(cant_claves,0);


	unordered_map <int,int> mapita ;


		for (int i = 0; i < t; ++i)
	{
		mapita[rand()%cant_claves]=rand();
	}
	

	 rank_support_v<1> b_rank(&B);


	 //···········CONSULTAS PARA EXPERIMENTO·············

	 vector<int> exp;
	 for (int i = 0; i < cant_elementos*100; ++i)
	 {
	 	exp.push_back(random%cant_claves); // Creacion de indices para aplicarles luego hash
	 }




	 clock_t comienzo;
	 comienzo=clock();
	 for (int i = 0; i < cant_elementos*100; ++i)
	 {
	 	mapita.find(exp[i]); // encontrar en unordered_map
	 }

	 double fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;

	 fprintf(resultados, "%d\t%lf\n", cant_elementos,fin);


	 clock_t comienzo2;

	 comienzo2=clock();
	 	 for (int i = 0; i < cant_elementos*100; ++i)
	 {
	 	if(B[exp[i]])
	 	list[b_rank(exp[i])]; //encontrar en bitvector
	 }

	 double fin2=(clock()-comienzo2)/(double)CLOCKS_PER_SEC;

	 fprintf(resultados_suc, "%d\t%lf\n", cant_elementos,fin2);


	fprintf(tam, "%d\t%f\n",cant_elementos,size_in_mega_bytes(B)	+ size_in_mega_bytes(b_rank)+((double)list.size()*16 /(2^20)) );
	fprintf(tam_suc, "%d\t%f\n",cant_elementos,(double)mapita.size()*16 /(2^20));
	
	}




}