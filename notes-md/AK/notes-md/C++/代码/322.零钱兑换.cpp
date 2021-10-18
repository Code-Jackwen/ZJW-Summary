#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution 
{
	public:
		int coinChange(vector<int>& coins, int amount);
		void print();
};

int Solution::coinChange(vector<int>& coins, int amount) {
	vector<long long> dp(amount+1, INT_MAX);
	dp[0] = 0;
	for(int& coin: coins) {
		for(int i = 0; i <= amount; i++) {
			if(coin <= i)
				dp[i] = min(dp[i], dp[i-coin] + 1);
		}
	}
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}

void Solution::print(){
	cout<<"hello"<<endl;
}

int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(5);
	int sum = 11;

//	s.print();
	int ret = s.coinChange(nums,sum);
	cout << ret << endl;
	return 0;
}
