#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

static int timeStamp = 0;

// ÿ�� Tweet ʵ����Ҫ��¼�Լ��� tweetId �ͷ���ʱ�� time
// ������Ϊ����ڵ㣬Ҫ��һ��ָ����һ���ڵ�� next ָ��
class Tweet
{
private:
    int id;
    int time;

public:
    Tweet *next;

    Tweet(int id, int time)
    {
        this->id = id;
        this->time = time;
        next = nullptr;
    }

    int getId() const
    {
        return this->id;
    }

    int getTime() const
    {
        return this->time;
    }
};

// ���������������ԭ�򣬡���ע����ȡ�ء��͡����ġ�Ӧ���� User ����Ϊ
// ���ҹ�ע�б�������б�Ҳ�洢�� User ���У�
// ����ҲӦ�ø� User ��� follow��unfollow �� post �⼸������
class User
{
private:
    int id;

public:
    Tweet *head;
    unordered_set<int> followed;

    // Userʵ������Ҫ��ע�Լ���ͷ��㸳��ָ��
    User(int userId)
    {
        this->id = userId;
        head = nullptr;
        followed.insert(id);
    }

    // ��ע����û�
    void follow(int userId)
    {
        followed.insert(userId);
    }

    // ȡ����ע����û���ע�⣺����ȡ����ע�Լ�
    void unfollow(int userId)
    {
        if (userId != this->id)
            followed.erase(userId);
    }

    // ����һ�����Ķ�̬��
    void post(int contentId)
    {
        Tweet *twt = new Tweet(contentId, timeStamp);
        timeStamp++;
        // ��ǰ����ָ��ָ��ͷ��㣬ͷ����ƶ�����ǰ��������
        twt->next = head;
        head = twt;
    }
};

class Twitter
{
private:
    // ӳ�佫 userId �� User �����Ӧ����
    unordered_map<int, User *> userMap;

    // �� c/c++ �У�Ϊ�˽��һЩƵ�����õ�С������������ջ�ռ䣨ջ�ڴ棩������
    // �ر�������� inline ���η�����ʾΪ��������
    inline bool contain(int id)
    {
        return userMap.find(id) != userMap.end();
    }

public:
    // clear()�������ڴ�userMap������ɾ������Ԫ�أ��Ӷ�ʹ���С����Ϊ0
    Twitter()
    {
        userMap.clear();
    }

    void postTweet(int userId, int tweetId)
    {
        if (!contain(userId))
            userMap[userId] = new User(userId);
        userMap[userId]->post(tweetId);
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> ret;
        if (!contain(userId))
            return ret;

        // typedef function<bool(const Tweet *, const Tweet *)> Compare;
        typedef bool (*Compare)(const Tweet *, const Tweet *);
        Compare cmp = [](const Tweet *a, const Tweet *b) {
            return a->getTime() < b->getTime();
        };

        // ʵ�ֺϲ� k ������������㷨��Ҫ�õ����ȼ����У�Priority Queue�����������ݽṹ�ǡ�����ѡ�����Ҫ��Ӧ��
        // ��������Ϊ�����ԶԲ����Ԫ���Զ�����
        // �����Ԫ�ز������оͱ��ŵ�����ȷ��λ�ã����԰��մ�С���󣨻�Ӵ�С�������ȡ��Ԫ��
        priority_queue<Tweet *, vector<Tweet *>, Compare> q(cmp);

        // ��ȡ��ǰ�û�userId����ע���˵�id�ŵ�һ��
        unordered_set<int> &users = userMap[userId]->followed;

        // �����й�ע�˷�������ͷָ��ŵ�q���ȶ�������
        for (int id : users)
        {
            if (!contain(id))
                continue;
            Tweet *twt = userMap[id]->head;
            if (twt == nullptr)
                continue;
            q.push(twt);
        }

        while (!q.empty())
        {
            Tweet *t = q.top();
            q.pop();
            ret.push_back(t->getId());

            if (ret.size() == 10)
                return ret;
            if (t->next)
                q.push(t->next);
        }
        return ret;
    }

    void follow(int followerId, int followeeId)
    {
        if (!contain(followerId))
            userMap[followerId] = new User(followerId);

        if (!contain(followeeId))
            userMap[followeeId] = new User(followeeId);

        userMap[followerId]->follow(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (contain(followerId))
            userMap[followerId]->unfollow(followeeId);
    }
};

int main()
{
    Twitter twitter;

    // �û�1������һ�������� (�û�id = 1, ����id = 5).
    twitter.postTweet(1, 5);

    // �û�1�Ļ�ȡ����Ӧ������һ���б����а���һ��idΪ5������.
    vector<int> twt = twitter.getNewsFeed(1);
    for (int i = 0; i < twt.size(); i++)
        cout << twt[i] << endl;

    // �û�1��ע���û�2.
    twitter.follow(1, 2);

    // �û�2������һ�������� (����id = 6).
    twitter.postTweet(2, 6);

    // �û�1�Ļ�ȡ����Ӧ������һ���б����а����������ģ�id�ֱ�Ϊ -> [6, 5].
    // ����id6Ӧ��������id5֮ǰ����Ϊ������5֮���͵�.
    vector<int> twt1 = twitter.getNewsFeed(1);
    for (int i = 0; i < twt1.size(); i++)
        cout << twt1[i] << endl;

    // // �û�1ȡ����ע���û�2.
    twitter.unfollow(1, 2);

    // // �û�1�Ļ�ȡ����Ӧ������һ���б����а���һ��idΪ5������.
    // // ��Ϊ�û�1�Ѿ����ٹ�ע�û�2.
    vector<int> twt2 = twitter.getNewsFeed(1);
    for (int i = 0; i < twt2.size(); i++)
        cout << twt2[i] << endl;

    return 0;
}