/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-22 21:03:05
 * @LastEditTime: 2021-08-23 10:42:08
 * @LastEditors: Mr. Lee
 */
#include <stdio.h>

void main()
{
    volatile int i = 10;

    int a = i;

    printf("i = %d\n", a);

    // 下面汇编语句的作用就是改变内存中 i 的值
    // 但是又不让编译器知道
    __asm
    {
		MOV DWORD PTR[EBP - 4], 20H
    }

    int b = i;
    printf("i = %d\n", b);
}