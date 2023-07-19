from collections import deque

n = int(input())
q, cnt = deque(), 0
l, check = [], False

for i in range(n):
    j = int(input())
    while cnt < j:
        cnt += 1
        l.append("+")
        q.append(cnt)

    if q[-1] == j:
        q.pop()
        l.append("-")
    else:
        check = True
        break

if check:
    print("NO")
else:
    for i in l:
        print(i)
