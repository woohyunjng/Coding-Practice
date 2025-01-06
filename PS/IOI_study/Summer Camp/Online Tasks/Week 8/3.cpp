#include "treedist.h"
#include <bits/stdc++.h>

using namespace std;

int get(int X) {
    int res = 0;
    while (!same())
        climb(X), res++;
    return res;
}

int get_distance() {
    int X[2] = {0, 0}, cur = 0;
    if (same())
        return 0;

    while (true) {
        if (climb(cur))
            X[cur]++;
        if (same()) {
            reset(cur ^ 1);
            cout << cur << ' ' << X[0] << ' ' << X[1] << '\n';
            return X[cur] + get(cur ^ 1);
        }
        cur ^= 1;
    }
}
