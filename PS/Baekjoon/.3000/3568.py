S = input()
T = S.split()[0]
S = "".join(S[:-1].split()[1:]).split(",")

for i in S:
    j = 0
    while j < len(i) and i[j] not in ["&", "*", "[", "]"]:
        j += 1
    print(T, end="")
    for k in range(len(i) - 1, j - 1, -1):
        if i[k] == "&" or i[k] == "*":
            print(i[k], end="")
        elif i[k] == "]":
            print("[]", end="")
    print(" " + i[:j] + ";")
