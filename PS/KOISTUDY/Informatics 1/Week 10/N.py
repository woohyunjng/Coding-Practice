combination = [[1]]


def do(K):
    if K == 0:
        return "1"

    def inside_do(X):
        if X == 0:
            combination.append([1])
        elif X == K:
            combination[K].append(1)
        else:
            combination[K].append(combination[K - 1][X - 1] + combination[K - 1][X])
        return str(combination[K][X])

    return " ".join(map(inside_do, range(K + 1)))


N = int(input())
print("\n".join(map(do, range(N))))
