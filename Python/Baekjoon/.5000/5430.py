from collections import deque

T = int(input())
for i in range(T):
    p = input()
    n = int(input())

    if n > 0:
        x = deque(map(int, input().lstrip("[").rstrip("]").split(",")))
    else:
        input()
        x = deque([])

    front, error = True, False
    for i in p:
        if i == "R":
            front = not front
        else:
            if front:
                if len(x):
                    x.popleft()
                else:
                    error = True
                    break
            else:
                if len(x):
                    x.pop()
                else:
                    error = True
                    break
    
    if error:
        print("error")
        continue

    if not front:
        x = reversed(x)

    print("[" + ",".join(map(str, x)) + "]")
