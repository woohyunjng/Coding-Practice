#include <bits/stdc++.h>
using namespace std;

extern int count_pair(int, int, int);
extern int find_character(int, vector<int>);

int guess_palindromicity(int N) {
    vector<int> arr;
    int X;
    bool ans = true;

    for (int i = 1; i < N / 2; i++) {
        X = count_pair(0, i, N - 1 - i);
        if (X == 3)
            continue;
        else if (X == 0)
            ans = false;
        else
            arr.push_back(i), arr.push_back(N - 1 - i);
    }

    ans &= find_character(0, arr) == 0;

    if (arr.empty())
        ans &= count_pair(0, 1, N - 1) == 3;
    else
        ans &= count_pair(0, N - 1, *arr.begin()) == 1;

    return ans;
}
