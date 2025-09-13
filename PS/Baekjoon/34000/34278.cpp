#include "hack.h"
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1'000'000'000;

signed hack() {
    int st = MAX / 2 + 1, en = MAX, md, V, X;
    vector<int> tmp, arr;

    while (st <= en) {
        md = st + en >> 1, tmp.clear();
        X = (int)sqrt(md - st + 1);
        for (int i = 1; i <= X; i++)
            tmp.push_back(i);
        for (int i = 1; st + i * X <= md; i++)
            tmp.push_back(st + i * X);
        tmp.push_back(md + 1);

        if (collisions(tmp) > 0)
            en = md - 1, V = md;
        else
            st = md + 1;
    }

    X = V;
    for (int i = 2; i * i <= V; i++) {
        if (X % i)
            continue;
        arr.push_back(i);
        while (X % i == 0)
            X /= i;
    }
    if (X > 1)
        arr.push_back(X);

    for (int i : arr) {
        while (V % i == 0 && collisions({1, V / i + 1}) > 0)
            V /= i;
    }

    return V;
}