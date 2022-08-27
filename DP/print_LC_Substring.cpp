#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr (string a, string b, int n, int m)
{
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=0; i<=n; i++) dp[i][0] == 0;
	for(int j=0; j<=m; j++) dp[0][j] == 0;

	int ans = 0;
	int row = 0, col = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				if(ans<=dp[i][j]){
					ans = dp[i][j];
					row = i;
					col = j;
				}
				continue;
			}

			dp[i][j] = 0; 
		}
	}

	string str(ans, ' ');
	int idx = ans-1;
	while(dp[row][col]!=0){
		str[idx--] = a[row];
		row--;
		col--;
	}

	cout<<str<<endl;

	return ans;
}

int main(){
	string a,b;
	cin>>a>>b;
	int n = a.length();
	int m = b.length();

	cout<<longestCommonSubstr(a, b, n, m);
	return 0;
}
