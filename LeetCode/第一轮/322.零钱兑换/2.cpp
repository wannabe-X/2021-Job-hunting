# include<iostream>
# include<vector>

using namespace std;

// 解法2 迭代法
int coinChange(vector<int>& coins, int amount) {
	
	// dp 数组的定义：当目标金额为 i 时，至少需要 dp[i] 枚硬币凑出。
	vector<int> dp(amount+1, amount+1);
	dp[0] = 0;

	for(int i=0; i < dp.size(); i++){
		for(int j=0; j < coins.size(); j++){
			if(i - coins[j] < 0) continue;
			dp[i] = dp[i] > 1 + dp[i - coins[j]] ? 1 + dp[i - coins[j]] : dp[i];
		}
	}

	return (dp[amount] == amount + 1) ? -1 : dp[amount];;
}




int main(void){
	int n[] = {1, 2, 5}, amount = 11;
	vector<int> coins(n, n+3) ;
    cout << coinChange(coins, amount);

    return 0;
}
