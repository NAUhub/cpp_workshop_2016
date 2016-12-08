#include "sort.h"

namespace Algorithms {
namespace Sort {

    void bubble_sort(std::vector<double> &data) {
        for (int last = data.size()-1; last > 0; --last) {
            for (int i = 0; i < last; ++i) {
                if (data[i] > data[i+1]) {
                    std::swap(data[i], data[i+1]);
                }
            }
        }
    }

    void shake_sort(std::vector<double> &data) {
        int last  = data.size()-1;
        int first = 0;
        while (first < last) {
            for (int i = 0; i < last; ++i) {
                if (data[i] > data[i+1]) {
                    std::swap(data[i], data[i+1]);
                }
            }
            last--;
            for (int i = last; i > first; --i) {
                if (data[i] < data[i-1]) {
                    std::swap(data[i], data[i-1]);
                }
            }
            first++;
        }
    }

} // namespace Sort
} // namespace Algorithms
