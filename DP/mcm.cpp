#include<bits/stdc++.h>

using namespace std;

int fn(int i, int j, vector<int> dim, vector<vector<int>>& dp){

	if(i==j){
		return 0;
	}

	if(dp[i][j]!=-1) return dp[i][j]; 

	int ans = 1e9;

	for(int k=i; k<j; k++){
		int steps = dim[i-1]*dim[k]*dim[j] + fn(i, k, dim, dp) + fn(k+1, j, dim, dp);
		ans = min(ans, steps);
	}

	return dp[i][j] = ans;
}

int opr(vector<int> dim, int s){
	vector<vector<int>> dp(s, vector<int>(s, 0));

	for(int i=s-1; i>=1; i--){
		for(int j=i+1;  j<s; j++){

			int ans = 1e9;

			for(int k=i; k<j; k++){
				int steps = dim[i-1]*dim[k]*dim[j] + dp[i][k] + dp[k+1][j];
				ans = min(ans, steps);
			}

			dp[i][j] = ans;
		}
	}
	return dp[1][s-1];
	return fn(1, s-1, dim, dp);
}

int main(){
	int s;
	cin>>s;
	vector<int> dim;

	int p = s;
	while(p--){
		int temp;
		cin>>temp;
		dim.push_back(temp);
	}

	cout<<opr(dim, s);
}
