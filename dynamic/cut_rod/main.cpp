#include <bits/stdc++.h>
/*
 * Suppose you have a rod of length n,
 * and you want to cut up the rod and
 * sell the pieces ina way that maximizes
 * the total amount of money you get.
 * A piece of length i is worth p_i dollars.
 * */
using namespace std;
int cut_rod_naive(vector<int>& p, int n) {
    if (n==0) return 0;
    int q = -1;
    for (int i=1; i<=n; i++) {
        q = max(q, p[i] + cut_rod_naive(p, n-i));
    }
    return q;
}

int memoized_cut_rod_aux(vector<int>& p, int n, vector<int>& r) {
    if (r[n] >= 0) return r[n];
    int q;
    if (n==0) {
        q = 0;
    } else {
        q = -1;
        for (int i=1; i<=n; i++) {
            q = max(q, p[i] + memoized_cut_rod_aux(p,n-i,r));
        }
    }
    r[n] = q;
    return q;
}


int memoized_cut_rod(vector<int>& p,int n) {
    vector<int> r(n+1, -1);
    return memoized_cut_rod_aux(p,n,r);
}

int bottom_up_cut_rod(vector<int>& p, int n) {
    vector<int> r(n+1,0);
    for (int j=1; j<=n; j++) {
        int q = -1;
        for (int i=1; i<=j; i++) {
            q = max(q, p[i] + r[j-i]);
        }
        r[j] = q;
    }
    return r[n];
}
int main() {
    // given examples.
    vector<int> costs = {-1, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout << "Naive solution " <<  cut_rod_naive(costs, 4) << endl;
    cout << "Memoized solution " <<  memoized_cut_rod(costs, 4) << endl;
    cout << "Bottom up solution " << bottom_up_cut_rod(costs, 4) << endl;
    return 0;
}