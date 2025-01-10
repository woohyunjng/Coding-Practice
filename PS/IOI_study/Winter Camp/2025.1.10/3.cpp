#include "twolist.h"
#include <bits/stdc++.h>

using namespace std;

int twolist(int N) {
    int st, en, mid, res;
    st = 1, en = N - 1, res = -1;

    while (st <= en) {
        mid = st + en >> 1;
        if (compare(mid, N - mid) == 1)
            res = mid, en = mid - 1;
        else
            st = mid + 1;
    }

    if (res == -1)
        return N;

    if (compare(res, N - res + 1))
        return N - res + 1 + N;
    else
        return res;
}
