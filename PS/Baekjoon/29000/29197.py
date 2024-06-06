from sys import stdin
from math import gcd

N = int(stdin.readline())
st = set([])

for i in range(N):
    X, Y = map(int, stdin.readline().rstrip().split())
    G = gcd(X, Y)
    st.add((X // G, Y // G))

print(len(st))
