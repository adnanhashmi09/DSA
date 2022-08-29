#include<bits/stdc++.h>
using namespace std;

int fn(int i, int j, string a, string b){
	if(j<0) return 1;
	if(i<0) return 0;

	if(a[i]==b[j])
		return fn(i-1, j, a, b) + fn(i-1, j-1, a, b);
	else
		return fn(i-1, j, a, b);
}

int subsequences(string a, string b){
	int n=a.length();
	int m=b.length();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	for(int i=0; i<=n; i++) dp[i][0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			
			if(a[i-1]==b[j-1])
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			else
				dp[i][j] =  dp[i-1][j];
		}
	}
	return dp[n][m];
}
int main(){
	string a, b;
	cin>>a>>b;
	
	cout<<subsequences(a, b)<<endl;
	return 0;
}
