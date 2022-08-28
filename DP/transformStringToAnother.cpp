#include<bits/stdc++.h>
using namespace std;

int lcs(string a, string b){
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

int minOperations(string a, string b) 
{ 
	// Your code goes here
	// a ---> b
	int alen = a.length();
	int blen = b.length();

	int lcsLen = lcs(a, b);
	int opr = 0;
	if(lcsLen < alen) opr = alen - lcsLen;
	opr += blen - lcsLen;
	return opr;
}

int main(){
	string a, b;
	cin>>a>>b;

	cout<<minOperations(a, b);
	return 0;
}
