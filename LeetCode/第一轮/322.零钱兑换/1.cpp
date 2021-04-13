# include<iostream>
# include<vector>

using namespace std;

// 解法1 递归法
int coinChange(vector<int>& coins, int amount) {
	if(amount==0) return 0;
	if(amount<0) return -1;

	int res = 1000000;

	for(int i=0; i < coins.size(); i++){
		int subproblem = coinChange(coins, amount - coins[i]);
		if( subproblem == -1) continue;
		res = res < (1+subproblem) ? res : (1+subproblem);
	}
		
	return res != 1000000? res: -1;
}
	
	


int main(void){
	int n[] = {1, 2, 5}, amount = 11;
	vector<int> coins(n, n+3) ;
    cout << coinChange(coins, amount);
    
    return 0;
}
