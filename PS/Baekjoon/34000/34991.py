S = input()
T = "toycartoon"

res = -1
TP, SP = "", ""

for i in range(len(T), 0, -1):
    X = -1
    for j in range(len(T)):
        if S[:i] == T[j : j + i]:
            X = j
            break

    if X != -1:
        TP, SP = T[:X], S[i:]
        Y = T[X + i : len(T)]
        for j in range(min(len(SP), len(Y)), 0, -1):
            if Y[0:j] == SP[len(SP) - j : len(SP)]:
                Y = Y[j : len(Y)]
                break
        if len(TP + S + Y) > 20:
            print("toycartoon")
        else:
            print(TP + S + Y)
        exit(0)

if len(T + "_" + S) > 20:
    print("toycartoon")
else:
    print(T + "_" + S)
