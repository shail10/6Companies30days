#include<bits/stdc++.h>
using namespace std;

int toyPosition(int n,int m,int k)
{
	if(m<=n-k+1)
		return m+k-1;
	
	m = m-(n-k+1);

	if(m%n==0)
		return n;
	else
		return m%n;
}

int main()
{
	int n = 15;
	int m = 8;
	int k = 13;
	int ans = toyPosition(n,m,k);
	cout<<ans;
}
