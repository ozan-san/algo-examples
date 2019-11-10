#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int fib_naive(int n) {
    if (n==1 || n == 2) {
        return 1;
    } else {
        return fib_naive(n-1) + fib_naive(n-2);
    }
}

int fib_dynamic(int n) {
    vector<int> results = {0, 1, 1};
    results.resize(n+1);
    if (n<=2) return results[n];
    else {
        for (int i=3; i<=n; i++) {
            results[i] = results[i-1] + result[i-2];
        }
    }
    return results[n];
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}