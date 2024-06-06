from collections import deque

N, K = map(int, input().split())
S = list(map(int, input()))

st = deque([0])

use = -1
for i in S:
    while len(st) and use < K and st[-1] < i:
        st.pop()
        use += 1
    st.append(i)

while use < K:
    st.pop()
    use += 1
print("".join(map(str, st)))
