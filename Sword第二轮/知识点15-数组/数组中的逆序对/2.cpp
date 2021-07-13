/*
 * @Description: 数组中的逆序对。归并排序，参考解法
 * @Author: Mr. Lee
 * @Date: 2021-07-07 23:58:20
 * @LastEditTime: 2021-07-10 23:20:59
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int merge_Sort(int l, int r, vector<int> &data, vector<int> &tmp)
{
    if (l >= r)
        return 0;

    int mid = (l + r) / 2;
    long long count = merge_Sort(l, mid, data, tmp) + merge_Sort(mid + 1, r, data, tmp);

    // 合并排序
    int i = l, j = mid + 1; // 左数组和右数组的起点
    for (int k = l; k <= r; k++)
    {
        tmp[k] = data[k];
    }

    for (int k = l; k <= r; k++)
    {
        if (i == mid + 1)
        {
            data[k] = tmp[j++];
        }
        else if (j == r + 1 || (tmp[i] <= tmp[j]))
        {
            data[k] = tmp[i++];
        }
        else
        {
            data[k] = tmp[j++];
            count += (mid - i + 1);
        }
    }

    return count % 1000000007;
}

int InversePairs(vector<int> data)
{
    vector<int> tmp(data.size());
    return merge_Sort(0, data.size() - 1, data, tmp);
}

int main()
{
    vector<int> data = {627126, 415347, 850134, 371085, 279048, 705820, 453064, 944751, 92317, 58592, 167988, 284065, 992573, 78043, 190215, 104546, 607528, 391775, 701214, 849731, 231053, 603058, 975374, 199773, 479544, 143961, 206797, 325662, 90035, 69615, 429916, 717161, 484962, 796403, 604598, 280362, 502223, 57662, 741466, 594540, 632606, 909454, 394957, 625180, 503849, 585172, 729726, 627729, 976947, 947293, 477461, 724352, 66703, 452835, 440478, 62599, 596797, 163627, 388261, 203184, 233243, 334529, 436697, 234557, 647284, 41295, 514920, 665859, 615310, 256386, 776752, 247916, 682192, 171709, 389448, 186041, 273234, 635527, 813771, 766533, 582820, 807584, 490886, 649523, 260419, 447716, 228474, 373568, 611343, 616735, 576752, 844586, 467616, 529801, 595496, 631253, 571097, 110416, 297112, 186407, 883154, 73864, 950675, 81698, 245574, 340124, 267739, 35160, 975651, 597862, 801693, 74823, 921798, 292579, 240698, 182218, 256647, 469172, 72138, 867991, 602259, 165243, 228929, 69875, 695044, 824425, 701128, 782493, 451193, 998241, 485252, 334347, 588457, 435928, 416045, 350383, 292404, 200137, 385543, 268055, 314351, 187237, 859230, 236150, 996168, 99928, 934720, 252816, 569100, 523210, 120807, 171359, 688453, 866088, 757586, 383498, 206866, 458715, 682343, 658059, 973308, 167596, 508759, 78117, 603524, 441156, 428501, 412280, 157645, 814044, 196687, 471997, 1281, 55917, 224499, 997450, 155845, 159219, 250266, 241297, 682429, 887425, 412656, 887235, 269865, 686594, 787085, 476731, 661661, 469428, 134791, 634969, 637024, 643550, 229439, 756900, 601058, 657940, 169180, 758704, 471984, 365867, 230701, 473266, 421784, 455200, 470716, 93981, 130771, 237334, 335278, 329552, 641111, 264286, 733139, 910976, 950881, 520224, 904060, 612542, 989653, 38851, 763864, 143029, 198753, 993303, 899930, 799811, 651243, 585462, 558515, 639579, 951330, 305568, 112845, 889466, 277120, 99913, 499800, 924243, 853599, 835078, 770148, 11062, 615717, 503287, 922039, 82950, 23512, 826099, 695492, 529517, 381302, 975708, 672546, 96407, 485363, 88828, 896218, 652958, 674291, 971086, 292538, 141973, 276654, 921735, 547791, 70127, 21649, 47591, 994370, 391600, 399022, 764518, 402663, 14739, 267806, 841054, 97689, 807670, 183505, 309533, 337187, 564807, 801594, 9733, 661214, 803309, 614914, 73784, 45626};
    int ans = InversePairs(data);
    cout << ans << endl;

    return 0;
}
