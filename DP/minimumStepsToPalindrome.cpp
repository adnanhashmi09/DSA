#include<bits/stdc++.h>
using namespace std;

int lps(string a, string b){
	int n = a.length();
	int m = b.length();
	vector<int> prev(m+1, 0), curr(m+1, 0);

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i-1]==b[j-1]){
				curr[j] = 1 + prev[j-1];
				continue;
			}

			curr[j] = max(prev[j], curr[j-1]); 
		}

		prev = curr;
	}
	return prev[m];
}

int minInsertions(string s) {
	string copy = s;
	reverse(copy.begin(), copy.end());
	int len = s.length();

	int lpsLen = lps(s, copy);

	return len - lpsLen;
}

int main(){
	string s;
	cin>>s;
	cout<<minInsertions(s);
	return 0;
}
