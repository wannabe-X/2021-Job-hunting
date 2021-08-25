/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-08-24 16:27:15
 * @LastEditTime: 2021-08-24 20:03:16
 * @LastEditors: Mr. Lee
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

int nResources = 3, nProcesses = 0; //定义输入的资源种类和进程数量
int resources[3];                   //资源数
int allocated[20][3];               //为每个进程分配的实例数量
int maxRequired[20][3];             //每个进程的最大需求
int need[20][3];                    //每个进程还需要的资源
int Flag[20];

pthread_mutex_t mutex; //进程互斥锁

bool banker();                                 //系统如果处于安全状态返回true，不安全返回false
void *processCode(void *);                     //多线程实现
void init();                                   //初始化资源请求等数据
void show();                                   //输出各个资源
int requestr(int customer_num, int request[]); //请求资源
int releaser(int customer_num, int release[]); //释放资源
void runner();

int main(int argc, char *argv[])
{
    init();
    show();
    runner();
    return 0;
}

//初始化信息
void init()
{
    printf("请输入进程的数量：\n");
    scanf("%d", &nProcesses);

    printf("请依次输出每种资源可用数量：\n");
    for (int i = 0; i < nResources; i++)
    {
        scanf("%d", &resources[i]);
    }
    printf("\n");

    // 每个进程已经得到的资源数量
    printf("请输入每个进程已经得到的资源数目：\n");
    for (int i = 0; i < nProcesses; i++)
    {
        printf("进程%d:", i);
        for (int j = 0; j < nResources; j++)
        {
            scanf("%d", &allocated[i][j]); //通过输入得到进程得到的资源数目
        }
    }
    printf("\n");

    // 每个进程需要的最大资源数量
    printf("请输入每个进程最大需求的资源数目\n");
    for (int i = 0; i < nProcesses; i++)
    {
        printf("进程%d:", i);
        for (int j = 0; j < nResources; j++)
        {
            scanf("%d", &maxRequired[i][j]); //每个进程最大需求资源量
        }
    }
    printf("\n");
    //计算每个进程仍然需要的各个资源数目
    for (int i = 0; i < nProcesses; i++)
        for (int j = 0; j < nResources; j++)
            need[i][j] = maxRequired[i][j] - allocated[i][j];
}

//输出各个进程获取资源内容
void show()
{
    printf("进程执行前资源清单\n");
    printf("*************************************************************************\n");
    printf("进程ID    allocated        request\n    ");
    for (int x = 0; x < nProcesses; x++)
    {
        printf("%d\t", x); //进程ID
        for (int i = 0; i < nResources; i++)
            printf("%3d", allocated[x][i]);
        printf("\t"); //已分配资源数量
        for (int i = 0; i < nResources; i++)
        {
            if (need[x][i] < 0)
                need[x][i] = 0; //防止所需资源量出现负数
            printf("%3d", need[x][i]);
        }
        printf("\n    ");
    }
    printf("     avaliable: %d %d %d", resources[0], resources[1], resources[2]);
}

void runner()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t ptd_t[nProcesses]; //创建长度为用户数量的线程
    int i = 0;
    int seq[5] = {0};
    printf("\n");
    printf("序列为：");
    for (i = 0; i < nProcesses; i++)
    {
        seq[i] = pthread_create(&ptd_t[i], NULL, processCode, (void *)&i);
        sleep(1);
    }
    //如果输出序列的数目少于进程数目，则证明出现不安全
    printf("\n");
    pthread_mutex_destroy(&mutex); //销毁锁
}

//进程请求资源
int requestr(int customer_num, int request[]) //两个参数分别是请求者和请求资源量
{
    int i = 0;
    //资源是否满足请求
    for (i; i < nResources; i++)
    {
        if (request[i] > resources[i])
        {
            return -1;
        }
    }
    //资源满足请求
    for (i = 0; i < nResources; i++)
    {
        allocated[customer_num][i] = allocated[customer_num][i] + request[i];
        resources[i] = resources[i] - request[i];
    }
    return 0; //回复申请成功
}
//释放进程资源
int releaser(int customer_num, int release[]) //两个参数分别是用户，释放量
{
    int i;
    //资源是否满足请求
    for (i = 0; i < nResources; i++)
    {
        if (allocated[customer_num][i] < release[i])
        {
            return -1;
        }
    }
    //释放资源
    for (i = 0; i < nResources; i++)
    {
        allocated[customer_num][i] = allocated[customer_num][i] - release[i];
        resources[i] = resources[i] + release[i];
    }
    return 0;
}
// 进程代码
void *processCode(void *arg)
{
    int i;
    int *argc = (int *)arg;
    int requset[3] = {0, 0, 0}; //线程的need
    int release[3] = {0, 0, 0}; //线程的max
    int num = *argc;
    int finish = 1;
    for (i = 0; i < nResources; i++)
    {
        requset[i] = need[num][i];
        release[i] = maxRequired[num][i];
    }
    while (-1)
    {
        pthread_mutex_lock(&mutex); //上锁，保证每次申请资源的进程只有一个
        int a = requestr(num, requset);
        if (a == 0)
        {
            releaser(num, release);
            Flag[num] = 1;
            finish = 0;
            printf("%d ", num);
            pthread_mutex_unlock(&mutex); //解锁，将资源让给其他进程
            break;
        }
        else
        {
            pthread_mutex_unlock(&mutex); //解锁，将资源让给其他进程
            if (banker() == -1)
            {
                break;
            }
        }
    }
    if (finish == 0)
    {
        return (void *)0; //安全
    }
    else
    {
        return (void *)-1; //不安全
    }
}

//判断是否为安全序列
bool banker()
{
    int i, a, b = 0, c = 0;
    for (i = 0; i < nProcesses; i++)
    {
        if (Flag[i] == 0)
        {
            c++;
            for (a = 0; a < nProcesses; a++)
            {
                if (resources[a] < need[i][a])
                {
                    b++;
                }
            }
        }
    }
    if (c == b)
    {
        return false;
    }
    return true;
}

