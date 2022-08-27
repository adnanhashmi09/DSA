#include <bits/stdc++.h>
using namespace std;

int memo(int i, int j, string a, string b){
	if(i<0 || j<0) return 0;

	if(a[i] == b[j]) return 1 + memo(i-1, j-1, a, b);

	return max(memo(i-1, j, a, b), memo(i, j-1, a, b));
}

int lcs(string a, string b){
	int n = a.length();
	int m = b.length();

	return memo(n-1, m-1, a, b);	
}

int tabulation(string a, string b) {
	int n = a.length();
	int m = b.length();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=0; i<=n; i++) dp[i][0] == 0;
	for(int j=0; j<=m; j++) dp[0][j] == 0;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				continue;
			}

			dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
		}
	}

	int i = n, j = m;
	string ans(dp[n][m], ' ');
	int index = dp[n][m] - 1;
	while(i>0 && j>0){
		if(a[i-1] == b[j-1]){
			ans[index--] = a[i-1];
			i--;
			j--;		
		}else if(dp[i][j-1] > dp[i-1][j]) j--;
		else i--;
	}

	cout<<ans<<endl;

	return dp[n][m];
}

int main(){
	string a, b;
	cin>>a>>b;
	cout<< tabulation(a,b);
	return 0;
}

