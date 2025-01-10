#include "kong.h"
#include <bits/stdc++.h>

using namespace std;

int kong(int N) {
    vector<int> arr, temp;
    vector<vector<int>> fail(N + 1);
    int res;

    for (int i = 1; i <= N; i++)
        arr.push_back(i);
    while (arr.size() > 1) {
        temp.clear();
        for (int i = 1; i + 1 <= arr.size(); i += 2) {
            if (compare(arr[i - 1], arr[i]) == 1)
                temp.push_back(arr[i - 1]), fail[arr[i - 1]].push_back(arr[i]);
            else
                temp.push_back(arr[i]), fail[arr[i]].push_back(arr[i - 1]);
        }
        if (arr.size() % 2 == 1)
            temp.push_back(arr.back());
        swap(arr, temp);
    }
    res = arr[0], arr = fail[res];

    while (arr.size() > 1) {
        temp.clear();
        for (int i = 1; i + 1 <= arr.size(); i += 2) {
            if (compare(arr[i - 1], arr[i]) == 1)
                temp.push_back(arr[i - 1]);
            else
                temp.push_back(arr[i]);
        }
        if (arr.size() % 2 == 1)
            temp.push_back(arr.back());
        swap(arr, temp);
    }

    return arr[0];
}
