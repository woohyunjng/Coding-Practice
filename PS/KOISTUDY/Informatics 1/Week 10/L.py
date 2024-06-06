to_char = [
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
]


def to_K(N, K):
    if N < K:
        return to_char[N]
    return "".join([to_K(N // K, K), to_char[N % K]])


N, K = map(int, input().split())
print(to_K(N, K))
