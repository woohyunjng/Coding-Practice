#include "festival.h"
#include <bits/stdc++.h>
using namespace std;

int answer(int N, int K, int i, vector<int> arr) {
    return K - accumulate(arr.begin(), arr.end(), 0) % K;
}