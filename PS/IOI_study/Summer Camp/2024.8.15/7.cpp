#include "search.h"
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pr;

int search(int N, int K) {
    int st = max(0, K - N - 1), en = min(N - 1, K - 1), md;

    while (st <= en) {
        md = st + en >> 1;
        if (K - md - 2 >= 0) {
            if (compare(md, K - md - 2))
                st = md + 1;
            else if (K - md - 1 < N) {
                if (!compare(md, K - md - 1))
                    en = md - 1;
                else
                    return md;
            } else
                return md;
        } else if (K - md - 1 < N) {
            if (!compare(md, K - md - 1))
                en = md - 1;
            else
                return md;
        } else
            return md;
    }

    return K - 2 - en + N;
}