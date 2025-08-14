#include "insects.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;

bool chk[MAX];

int min_cardinality(int N) {
    int st, en, md, K = N, S, ans = 1;
    bool flag = true;
    vector<int> stk;

    for (int i = 0; i < N; i++) {
        move_inside(i), chk[i] = true;
        if (press_button() > 1)
            move_outside(i), chk[i] = false, K--;
    }
    S = K, en = N / K;

    st = 2, en = N / K;
    while (st <= en) {
        md = (st + en + (en - st > 5)) >> 1, stk.clear();
        for (int i = 0; i < N; i++) {
            if (chk[i])
                continue;
            if (S == md * K)
                break;
            move_inside(i), stk.push_back(i), chk[i] = true, S++;
            if (press_button() > md)
                move_outside(i), stk.pop_back(), chk[i] = false, S--;
        }

        if (S == md * K)
            st = md + 1, ans = md;
        else {
            fill(chk, chk + N, true);
            while (!stk.empty())
                move_outside(stk.back()), chk[stk.back()] = false, stk.pop_back(), S--;
            en = md - 1;
        }
    }

    return ans;
}