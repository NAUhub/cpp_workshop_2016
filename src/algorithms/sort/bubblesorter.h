#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

#include <algorithm>

namespace Algorithms {
namespace Sort {

class BubbleSorter {
    public:
        template <class Data, template <class D, class Allocator = std::allocator<D> > class Container>
        static void sort(Container<Data> &data);
};

template <class Data, template <class D, class Allocator = std::allocator<D> > class Container>
void BubbleSorter::sort(Container<Data> &data) {
    if (data.size() > 1) {
        typename Container<Data>::const_iterator lit = data.end();
        lit--;
        for (; lit != data.begin(); --lit) {
            for (typename Container<Data>::iterator it = data.begin(); it != lit; ++it) {
                typename Container<Data>::iterator nit = it;
                nit++;
                if (*it > *nit) {
                    std::swap(*it, *nit);
                }
            }
        }
    }
}

} // namespace Sort
} // namespace Algorithms

#endif // BUBBLESORTER_H
