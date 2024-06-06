from collections import deque

N = int(input())
checked = [True for i in range(N + 2)]

checked[1] = False

for i in range(2, int(N**0.5) + 1):
    if not checked[i]:
        continue

    for j in range(i * 2, N + 1, i):
        checked[j] = False

dq = deque([])
sw = False

S = 0

for i in range(1, N + 1):
    if not checked[i]:
        if sw:
            dq.appendleft("B")
        else:
            dq.append("B")
    else:
        if sw:
            if dq[0] == "B":
                dq.popleft()
                dq.appendleft("S")
                dq.appendleft("S")
                S += 2
            else:
                dq.appendleft("S")
                S += 1
        else:
            if dq[-1] == "B":
                dq.pop()
                dq.append("S")
                dq.append("S")
                S += 2
            else:
                dq.append("S")
                S += 1

        sw = not sw

print(N - S, S)
