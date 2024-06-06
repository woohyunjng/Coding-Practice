T = int(input())

for i in range(T):
    N = input()
    score, add_score = 0, 1

    for j in N:
        if j == "O":
            score += add_score
            add_score += 1
        else:
            add_score = 1

    print(score)
