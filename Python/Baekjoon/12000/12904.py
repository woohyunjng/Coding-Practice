from collections import deque

A = input()
B = deque(input())
reverse = False

while len(B) > len(A):
    if reverse:
        if B[0] == "A":
            B.popleft()
        else:
            B.popleft()
            reverse = False
    else:
        if B[-1] == "A":
            B.pop()
        else:
            B.pop()
            reverse = True

if reverse:
    B = list(reversed(B))
B = "".join(B)

if A == B:
    print(1)
else:
    print(0)
