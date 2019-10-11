#include <bits/stdc++.h>
#define VEC_SIZE 10000
int binarySearch(std::vector<int>& array, int key) {
    // iterative implementation
    int start = 0;
    int end = (int)array.size()-1;
    int mid = 0;
    while (start <= end) {
        mid = start + (end-start) / 2;
        if (key == array[mid]) return key;
        if (key < array[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int binarySearchRecursive(std::vector<int>& array, int key, int start, int end) {
    // easier to write this way
    if (start <= end) {
        int mid = start + (end - start) / 2;
        if (array[mid] == key) return mid;
        if (array[mid] > key) {
            return binarySearchRecursive(array, key, start, mid-1);
        }
        return binarySearchRecursive(array, key, mid+1, end);
    }
    return -1;
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
    auto start = std::chrono::high_resolution_clock::now();
    int r1 = binarySearch(vec, 1);
    auto mid = std::chrono::high_resolution_clock::now();
    int r2 = binarySearchRecursive(vec, 1, 0, (int)vec.size()-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration1 = mid-start;
    auto duration2 = end-mid;
    std::cout << "Non-recursive binary search executed in " << duration1.count() << " ticks" << std::endl;
    std::cout << "Recursive binary search executed in " << duration2.count() << " ticks" << std::endl;
    std::cout << "Caching may be involved in this." << std::endl;
    // TODO: check if caches have anything to do with this result.
    return 0;
}