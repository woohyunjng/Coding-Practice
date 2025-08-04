#include "stub.h"
#include <bits/stdc++.h>
using namespace std;

void swapCards(int cards[], int S, int T) {
    int idx[52], X, Y;
    bool chk[52] = {false};

    for (int i = 0; i < 52; i++)
        idx[cards[i]] = i;

    for (int i = 0; i < 52; i++) {
        if (chk[i])
            continue;
        X = i, Y = 1, chk[i] = true;
        while (Y < T && !chk[cards[X]])
            X = cards[X], chk[X] = true, Y++;
        if (chk[cards[X]])
            continue;
        doSwap(X, idx[i]);
        idx[cards[X]] = idx[i], cards[idx[i]] = cards[X];
    }
}

void guessCard(int S, int T, int target) {
    int V = target;
    while (true) {
        V = guess(V);
        if (V == target)
            return;
    }
}
