import time

from linear_search import find_root as find_root_linear_search
from binary_search import find_root as find_root_binary_search
from rand import find_root as find_root_rand
from babylonian import find_root as find_root_babylonian


n = float(input("Find root "))
if n < 0:
    print("n is under 0")
    exit()
if n == 0:
    print("0")
    exit()


def try_fnc(name, fnc, **params):
    start_time = time.time()
    root_n = fnc(n, **params)
    end_time = time.time()

    print(f"\nMethod {name}")
    print(
        f"√{n} value : {root_n} (error percentage {abs(n ** 0.5 - root_n) / n ** 0.5 * 100}%)"
    )
    print(f"Executed in {end_time - start_time}s\n")


try_fnc("Linear Search", find_root_linear_search, decimal=1000)
try_fnc("Binary Search", find_root_binary_search, decimal=1000)
try_fnc("Random", find_root_rand, test_case=10**4)
try_fnc("Babylonian", find_root_babylonian, tries=1000)
