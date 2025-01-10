#include "minmax.h"
#include <bits/stdc++.h>

using namespace std;

int find_minmax(int N) {
    int A = 1, B = 1, X;

    vector<int> arr, temp, arr2;
    for (int i = 1; i <= N; i++)
        arr.push_back(i);
    if (N == 1)
        return 38;

    while (arr.size() > 1) {
        for (int i = 1; i + 1 <= arr.size(); i += 2) {
            X = get_larger_index(arr[i - 1], arr[i]);
            if (arr.size() == N)
                arr2.push_back(arr[i - 1] + arr[i] - X);
            temp.push_back(X);
        }
        if (arr.size() % 2 == 1) {
            temp.push_back(arr.back());
            if (arr.size() == N)
                arr2.push_back(arr.back());
        }
        arr = temp, temp.clear();
    }
    B = arr[0];

    arr = arr2;
    while (arr.size() > 1) {
        for (int i = 1; i + 1 <= arr.size(); i += 2)
            temp.push_back(arr[i - 1] + arr[i] - get_larger_index(arr[i - 1], arr[i]));
        if (arr.size() % 2 == 1)
            temp.push_back(arr.back());
        arr = temp, temp.clear();
    }
    A = arr[0];

    return A * 37 + B;
}