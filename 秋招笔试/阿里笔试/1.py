'''
Description:
Author: Mr. Lee
Date: 2021-09-24 20:41:09
LastEditTime: 2021-09-24 22:01:49
LastEditors: Mr. Lee
'''


def hammingWeight(n):
    str = bin(n).replace('0b', '')
    return len(str) - 1


num = int(input())
print(hammingWeight(num))
