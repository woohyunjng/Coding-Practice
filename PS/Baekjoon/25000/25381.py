S = input()
res = 0
A, B, AB = 0, 0, 0

for i in S:
    if i == "A":
        A += 1
    elif i == "B":
        if A:
            A -= 1
            AB += 1
        else:
            B += 1
    elif i == "C":
        if B:
            B -= 1
            res += 1
        elif AB:
            AB -= 1
            A += 1
            res += 1

print(res + AB)
