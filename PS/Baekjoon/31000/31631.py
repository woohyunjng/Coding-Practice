from collections import deque

N = int(input())
start = deque([])
end = deque([])

go = 1
for i in range(N, N % 2, -2):
    if go == 1:
        end.appendleft(i)
        start.append(i - 1)
    else:
        start.append(i)
        end.appendleft(i - 1)
    go = -go

if N % 2:
    start.append(1)
print(*(start + end))
