# 91.2 / 100

from colorama import init
from termcolor import colored
from copy import deepcopy
from random import choice

init()

f = open("", "r")
N, M = map(int, f.readline().rstrip().split())
arr = []

for i in range(N):
    arr.append(list(f.readline().rstrip()))

K = int(f.readline().rstrip())
for i in range(K):
    word = list(f.readline().rstrip())
    res = deepcopy(arr)

    for j in range(N):
        for k in range(M - len(word) + 1):
            if arr[j][k : k + len(word)] == word:
                color = choice(
                    [
                        "red",
                        "green",
                        "yellow",
                        "blue",
                        "magenta",
                        "cyan",
                    ]
                )
                for x in range(k, k + len(word)):
                    res[j][x] = colored(arr[j][x], color)

    for j in range(M):
        for k in range(N - len(word) + 1):
            new_arr = []
            for x in range(k, k + len(word)):
                new_arr.append(arr[x][j])
            if new_arr == word:
                color = choice(
                    [
                        "red",
                        "green",
                        "yellow",
                        "blue",
                        "magenta",
                        "cyan",
                    ]
                )
                for x in range(k, k + len(word)):
                    res[x][j] = colored(arr[x][j], color)

    print("".join(word))
    for j in range(N):
        for k in range(M):
            print(res[j][k], end="")
        print()
    print()
