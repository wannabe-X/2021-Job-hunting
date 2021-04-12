def coinChange(coins, amount):
    """
    :type coins: List[int]
    :type amount: int
    :rtype: int
    """
    memo = dict()

    def dp(n):
        if n in memo: return memo[n]
        if n == 0: return 0
        if n < 0 : return -1

        res = float('inf')

        for coin in coins:
            subproblem = dp(n - coin)
            if subproblem == -1: continue
            res = res if res < 1 + subproblem else 1 + subproblem

        memo[amount] = res if res != float('inf') else -1

        return memo[amount]

    return dp(amount)
    


if __name__ == '__main__':
    coins = [2]
    amount = 3
    print(coinChange(coins, amount))