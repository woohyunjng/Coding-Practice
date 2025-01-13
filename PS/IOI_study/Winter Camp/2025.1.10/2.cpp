#include "kong.h"
#include <bits/stdc++.h>

#define MAX 3000

using namespace std;

vector<int> fail[MAX];

int get(vector<int> &arr) {
    if (arr.size() == 1)
        return arr[0];

    vector<int> temp;
    for (int i = 1; i + 1 <= arr.size(); i += 2) {
        if (compare(arr[i - 1], arr[i]) == 1)
            temp.push_back(arr[i - 1]), fail[arr[i - 1]].push_back(arr[i]);
        else
            temp.push_back(arr[i]), fail[arr[i]].push_back(arr[i - 1]);
    }
    if (arr.size() % 2 == 1)
        temp.push_back(arr.back());
    return get(temp);
}

int kong(int N) {
    vector<int> arr;
    for (int i = 1; i <= N; i++)
        arr.push_back(i);
    return get(fail[get(arr)]);
}
