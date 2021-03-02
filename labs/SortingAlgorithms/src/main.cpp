#include <iostream>
#include <vector>
#include <random>
#include <array>
#include <map>
#include <assert.h>
#include <iomanip>

#include "chrono.h"

#include "stlsort.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "shellsort.h"

void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        std::cout << input.at(i) << ' ';
    }
    std::cout << std::endl;
}

std::vector<int> get_random_vector(int size)
{
    std::vector<int> v(size);

    // Fast pseudo random number generator
    // We don't really care if it is really random, as long as it looks random
    int g_seed = 123456;
    for (int i = 0; i < size; i++)
    {
        g_seed = (214013 * g_seed + 2531011);
        v[i] = (g_seed >> 16) & 0x7FFF;
    }

    return v;
}

std::vector<int> get_sorted_vector(int size)
{
    std::vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        v[i] = i;
    }
    return v;
}

std::vector<int> get_reverse_sorted_vector(int size)
{
    std::vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        v[i] = size - i;
    }
    return v;
}

bool is_sorted(std::vector<int> &data)
{
    int i = 0;
    while (i < data.size() - 1 && data[i + 1] >= data[i])
    {
        i++;
    }
    return i == data.size() - 1;
}

void measure(std::map<std::string, SortingAlgorithm *> sortingmethods, std::vector<int> &data)
{
    Chrono chrono;

    std::cout << std::setw(12) << data.size() << "\t";
    for (auto it = sortingmethods.begin(); it != sortingmethods.end(); it++)
    {
        std::vector<int> copy = data;
        chrono.start();
        //print(copy);
        it->second->sort(copy);
        chrono.stop();
        std::cout << std::setw(12) << chrono.time() << "\t";
        //print(copy);
        assert(is_sorted(copy));
    }
    std::cout << std::endl;
}

void run(std::map<std::string, SortingAlgorithm *> sortingmethods, int min, int max, int delta, std::vector<int> (*f)(int))
{
    std::cout << std::setw(12) << "Input size"
              << "\t";
    for (auto it = sortingmethods.begin(); it != sortingmethods.end(); it++)
    {
        std::cout << std::setw(12) << it->first << "\t";
    }
    std::cout << std::endl;
    for (int size = min; size <= max; size += delta)
    {
        std::vector<int> v = f(size);
        measure(sortingmethods, v);
    }
}

int main()
{
    std::map<std::string, SortingAlgorithm *> sortingmethods;
    sortingmethods["StlSort"] = new STLSort();
    sortingmethods["SelectionSort"] = new SelectionSort();
    sortingmethods["InsertionSort"] = new InsertionSort();
    sortingmethods["ShellSort"] = new ShellSort();

    int min = 10000;
    int max = 100000;
    int step = 10000;

    std::cout << "Random input" << std::endl;
    run(sortingmethods, min, max, step, get_random_vector);

    std::cout << std::endl
              << "Sorted input" << std::endl;
    run(sortingmethods, min, max, step, get_sorted_vector);

    std::cout << std::endl
              << "Inverse sorted input" << std::endl;
    run(sortingmethods, min, max, step, get_reverse_sorted_vector);

    for (auto it : sortingmethods)
    {
        delete it.second;
    }
    return 0;
}