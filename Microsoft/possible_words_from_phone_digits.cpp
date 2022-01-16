// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    void findString(int a[],int i,int N,string &temp,vector<string> &ans,string keypad[]){
        if(i>=N){
            ans.push_back(temp);
            return;
        }
        string midstring = keypad[a[i]];
        for(auto ch:midstring){
            temp.push_back(ch);
            findString(a,i+1,N,temp,ans,keypad);
            temp.pop_back();
        }
    } 

    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        string temp = "";
        vector<string> ans;
        string keypad[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        findString(a,0,N,temp,ans,keypad);
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
    int T;
    
    cin >> T; //testcases
    
    while(T--){ //while testcases exist
       int N;
        
       cin >> N; //input size of array
       
       int a[N]; //declare the array
       
       for(int i =0;i<N;i++){
           cin >> a[i]; //input the elements of array that are keys to be pressed
       }
       
       Solution obj;
       
      vector <string> res = obj.possibleWords(a,N);
      for (string i : res) cout << i << " ";
       cout << endl;
    }
    
    return 0;
}  // } Driver Code Ends