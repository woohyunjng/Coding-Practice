from sys import stdin
from math import gcd

N = int(stdin.readline())
arr = []

for i in range(N):
    arr.append(int(stdin.readline()))

G = abs(arr[0] - arr[1])
for i in range(1, N - 1):
    G = gcd(G, abs(arr[i] - arr[i + 1]))

A, B = [], []
for i in range(1, int(G**0.5) + 1):
    if G % i:
        continue

    if i**2 != G:
        if i != 1:
            A.append(i)
        B.append(G // i)
    else:
        A.append(i)

if A:
    print(" ".join(map(str, A)), end=" ")
print(" ".join(map(str, reversed(B))))
