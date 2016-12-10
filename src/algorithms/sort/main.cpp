#include "sort.h"
#include <iostream>

#include <ctime>

int main(int argc, char *argv[]) {
    int N=6;
    srand(time(0));
    std::vector<double> data(N);
    for(int i = 0; i < N; ++i){
        data[i] = rand() % 100 + 1;
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    Algorithms::Sort::Seredan::bubble_sort(data);
    for(int i = 0; i < data.size(); ++i){
        std::cout << data[i] << " ";
   }
    std::cout << std::endl;

    return 0;
}
