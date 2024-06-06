from collections import deque

N = int(input())
A = [[] for i in range(27)]

for i in range(N):
    x, y, z = input().split()

    A[ord(x) - 64].append(ord(y) - 64 if y != "." else 0)
    A[ord(x) - 64].append(ord(z) - 64 if z != "." else 0)

q = deque([1])
while len(q):
    p = q.pop()
    print(chr(p + 64), end="")
    for i in reversed(A[p]):
        if i:
            q.append(i)
print()

q = deque([1])
checked = [False for i in range(27)]
checked[0] = True
while len(q):
    p = q[-1]
    checked[p] = True

    if not checked[A[p][0]]:
        q.append(A[p][0])
    else:
        q.pop()
        if not checked[A[p][1]]:
            q.append(A[p][1])
        print(chr(p + 64), end="")
        continue
print()

q = deque([1])
checked = [False for i in range(27)]
checked[0] = True
while len(q):
    p = q[-1]
    checked[p] = True

    if not checked[A[p][0]]:
        q.append(A[p][0])
    elif not checked[A[p][1]]:
        q.append(A[p][1])
    else:
        q.pop()
        print(chr(p + 64), end="")
        continue
print()
