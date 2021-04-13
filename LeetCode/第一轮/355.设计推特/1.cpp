#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

static int timeStamp = 0;

// 每个 Tweet 实例需要记录自己的 tweetId 和发表时间 time
// 而且作为链表节点，要有一个指向下一个节点的 next 指针
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

// 根据面向对象的设计原则，「关注」「取关」和「发文」应该是 User 的行为
// 况且关注列表和推文列表也存储在 User 类中，
// 所以也应该给 User 添加 follow，unfollow 和 post 这几个方法
class User
{
private:
    int id;

public:
    Tweet *head;
    unordered_set<int> followed;

    // User实例首先要关注自己，头结点赋空指针
    User(int userId)
    {
        this->id = userId;
        head = nullptr;
        followed.insert(id);
    }

    // 关注别的用户
    void follow(int userId)
    {
        followed.insert(userId);
    }

    // 取消关注别的用户，注意：不能取消关注自己
    void unfollow(int userId)
    {
        if (userId != this->id)
            followed.erase(userId);
    }

    // 发送一条推文动态，
    void post(int contentId)
    {
        Tweet *twt = new Tweet(contentId, timeStamp);
        timeStamp++;
        // 当前推文指针指向头结点，头结点移动到当前推文上面
        twt->next = head;
        head = twt;
    }
};

class Twitter
{
private:
    // 映射将 userId 和 User 对象对应起来
    unordered_map<int, User *> userMap;

    // 在 c/c++ 中，为了解决一些频繁调用的小函数大量消耗栈空间（栈内存）的问题
    // 特别的引入了 inline 修饰符，表示为内联函数
    inline bool contain(int id)
    {
        return userMap.find(id) != userMap.end();
    }

public:
    // clear()函数用于从userMap容器中删除所有元素，从而使其大小保持为0
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

        // 实现合并 k 个有序链表的算法需要用到优先级队列（Priority Queue），这种数据结构是「二叉堆」最重要的应用
        // 你可以理解为它可以对插入的元素自动排序
        // 乱序的元素插入其中就被放到了正确的位置，可以按照从小到大（或从大到小）有序地取出元素
        priority_queue<Tweet *, vector<Tweet *>, Compare> q(cmp);

        // 获取当前用户userId所关注的人的id放到一个
        unordered_set<int> &users = userMap[userId]->followed;

        // 把所有关注人发的推文头指针放到q优先队列里面
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

    // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
    twitter.postTweet(1, 5);

    // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
    vector<int> twt = twitter.getNewsFeed(1);
    for (int i = 0; i < twt.size(); i++)
        cout << twt[i] << endl;

    // 用户1关注了用户2.
    twitter.follow(1, 2);

    // 用户2发送了一个新推文 (推文id = 6).
    twitter.postTweet(2, 6);

    // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
    // 推文id6应当在推文id5之前，因为它是在5之后发送的.
    vector<int> twt1 = twitter.getNewsFeed(1);
    for (int i = 0; i < twt1.size(); i++)
        cout << twt1[i] << endl;

    // // 用户1取消关注了用户2.
    twitter.unfollow(1, 2);

    // // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
    // // 因为用户1已经不再关注用户2.
    vector<int> twt2 = twitter.getNewsFeed(1);
    for (int i = 0; i < twt2.size(); i++)
        cout << twt2[i] << endl;

    return 0;
}