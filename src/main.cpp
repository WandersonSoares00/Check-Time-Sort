#include <iostream>
#include <iomanip>
#include "sort.hpp"
#include "utill.hpp"

using namespace std;

int main(int argc, char **argv){
    try{
        if (argc < 4)
            throw invalid_argument("Use ./programa [Tipo de Instância] [Tamanho do Vetor] [Número de Instâncias]");

        double t_hs, t_qsf, t_qsa, t_is_hs, t_is_is, t_ms, t_is_ms;
        t_hs = t_qsf = t_qsa = t_is_hs = t_is_is = t_ms = t_is_ms = 0.0;

        int i = atoi(argv[3]);
        int size = atoi(argv[2]);
        int *v;
        SortingTime<int> sort(v, size);
        
        fill_array <int>(v, size, *argv[1]);

        while(i--){
            t_hs    += sort.time(heap_sort);
            t_qsf   += sort.time(quick_sort_determ);
            t_qsa   += sort.time(quick_sort_indeterm);
            t_is_hs += sort.time(intro_sort_hs);
            t_is_is += sort.time(intro_sort_in);
            t_ms    += sort.time(merge_sort);
            t_is_ms += sort.time(intro_sort_ms);
        }

        cout << "\nResultados do tempo de execução da ordenação de "<< argv[3] <<" vetores de tamanho " << size << "\n\n";
        cout << setw(30) << "\tAlgoritmo"  << setw(50) << "Tempo total de execução (em segundos)\n";
        cout << setw(30) << left << "\tHeap Sort"                   <<right<<':' << setw(30) << right <<fixed<<setprecision(7)<<t_hs << '\n';
        cout << setw(31) << left << "\tQuick Sort (pivô fixo)"      <<right<<':' << setw(30) << right <<fixed<<setprecision(7)<<t_qsf << '\n';
        cout << setw(32) << left << "\tQuick Sort (pivô aleatório)" <<right<<':' << setw(30) << right <<fixed<<setprecision(7)<<t_qsa << '\n';
        cout << setw(30) << left << "\tIntro Sort (Heap Sort)"      <<right<<':' << setw(30) << right <<fixed<<setprecision(7)<<t_is_hs << '\n';
        cout << setw(30) << left << "\tIntro Sort (Insertion Sort)" <<right<<':' << setw(30) << right <<fixed<<setprecision(7)<<t_is_is << '\n';
        cout << setw(30) << left << "\tMerge Sort (interativo)"     <<right<<':' << setw(30) << right <<fixed<<setprecision(7)<<t_ms << '\n';
        cout << setw(30) << left << "\tIntro Sort (Merge, insert)"  <<right<<':' << setw(30) << right <<fixed<<setprecision(7)<<t_is_ms << '\n';
    
    }
    catch(const exception& e){
        cerr << "ERRO: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
