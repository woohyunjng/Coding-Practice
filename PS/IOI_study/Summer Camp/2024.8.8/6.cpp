#include "subarraymin.h"
#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

void subarray_min(signed N, signed K) {
    deque<int> dq;

    for (int i = 1; i <= N; i++) {
        while (!dq.empty() && dq.front() <= i - K)
            dq.pop_front();
        while (!dq.empty() && compare(i, dq.back()))
            dq.pop_back();
        dq.push_back(i);

        if (i >= K)
            answer(i - K + 1, dq.front());
    }
}