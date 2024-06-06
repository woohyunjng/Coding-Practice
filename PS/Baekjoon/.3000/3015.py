from collections import deque
from sys import stdin

N = int(stdin.readline())
arr = []

for i in range(N):
    arr.append(int(stdin.readline()))

st = deque([])
res = 0

for i in arr:
    val = 1
    while len(st) and st[-1][0] <= i:
        res += st[-1][1]
        if st[-1][0] == i:
            val += st[-1][1]
        st.pop()

    if len(st):
        res += 1
    st.append((i, val))

print(res)
