#include<bits/stdc++.h>
using namespace std;

int fn(int i, vector<int>& nums, unordered_map<int, bool> mp, int sum, vector<vector<int>> &dp){
	if(i==0){
		if(mp[nums[i]]==true) return nums[i];
		else return 0;
	}

	if(dp[i][sum]!=-1) return dp[i][sum];

	int pick=0;
	if(mp[nums[i]]==true){
		int pred = 0, succ = 0;
		if(mp[nums[i]-1]==true) pred = 1; 
		if(mp[nums[i]+1]==true) succ = 1; 
		mp[nums[i]-1] = false;
		mp[nums[i]+1] = false;
		pick = nums[i] + fn(i-1, nums, mp, sum+nums[i], dp);
		if(pred==1) mp[nums[i]-1] = true;
		if(succ==1) mp[nums[i]+1] = true;
	}

	int notPick = fn(i-1,nums, mp, sum, dp);
	
	return dp[i][sum] = max(pick, notPick);
}

int deleteAndEarn(vector<int>& nums) {
	int n = nums.size();
	unordered_map<int, bool> mp;
	int sum=0;
	for(int i=0; i<n; i++){ 
		mp[nums[i]]=true;
		sum+=nums[i];
	}
	vector<vector<int>> dp(n, vector<int>(sum+1, -1));	
	return fn(n-1, nums, mp, 0, dp);
}

int main(){
	int len;
	cin>>len;
	vector<int> nums;
	while(len--){
		int temp;
		cin>>temp;
		nums.push_back(temp);
	}

	cout<<deleteAndEarn(nums);

	return 0;
}
