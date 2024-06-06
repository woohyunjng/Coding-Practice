from collections import deque

while True:
    S = input()
    A, check = deque([]), False

    if S == ".":
        break

    for i in S:
        if i == "(":
            A.append(0)
        elif i == "[":
            A.append(1)
        elif i == ")":
            if not len(A) or A.pop():
                check = True
                break
        elif i == "]":
            if not len(A) or not A.pop():
                check = True
                break

    if len(A):
        check = True

    print("no" if check else "yes")
