#ifndef SORT_H
#define SORT_H

#include <vector>
#include "bubblesorter.h"
#include "shakesorter.h"
#include "mergesorter.h"

namespace Algorithms {
namespace Sort {
namespace Seredan {

    void bubble_sort(std::vector<double> &data);
    void shake_sort (std::vector<double> &data);

} // namespace Seredan
} // namespace Sort
} // namespace Algorithms

#endif // SORT_H
