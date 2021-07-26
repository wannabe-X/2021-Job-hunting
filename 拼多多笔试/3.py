'''
Description: 
Author: Mr. Lee
Date: 2021-07-25 19:49:22
LastEditTime: 2021-07-26 17:06:12
LastEditors: Mr. Lee
'''


def func(A, B, C, Q):
    if B == 0 or C == 0:
        return 0
    elif (Q == A) or ((Q - A) % B == 0) or (((Q - A) // B) % C == 0):
        return 1

    return 0


if __name__ == '__main__':
    import sys

    n = int(sys.stdin.readline().strip())
    for _ in range(n):
        a, b, c, q = list(map(int, sys.stdin.readline().strip().split()))
        print(func(a, b, c, q))
