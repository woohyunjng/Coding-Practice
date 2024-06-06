from collections import deque

A = input()
B = deque(input())
reverse = False

while len(B) > len(A):
    print(B, reverse)
    if reverse:
        if B[-1] == "B":
            B.pop()
            reverse = False
        elif B[0] == "A":
            B.popleft()
        else:
            print(0)
            exit()
    else:
        if B[0] == "B":
            B.popleft()
            reverse = True
        elif B[-1] == "A":
            B.pop()
        else:
            print(0)
            exit()

if reverse:
    B = list(reversed(B))
B = "".join(B)

if A == B:
    print(1)
else:
    print(0)
