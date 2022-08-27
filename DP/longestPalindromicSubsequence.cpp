#include<bits/stdc++.h>
using namespace std;

int memo(int i, int j, string s, vector<vector<int>> &dp){
	if(i>j) return 0;

	if(dp[i][j]!=-1) return dp[i][j];

	if(s[i]==s[j] && i==j) return 1 + memo(i+1, j-1, s, dp);
	if(s[i]==s[j]) return 2 + memo(i+1, j-1, s, dp);

	int left = memo(i+1, j, s, dp);
	int right = memo(i, j-1, s, dp);

	return dp[i][j] = max(left, right);
}

int lps(string s) {
	int n = s.length();
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return memo(0, n-1, s, dp);
}

int lpsTab(string s){
	int n = s.length();
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for(int i=n-1; i>=0; i--){
		dp[i][i] = 1;      
		for(int j=i+1; j<n; j++){
			
			if(s[i]==s[j] && i==j){
				dp[i][j] = 1 + dp[i+1][j-1];
				continue;
			}
			else if(s[i]==s[j]){ 
				dp[i][j] =  2 + dp[i+1][j-1];
				continue;
			}


			int left = dp[i+1][j];
			int right = dp[i][j-1];

			dp[i][j] = max(left, right);
		
		}
	}

	cout<<"_ || ";

	for(int i=0; i<n; i++){

		cout<<s[i]<<" || ";
	}

	cout<<endl;

	for(int i=0; i<n; i++){
		cout<<s[n-i-1]<<" || ";
		for(int j=0; j<n; j++){
			cout<<dp[i][j]<<" || ";
		}
		cout<<endl;
	}

	cout<<endl;

	return dp[0][n-1];
	
}

int main(){
	string a;
	cin>>a;
	cout<<lpsTab(a)<<endl;
	return 0;
}
