int func(int n)
// {
//     vector<int> nums;
//     for (int i = 1; i <= n; i++)
//         nums.push_back(i);
//     int tmp = 2;
//     while (nums.size() > 1)
//     {
//         tmp %= nums.size();
//         auto it = nums.begin() + tmp;
//         nums.erase(it);
//         tmp += 2;
//     }

//     return nums[0];
// }