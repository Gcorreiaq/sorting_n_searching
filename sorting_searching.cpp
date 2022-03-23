#include <iostream>
#include "sorting_n_searching.hpp"

int main()
{
    int key;
    int array_size = 100;
    int * arrays[5];
    for (int i = 0;i < 5;i++) arrays[i] = {new int[array_size]{}}; //Creates 3 int arrays
    random_array(arrays[0], array_size); // fills the first array with random data
    for (int i = 1;i < 5;i++) 
        for (int j = 0;j < 100;j++) 
            arrays[i][j] = arrays[0][j]; // copies array[0] to the remaining arrays
    std::cout << "Array: ";
    print_array(arrays[0], array_size);
    std::cout << '\n';

    // all the functions return how many accesses to the memory they made
    std::cout << "Insertion Sort: " << insertion_sort(arrays[0], array_size) << '\n';
    std::cout << "Selection Sort: " << selection_sort(arrays[1], array_size) << '\n';
    std::cout << "Bubble Sort: " << bubble_sort(arrays[2], array_size) << '\n';
    loop = 0; // for the matter of performance, loop is nullified here for quick_sort
    quick_sort(arrays[3], array_size);
    std::cout << "Quick Sort: " << loop << "\n\n";

    std::cout << "Sorted array: ";
    print_array(arrays[3], array_size); // all arrays are sorted now
    std::cout << "\nChoose a number: ";
    std::cin >> key;
    int a = binary_search(arrays[0], key, array_size);
    if (a != -1) std::cout << key << " is the " << a << " element\n";
    else std::cout << "Not found\n";
    return 0;
}