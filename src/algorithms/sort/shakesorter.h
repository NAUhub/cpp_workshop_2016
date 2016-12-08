#ifndef SHAKESORTER_H
#define SHAKESORTER_H

namespace Algorithms {
namespace Sort {

class ShakeSorter {
    public:
        template <class Data, template <class D, class Allocator = std::allocator<D> > class Container>
        static void sort(Container<Data> &data);
};

template <class Data, template <class D, class Allocator = std::allocator<D> > class Container>
void ShakeSorter::sort(Container<Data> &data) {
    if (data.size() > 1) {
        typename Container<Data>::iterator lit = data.end();
        lit--;
        typename Container<Data>::iterator fit = data.begin();
        for(;;) {
            for (typename Container<Data>::iterator it = fit; it != lit; ++it) {
                typename Container<Data>::iterator nit = it;
                nit++;
                if (*it > *nit) {
                    std::swap(*it, *nit);
                }
            }
            if (lit == fit) break;
            lit--;
            for (typename Container<Data>::iterator it = lit; it != fit; --it) {
                typename Container<Data>::iterator nit = it;
                nit--;
                if (*it < *nit) {
                    std::swap(*it, *nit);
                }
            }
            if (lit == fit) break;
            fit++;
        }
    }
}

} // namespace Sort
} // namespace Algorithms

#endif // SHAKESORTER_H
