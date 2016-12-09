#ifndef MERGESORTER_H
#define MERGESORTER_H

#include <algorithm>

namespace Algorithms {
namespace Sort {

enum MergeSortType {
    Recursive,
    BottomUp
};

template <MergeSortType SortType = BottomUp>
class MergeSorter {
    public:
        template <class Data, template <class D, class Allocator = std::allocator<D> > class Container>
        static void sort(Container<Data> &data);

    protected:
        template <class Iterator,
                  template <class D, class Allocator = std::allocator<D> > class Container = std::vector>
        static void merge(Iterator &from, Iterator &mid, Iterator &to);
};

template <MergeSortType SortType>
template <class Data, template <class D, class Allocator = std::allocator<D> > class Container>
void MergeSorter<SortType>::sort(Container<Data> &data) {
    // sort left half
    if (data.size() > 1) {
        typename Container<Data>::iterator from = data.begin();
        typename Container<Data>::iterator mid  = data.begin();
        std::advance(mid, data.size() / 2);
        typename Container<Data>::iterator to   = data.end();
        merge(from, mid, to);
    }
}

template <MergeSortType SortType>
template <class Iterator,
          template <class D, class Allocator = std::allocator<D> > class Container>
void MergeSorter<SortType>::merge(Iterator &from, Iterator &mid, Iterator &to) {
    // sort left half
    size_t elements_count = std::distance(from, mid);
    if (elements_count > 1) {
        Iterator temp_mid = from;
        std::advance(temp_mid, elements_count / 2);
        merge(from, temp_mid, mid);
    }

    // sort right half
    elements_count = std::distance(mid, to);
    if (elements_count > 1) {
        Iterator temp_mid = mid;
        std::advance(temp_mid, elements_count / 2);
        merge(mid, temp_mid, to);
    }

    // merge sorted parts
    elements_count = std::distance(from, to);
    if (elements_count > 0) {
        Container<typename std::iterator_traits<Iterator>::value_type> buffer(elements_count);
        Iterator lit = from;
        Iterator rit = mid;
        for (typename Container<typename std::iterator_traits<Iterator>::value_type>::iterator bit = buffer.begin(); bit != buffer.end(); ++bit) {
            if      (lit == mid)    *bit = *rit++;
            else if (rit == to)     *bit = *lit++;
            else                    *bit = *lit < *rit ? *lit++ : *rit++;
        }
        std::copy(buffer.begin(), buffer.end(), from);
    }
}

// Specialization

template <>
class MergeSorter<BottomUp> {
    public:
        template <class Data, template <class D, class Allocator = std::allocator<D> > class Container>
        static void sort(Container<Data> &data);

    protected:
        template <class Iterator,
                  template <class D, class Allocator = std::allocator<D> > class Container = std::vector>
        static void merge(Iterator &from, Iterator &to, int elements);
};

template <class Data, template <class D, class Allocator = std::allocator<D> > class Container>
void MergeSorter<BottomUp>::sort(Container<Data> &data) {
    if (data.size() > 1) {
        typename Container<Data>::iterator lit = data.begin();
        typename Container<Data>::iterator rit = data.end();
        for (int i=1; i<data.size(); i*=2) {
            merge(lit, rit, i);
        }
    }
}

template <class Iterator,
          template <class D, class Allocator = std::allocator<D> > class Container>
void MergeSorter<BottomUp>::merge(Iterator &from, Iterator &to, int elements) {
    if (elements > 0) {

        Iterator t_from = from;
        Iterator t_mid =  t_from;
        Iterator t_to   = t_from;

        int l_to_end = std::distance(t_from, to);
        for (;;) {
            int l_count = std::min(elements, l_to_end);
            int r_count = std::min(elements, l_to_end-l_count);
            t_mid = t_from;
            std::advance(t_mid, l_count);
            t_to  = t_mid;
            std::advance(t_to, r_count);

            int elements_count = l_count + r_count;

            // merge sorted parts
            if (elements_count > 0) {
                Container<typename std::iterator_traits<Iterator>::value_type> buffer(elements_count);
                Iterator lit = t_from;
                Iterator rit = t_mid;
                for (typename Container<typename std::iterator_traits<Iterator>::value_type>::iterator bit = buffer.begin(); bit != buffer.end(); ++bit) {
                    if      (lit == t_mid)  *bit = *rit++;
                    else if (rit == t_to)   *bit = *lit++;
                    else                    *bit = *lit < *rit ? *lit++ : *rit++;
                }
                std::copy(buffer.begin(), buffer.end(), t_from);
            }

            elements_count = std::min(elements_count, l_to_end);
            std::advance(t_from, elements_count);
            l_to_end -= elements_count;

            if (l_to_end < 1) {
                break;
            }
        }
    }
}


} // namespace Sort
} // namespace Algorithms

#endif // MERGESORTER_H
