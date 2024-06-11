#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> compressed;

void compress(vector<int> arr)
{
    compressed = arr;
    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
}

int get_id(int A) { return lower_bound(compressed.begin(), compressed.end(), A) - compressed.begin(); }
