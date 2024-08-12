#include <bits/stdc++.h>
#define int long long

using namespace std;

int euler_phi(int N) {
    int res = N;
    for (int i = 2; i * i <= N; i++) {
        if (N % i)
            continue;
        while (!(N % i))
            N /= i;
        res /= i;
        res *= i - 1;
    }

    if (N != 1) {
        res /= N;
        res *= N - 1;
    }
    return res;
}