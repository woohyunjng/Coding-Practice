#include <bits/stdc++.h>
#define int long long
using namespace std;

bool is_prime(int N) {
    bool res = true;
    for (int i = 2; i * i <= N; i++) {
        if (!(N % i)) {
            res = false;
            break;
        }
    }
    return res;
}