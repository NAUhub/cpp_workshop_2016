#ifndef SORT_H
#define SORT_H

#include <vector>
#include "bubblesorter.h"
#include "shakesorter.h"
#include "mergesorter.h"

namespace Algorithms {
namespace Sort {

    void bubble_sort(std::vector<double> &data);
    void shake_sort (std::vector<double> &data);

    template <class Sorter>
    void sort(std::vector<double> &data) {
        Sorter::sort(data);
    }

} // namespace Sort
} // namespace Algorithms

#endif // SORT_H
