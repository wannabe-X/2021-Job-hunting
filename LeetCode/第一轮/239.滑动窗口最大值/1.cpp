#include <iostream>
#include <vector>
// ˫�˶���
#include <deque>
using namespace std;

// ˫�˶��е�API
// class deque {
//     // �ڶ�ͷ����Ԫ�� n
//     void push_front(int n);
//     // �ڶ�β����Ԫ�� n
//     void push_back(int n);
//     // �ڶ�ͷɾ��Ԫ��
//     void pop_front();
//     // �ڶ�βɾ��Ԫ��
//     void pop_back();
//     // ���ض�ͷԪ��
//     int front();
//     // ���ض�βԪ��
//     int back();
// };

class MonotonicQueue
{
private:
    deque<int> data;

public:
    // ÿ�����������Ԫ�أ���Ҫ��֤�����ǴӶ�ͷ����β�ǵ����ݼ���
    // Ҳ����˵��ÿ�¼ӽ���һ��Ԫ�أ���Ҫ��������ͷ�ƶ�
    // �ƶ��Ĺ����У��������ǰ���Ԫ��С�ڵ��ڵ�ǰֵ����pop��βԪ�أ�ָ��ǰ��
    void push(int val)
    {
        while (!data.empty() && data.back() < val)
            data.pop_back();
        data.push_back(val);
    }

    // ��push�Ĺ��̿��Կ�������ͷ��Ԫ����Զ�Ǳ�������
    int max()
    {
        return data.front();
    }

    // ������е�Ԫ�ظ���Ϊk�����Ҷ�ͷ��Ԫ��ֵ���ڵ�ǰֵ��ɾ����ͷԪ��
    // ���磬nums={3,2,1} �����Ԫ��Ϊ{3,2,1},��ʱӦ��ɾ��3���Ԫ�أ�������һ����������
    void pop(int val)
    {
        if (!data.empty() && data.front() == val)
            data.pop_front();
    }
};

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    MonotonicQueue window;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
    {
        // k-1��Ԫ��������
        if (i < k - 1)
        {
            window.push(nums[i]);
        }
        else
        {
            // �Ӷ�β���Ԫ��
            window.push(nums[i]);                                                                                                   
            // ��ȡ���ֵ�����뵽res��
            res.push_back(window.max());
            // ɾ����βԪ��
            window.pop(nums[i - k + 1]);
        }
    }
    return res;
}

int main(void)
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}