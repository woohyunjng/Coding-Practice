from math import log2
from sys import stdin

Q = int(stdin.readline().rstrip())
for i in range(Q):
    a = int(stdin.readline().rstrip())
    print(int(log2(a).is_integer()))
