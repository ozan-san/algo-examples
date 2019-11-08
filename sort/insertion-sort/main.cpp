#include <bits/stdc++.h>
#define VEC_SIZE 1000
void insertionSort(std::vector<int>& array) {
    int i, key, j;
    int n = array.size();
    for (i = 1; i<n; i++) {
        key = array[i];
        j = i+1;

        while (j >= 0 and array[j] > key) {
            // move them to the left, then.
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key; // now time to re-insert.
    }
}

int main() {
    // timing
    std::vector<int> vec;
    for (int i=0; i<VEC_SIZE; i++) {
        vec.push_back(i);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
    std::cout << "Vector after shuffle: ";
    for (int i=0; i<(VEC_SIZE)/100; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Vector after sort: ";
    for (int i=0; i<(VEC_SIZE)/100; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    auto duration = end-start;
    std::cout << "This took " << duration.count() << " ticks. Goodbye." << std::endl;
    return 0;
}