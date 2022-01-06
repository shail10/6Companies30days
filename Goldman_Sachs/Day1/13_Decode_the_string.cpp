#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string decodedString(string s){
        stack<int> numbers;
        stack<string> str;
        int index = 0;
        string curr_str = "";
        
        while(index<s.length()){
            if(isdigit(s[index]))
            {
                int c = 0;
                while(isdigit(s[index]))
                {
                    c = 10*c+(s[index]-'0');
                    index++;
                }
                numbers.push(c);
            }
            else if(s[index] == ']')
            {
                int count = numbers.top();
                numbers.pop();
                string prev_string = str.top();
                str.pop();
                for(int i = 0;i<count;i++){
                    prev_string = prev_string + curr_str;
                }
                index++;
                curr_str = prev_string;
            }
            else if(s[index] == '[')
            {
                str.push(curr_str);
                curr_str = "";
                index++;
            }
            else 
            {
                curr_str = curr_str + s[index];
                index++;
            }
        }
        return curr_str;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends