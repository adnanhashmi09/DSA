#include<bits/stdc++.h>
using namespace std;

int fn(int i, int j, string &a, string &b, vector<vector<int>> &dp){
	if(i<0) return j+1;
	if(j<0) return i+1;
	if(dp[i][j]!=-1) return dp[i][j];

	if(a[i]==b[j]){
		return fn(i-1, j-1, a, b, dp);
	}
	int ins = 1 + fn(i, j-1, a, b, dp);
	int del = 1 + fn(i-1, j, a, b, dp);
	int rep = 1 + fn(i-1, j-1, a, b, dp);

	return dp[i][j] = min(ins, min(rep, del));

}

int editDistance(string a, string b){
	int n=a.length();
	int m=b.length();
	
	vector<vector<int>> dp(n, vector<int>(m, -1));
	return fn(n-1, m-1, a, b, dp);
}

int main(){
	string a, b;
	cin>>a>>b;
	cout<<editDistance(a,b);
	return 0;
}
