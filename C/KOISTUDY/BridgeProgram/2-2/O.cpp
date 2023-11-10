#include <iostream>
using namespace std;

int main()
{
    int A, B, C, i;
    cin >> A >> B >> C;

    for (i = A; (i % B) || (i % C); i += A)
        continue;

    cout << i;
}