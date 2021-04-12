# include<iostream>
# include<vector>

using namespace std;

// �ⷨ2 ������
int coinChange(vector<int>& coins, int amount) {
	
	// dp ����Ķ��壺��Ŀ����Ϊ i ʱ��������Ҫ dp[i] öӲ�Ҵճ���
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
