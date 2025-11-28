#include <iostream>
#include <memory>


// Strategy ինտերֆեյս
class SortStrategy {
public:
    virtual void sort() = 0;
    virtual ~SortStrategy() {}
};

// Կոնկրետ ստրատեգիաներ
class QuickSort : public SortStrategy {
public:
    void sort() override { std::cout << "Sorting using QuickSort\n"; }
};

class MergeSort : public SortStrategy {
public:
    void sort() override { std::cout << "Sorting using MergeSort\n"; }
};

class BubbleSort : public SortStrategy {
public:
    void sort() override { std::cout << "Sorting using BubbleSort\n"; }
};

// Context
class DataSet {
	std::unique_ptr<SortStrategy> strategy;
public:
    void setStrategy(SortStrategy* s) {
        strategy.reset(s);
    }
    void sortData() {
        if (strategy) strategy->sort();
        else std::cout << "No strategy set!\n";
    }
};

// --- Օգտագործում ---
int main() {
    DataSet data;

    data.setStrategy(new QuickSort());
    data.sortData();   //  QuickSort

    data.setStrategy(new MergeSort());
    data.sortData();   //  MergeSort

    data.setStrategy(new BubbleSort());
    data.sortData();   //  BubbleSort

}

