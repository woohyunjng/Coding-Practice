#include <iostream>
using namespace std;

int main()
{
    int N, i = 1;
    cin >> N;
    while (N - i > 0)
        N -= i++;
    cout << i;
}