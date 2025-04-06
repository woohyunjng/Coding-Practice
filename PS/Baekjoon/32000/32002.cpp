#include "library3.h"
#include <bits/stdc++.h>
using namespace std;

void solve(int N) {
    vector<int> arr, tmp;
    for (int i = 0; i < N; i++)
        arr.push_back(i);

    int X = query(arr), Y, st, en, md;

    for (int i = 1; i < N; i++) {
        X = query(arr);
        st = 0, en = i - 1, Y = i;

        while (st <= en) {
            md = st + en >> 1, tmp = arr;
            for (int j = 0; j + 1 <= md; j++)
                swap(tmp[j], tmp[j + 1]);
            swap(tmp[md], tmp[i]);
            if (X + md > query(tmp))
                en = md - 1, Y = md;
            else
                st = md + 1;
        }

        if (Y < i)
            swap(arr[Y], arr[i]);
    }

    answer(arr);
}
