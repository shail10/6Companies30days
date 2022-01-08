// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:


    bool validR(vector<vector<int>> &mat, int row){
        int freq[10] = {0};
        for(int i=0;i<9;i++){
            freq[mat[row][i]]++;
        }
        for(int i=1;i<=9;i++){
            if(freq[i] > 1){
                return false;
            }
        }
        return true;
    }
    
    bool validC(vector<vector<int>> &mat, int col){
        int freq[10] = {0};
        for(int i=0;i<9;i++){
            freq[mat[i][col]]++;
        }
        for(int i=1;i<=9;i++){
            if(freq[i]>1){
                return false;
            }
        }
        return true;
    }
    
    
    bool validSub(vector<vector<int>> &mat, int x, int y){
        int freq[10] = {0};
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                freq[mat[i][j]]++;
            }
        }
        for(int i=1;i<=9;i++){
            if(freq[i]>1){
                return false;
            }
        }
        return true;
    }

    int isValid(vector<vector<int>> mat){
        int flag = 1;
        for(int i=0;i<9;i++){
            if(!validR(mat,i) || !validC(mat,i)){
                flag = false;
                break;
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                flag = flag & validSub(mat,i,j);
            }
        }
        return flag;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends