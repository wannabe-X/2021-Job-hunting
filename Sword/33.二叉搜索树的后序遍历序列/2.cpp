#include <iostream>
#include <vector>

using namespace std;
bool vaild(vector<int> &postorder, int l, int r)
{
    if (l >= r)
        return true;         //区域不合法时，不用继续验证
    int root = postorder[r]; //当前子树根节点的值为区间最后一个元素

    int k = l;
    while (k < r && postorder[k] < root)
        ++k; //因为左子树均小于根节点，所以退出循环时定位到右子树

    for (int i = k; i < r; ++i)
        if (postorder[i] < root)
            return false; //验证右子树的值是否大于根节点

    return vaild(postorder, l, k - 1) && vaild(postorder, k, r - 1); //最后分别递归验证左右子树
}

bool verifyPostorder(vector<int> &postorder)
{
    if (postorder.size() < 2)
        return true;
    return vaild(postorder, 0, postorder.size() - 1);
}

int main(void)
{
    vector<int> postorder = {1, 3, 2, 6, 5};
    bool ans = verifyPostorder(postorder);
    cout << boolalpha;
    cout << ans << endl;
    return 0;
}