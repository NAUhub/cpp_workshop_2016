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

namespace Seredan {
    void bubble_sort(std::vector<double> &data) {
        double temp;
        int last = data.size();
        for (int j=0; j<data.size()-1; j++, last--) {
            int len = 0;
            while (len < last-1) {
                if (data[len] > data[len+1]) {
                    temp = data[len];
                    data[len] = data[len+1];
                    data[len+1] = temp;
                }
                len++;
            }
        }
    }

    void shake_sort (std::vector<double> &data) {

    }
} // namespace Seredan

} // namespace Sort
} // namespace Algorithms
