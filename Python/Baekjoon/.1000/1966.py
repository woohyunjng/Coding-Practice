from collections import deque

T = int(input())

for i in range(T):
    N, M = map(int, input().split())
    a = list(map(int, input().split()))
    b = deque(sorted(a, reverse=True))

    for j in range(N):
        a[j] = [j, a[j]]

    a = deque(a)
    j = 0

    while True:
        k = a.popleft()
        if k[1] < b[0]:
            a.append(k)
        else:
            b.popleft()
            j += 1
            if k[0] == M:
                print(j)
                break
