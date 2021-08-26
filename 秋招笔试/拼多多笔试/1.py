'''
Description: 
Author: Mr. Lee
Date: 2021-07-25 19:26:32
LastEditTime: 2021-07-25 19:50:04
LastEditors: Mr. Lee
'''

import sys


def solution(n, arr):
    arr.sort(key=lambda x: (x[1], x[0]))
    for i in range(n - 1):
        if (arr[i][1] <= arr[i + 1][0]):
            continue
        if (arr[i][0] >= arr[i + 1][0]):
            return 'true'
    return 'false'


if __name__ == '__main__':
    N = int(sys.stdin.readline().strip())
    arr = []
    for i in range(N):
        arr.append(list(map(int, sys.stdin.readline().strip().split())))
    print(solution(N, arr))
