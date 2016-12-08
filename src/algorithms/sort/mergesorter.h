#ifndef MERGESORTER_H
#define MERGESORTER_H

namespace Algorithms {
namespace Sort {

class MergeSorter {
    public:
        template <class Data, template <class D, class Allocator = std::allocator<D> > class Container>
        static void sort(Container<Data> &data) {}
};

} // namespace Sort
} // namespace Algorithms

#endif // MERGESORTER_H
