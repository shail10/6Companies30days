class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j;
        int count = 0;
        while(i<n){
            j = i;
            if(j+1<n && arr[j] < arr[j+1]){
                while(j+1<n && arr[j]<arr[j+1])
                   j++;
                if(j+1<n && arr[j]>arr[j+1]){
                    while(j+1<n && arr[j]>arr[j+1])
                        j++;
                    count = max(count,j-i+1);
                }
            }
            i = max(j,i+1);
        }
        return count;
    }
};