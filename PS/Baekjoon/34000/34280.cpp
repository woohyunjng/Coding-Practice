#include "rotate.h"
#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

void energy(int N, vector<int> V) {
    vector<pr> arr;
    for (int i = 0; i < N; i++)
        arr.push_back({V[i], i});
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N / 2; i++)
        rotate({arr[i][1]}, arr[i + (N + 1) / 2][0] - arr[i][0] + 25000);
}