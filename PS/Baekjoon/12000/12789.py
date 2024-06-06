from collections import deque

N = int(input())
st = deque([])
cnt = 1

arr = list(map(int, input().split()))
for i in arr:
    if i == cnt:
        cnt += 1
    else:
        st.append(i)

    while len(st) and st[-1] == cnt:
        st.pop()
        cnt += 1

if cnt == N + 1:
    print("Nice")
else:
    print("Sad")
