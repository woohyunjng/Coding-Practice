S = input()
A, B, lst = 0, 0, -1

for i in S:
    if i != lst:
        lst = i
        if i == "1":
            B += 1
        else:
            A += 1

print(min(A, B))
