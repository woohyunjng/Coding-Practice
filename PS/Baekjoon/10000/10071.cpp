#include "game.h"
#include <bits/stdc++.h>
using namespace std;

int cnt[1500];

void initialize(int n) {
    for (int i = 0; i < n; i++)
        cnt[i] = i;
}

int hasEdge(int U, int V) {
    if (U > V)
        swap(U, V);
    return --cnt[V] == 0;
}
