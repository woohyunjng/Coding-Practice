#include "liar.h"

#include <bits/stdc++.h>
using namespace std;

int shout(int N, int a, int b, vector<int> S, int l, int r) { return l ^ r; }
int answer(int N, int a, int b, vector<int> T, int l, int r) {
    int ans, V = 0;
    bool flag;

    a--;
    for (int i : T)
        V ^= i;
    ans = l, flag = false;
    for (int i = (a + N - 1) % N; i != a; i = (i + 2) % N)
        ans ^= T[(i + 1) % N], flag |= (i + 1) % N == 0;
    if ((a == 0 && flag) || (a != 0 && !flag))
        ans ^= V;
    return ans;
}