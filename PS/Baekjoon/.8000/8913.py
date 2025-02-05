def get(S):
    if S == "":
        return 1

    X, Y, L = 0, 0, len(S)
    while X < L:
        while Y < L and S[Y] == S[X]:
            Y += 1
        if Y - X >= 2 and get(S[:X] + S[Y:]) == 1:
            return 1
        X = Y

    return 0


T = int(input())

for i in range(T):
    S = input()
    print(get(S))
