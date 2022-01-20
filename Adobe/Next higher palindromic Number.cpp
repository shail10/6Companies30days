// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
  
    void reverse(string &N, int i, int j)
    {
    while (i < j) {
        swap(N[i], N[j]);
        i++;
        j--;
    }
    }
  
  
    string nextPalin(string N) { 
        
        
    int n = N.size();
        if (n <= 3) {
        return ("-1");
    }

    // find the index of last digit
    // in the 1st half of 'num'
    int mid = n / 2 - 1;
    int i, j;

    // Start from the (mid-1)th digit and
    // find the first digit that is
    // smaller than the digit next to it.
    for (i = mid - 1; i >= 0; i--)
        if (N[i] < N[i + 1])
            break;

    // If no such digit is found, then all
    // digits are in descending order which 
    // means there cannot be a greater 
    // palindromic number with same set of 
    // digits
    if (i < 0) {
        return ("-1");
    }

    // Find the smallest digit on right
    // side of ith digit which is greater 
    // than num[i] up to index 'mid'
    int smallest = i + 1;
    for (j = i + 2; j <= mid; j++)
        if (N[j] > N[i] && 
            N[j] <= N[smallest])
            smallest = j;

    // swap num[i] with num[smallest]
    swap(N[i], N[smallest]);

    // as the number is a palindrome, the same
    // swap of digits should be performed in
    // the 2nd half of 'num'
    swap(N[n - i - 1], N[n - smallest - 1]);

    // reverse digits in the range (i+1) to mid
    reverse(N, i + 1, mid);

    // if n is even, then reverse digits in the
    // range mid+1 to n-i-2
    if (n % 2 == 0)
        reverse(N, mid + 1, n - i - 2);

    // else if n is odd, then reverse digits
    // in the range mid+2 to n-i-2
    else
        reverse(N, mid + 2, n - i - 2);

    // required next higher palindromic number
    return N;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends