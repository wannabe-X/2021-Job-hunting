// ��С��
// #include <iostream>

// #include <bits/stdc++.h>

// using namespace std;

// class minheap
// {
// public:
//     int *arr;      //pointer to array of element in heap;
//     int capacity;  //the capacity of array;
//     int heap_size; //current number of element in heap
// public:
//     minheap(int cap);
//     int parent(int i) { return (i - 1) / 2; }
//     int left(int i) { return 2 * i + 1; }
//     int right(int i) { return 2 * i + 2; }

//     void insertvalue(int k);

//     int getmin() { return arr[0]; }

//     void decreasekey(int i, int new_key);

//     void minheapify(int i);

//     int extractmin();

//     void deletekey(int i);
// };

// //initialization

// minheap::minheap(int cap)

// {

//     capacity = cap;

//     heap_size = 0;

//     arr = new int[cap];
// }

// void minheap ::insertvalue(int k)

// {

//     if (heap_size == capacity)

//     {
//         cout << "can't insert value" << endl;
//         return;
//     }

//     heap_size++;
//     int i = heap_size - 1;
//     arr[i] = k;

//     while (i != 0 && arr[parent(i)] > arr[i])
//     {
//         swap(arr[i], arr[parent(i)]);
//         i = parent(i);
//     }
// }

// void minheap::decreasekey(int i, int new_key)
// {
//     arr[i] = new_key;
//     while (i != 0 && arr[parent(i)] > arr[i])
//     {
//         swap(arr[parent(i)], arr[i]);
//         i = parent(i);
//     }
// }

// void minheap::minheapify(int i)
// {
//     int l = left(i);
//     int r = right(i);
//     int smallest = i;

//     if (l < heap_size && arr[l] < arr[i])
//         smallest = l;
//     if (r < heap_size && arr[r] < arr[smallest])
//         smallest = r;
//     while (smallest != i)
//     {
//         swap(arr[i], arr[smallest]);
//         i = smallest;
//         minheapify(i);
//     }
// }

// int minheap::extractmin()
// {
//     if (heap_size <= 0)
//     {
//         return -1;
//     }
//     if (heap_size == 1)
//     {
//         heap_size--;
//         return arr[0];
//     }

//     int root = arr[0];
//     arr[0] = arr[heap_size - 1];
//     heap_size--;
//     minheapify(0);

//     return root;
// }

// void minheap::deletekey(int i)
// {
//     decreasekey(i, -1);
//     extractmin();
// }

// int main()
// {
//     minheap h(10);
//     for(int i=1;i<11;i++)
//     h.insertvalue(i);
//     // h.insertvalue(1);
//     // h.insertvalue(3);
//     // h.insertvalue(4);
//     // h.insertvalue(5);

//     // h.extractmin();

//     // h.extractmin();

//     for (int i = 0; i < h.heap_size; i++)
//     {
//         cout << h.arr[i] << endl;
//     }

//     return 0;
// }

// ����
#include <iostream>
using namespace std;

int N = 0;

int pq[100];

// ���ڵ������
int parent(int root)
{
    return root / 2;
}
// ���ӵ�����
int left(int root)
{
    return root * 2;
}
// �Һ��ӵ�����
int right(int root)
{
    return root * 2 + 1;
}

// �Ƚϴ�С
int less_(int i, int j)
{
    return (pq[i] - pq[j] < 0) ? 1 : 0;
}

// ����Ԫ��
void exch(int i, int j)
{
    int temp = pq[i];
    pq[i] = pq[j];
    pq[j] = temp;
}

//�ϸ�
void swim(int k)
{
    // ��������Ѷ����Ͳ������ϸ���
    while (k > 1 && less_(parent(k), k))
    // ����� k ��Ԫ�ر��ϲ��
    // �� k ����ȥ
    {
        exch(parent(k), k);
        k = parent(k);
    }
}

// �³�
void sink(int k)
{
    // ��������ѵף��ͳ�����ȥ��
    while (left(k) <= N)
    {
        // order������ �Һ������ֵ������
        int order = left(k);
        if (right(k) <= N && less_(left(k), right(k)))
            order = right(k);

        exch(order, k);
        k = order;
    }
}

// ����Ԫ��
void insert(int e)
{
    ++N;
    pq[N] = e;
    // ���±�ΪN��Ҳ���Ǹղ����Ԫ�أ�����ȥ��ˢ�¶����
    swim(N);
}

// ɾ�����ֵ
int delMax()
{
    int max = pq[1];

    // �����Ԫ������СԪ�ؽ�����Ȼ����Сֵ���գ����ȼ�һ���൱��ɾ�������һ��Ԫ��
    exch(1, N);
    pq[N] = 0;
    N--;
    // �õ�һ��Ԫ���³������¶����
    sink(1);
    return max;
}

int main()
{
    int i;
    for (i = 1; i < 11; i++)
        insert(i);

    for (int j = 1; j < i; j++)
        cout << pq[j] << endl;

    delMax();
    cout << endl;

    for (int j = 1; j < i - 1; j++)
        cout << pq[j] << endl;
}
