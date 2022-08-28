#include<bits/stdc++.h>

using namespace std;

int memo(int i, int j, string a, string b){
	if(i<0 || j<0) return 0;

	if(a[i]==b[j]) return 1 + memo(i-1, j-1, a, b);

	return max(memo(i-1, j, a, b), memo(i, j-1, a, b));
}

int scs(string a, string b){
	int n = a.length();
	int m = b.length();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i-1]==b[j-1]){ 
				dp[i][j] =  1 + dp[i-1][j-1];
				continue;
			}

			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int i=n, j=m;
	string ans = "";
	while(i>0 && j>0){
		if(a[i-1] == b[j-1]){
			ans+=a[i-1];
			i--, j--;
		}else if(dp[i-1][j] > dp[i][j-1]){
			ans+=a[i-1];
			i--;
		}else{
			ans+=b[j-1];
			j--;
		}
	}

	while(i>0){
		ans+=a[i-1];
		i--;
	}

	while(j>0){
		ans+=b[j-1];
		j--;
	}

	reverse(ans.begin(), ans.end());
	cout<<ans<<endl;

	return m+n-dp[n][m];
}

int main(){
	string a, b;
	cin>>a>>b;

	cout<<scs(a, b);
	return 0;
}

