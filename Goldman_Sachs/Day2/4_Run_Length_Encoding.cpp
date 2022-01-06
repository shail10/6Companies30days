
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;





string encode(string src)
{     
    int count = 1;
    string ans = "";
    ans+=src[0];
    for(int i=1;i<src.size();i++){
        if(src[i] == src[i-1])
            count++;
        else{
            ans+=count+'0';
            ans+=src[i];
            count=1;
        }
    }
    ans+=count+'0';
    return ans;
}     
 
