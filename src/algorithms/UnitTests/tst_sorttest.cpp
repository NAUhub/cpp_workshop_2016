#include <QString>
#include <QtTest>

#include "sort.h"

class SortTest : public QObject {
    Q_OBJECT

    public:
        SortTest() {}

    private Q_SLOTS:
        void bubbleSort();
        void bubbleSortBenchmark();
        void shakeSort();
        void shakeSortBenchmark();
        void templateSort();
        void templateSortBenchmark();
};


void SortTest::bubbleSort() {
    // Generate random order data
    int N = 10000;
    std::vector<double> random_data(N);
    qsrand(0);
    for (int i = 0; i < N; ++i) {
        random_data[i] = (double)qrand() / (double)RAND_MAX;
    }

    Algorithms::Sort::bubble_sort(random_data);

    // Test if data is sorted in accending order
    for (int i = 0; i < N-1; ++i) {
        QVERIFY2(random_data[i] <= random_data[i+1], QString("%1[%2] > %3[%4]").arg(random_data[i]).arg(i).arg(random_data[i+1]).arg(i+1).toLocal8Bit());
    }
}

void SortTest::bubbleSortBenchmark() {
    // Generate random order data
    int N = 10000;
    std::vector<double> random_data(N);
    qsrand(0);
    for (int i = 0; i < N; ++i) {
        random_data[i] = (double)qrand() / (double)RAND_MAX;
    }

    // Sort data
    QBENCHMARK {
        Algorithms::Sort::bubble_sort(random_data);
    }
}

void SortTest::shakeSort() {
    // Generate random order data
    int N = 10000;
    std::vector<double> random_data(N);
    qsrand(0);
    for (int i = 0; i < N; ++i) {
        random_data[i] = (double)qrand() / (double)RAND_MAX;
    }

    Algorithms::Sort::shake_sort(random_data);

    // Test if data is sorted in accending order
    for (int i = 0; i < N-1; ++i) {
        QVERIFY2(random_data[i] <= random_data[i+1], QString("%1[%2] > %3[%4]").arg(random_data[i]).arg(i).arg(random_data[i+1]).arg(i+1).toLocal8Bit());
    }
}

void SortTest::shakeSortBenchmark() {
    // Generate random order data
    int N = 10000;
    std::vector<double> random_data(N);
    qsrand(0);
    for (int i = 0; i < N; ++i) {
        random_data[i] = (double)qrand() / (double)RAND_MAX;
    }

    // Sort data
    QBENCHMARK {
        Algorithms::Sort::shake_sort(random_data);
    }

}

void SortTest::templateSort() {
    // Generate random order data
    int N = 10;
    std::vector<double> random_data(N);
    qsrand(0);
    for (int i = 0; i < N; ++i) {
        random_data[i] = (double)qrand() / (double)RAND_MAX;
    }

    Algorithms::Sort::sort<Algorithms::Sort::BubbleSorter>(random_data);

    // Test if data is sorted in accending order
    for (int i = 0; i < N-1; ++i) {
        QVERIFY2(random_data[i] <= random_data[i+1], QString("%1[%2] > %3[%4]").arg(random_data[i]).arg(i).arg(random_data[i+1]).arg(i+1).toLocal8Bit());
    }

    for (int i = 0; i < N; ++i) {
        random_data[i] = (double)qrand() / (double)RAND_MAX;
    }
    Algorithms::Sort::sort<Algorithms::Sort::ShakeSorter>(random_data);

    // Test if data is sorted in accending order
    for (int i = 0; i < N-1; ++i) {
        QVERIFY2(random_data[i] <= random_data[i+1], QString("%1[%2] > %3[%4]").arg(random_data[i]).arg(i).arg(random_data[i+1]).arg(i+1).toLocal8Bit());
    }
}

void SortTest::templateSortBenchmark() {
    // Generate random order data
    int N = 10000;
    std::vector<double> random_data(N);
    qsrand(0);
    for (int i = 0; i < N; ++i) {
        random_data[i] = (double)qrand() / (double)RAND_MAX;
    }

    // Sort data
    QBENCHMARK {
        Algorithms::Sort::sort<Algorithms::Sort::BubbleSorter>(random_data);
    }

    for (int i = 0; i < N; ++i) {
        random_data[i] = (double)qrand() / (double)RAND_MAX;
    }

    // Sort data
    QBENCHMARK {
        Algorithms::Sort::sort<Algorithms::Sort::ShakeSorter>(random_data);
    }
}

QTEST_APPLESS_MAIN(SortTest)
#include "tst_sorttest.moc"
