// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        int count = 1;
        int j = 0;
        int i = 0;
        string ans = "";
        while(i<=S.size()){
            if(S[i] == 'I' || i == S.size()){
                while(count>0){
                    if((count-j)<=0)
                        break;
                    char c = count + '0';
                    ans.push_back(c);
                    count--;
                }
                j = i+1;
                count = j+1;
            }
            else if(S[i] == 'D'){
                count++;
            }
            i++;
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends