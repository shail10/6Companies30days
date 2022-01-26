/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int t, MountainArray &arr) {
        //firs finding the peak element
        int peak = 0;
        int end = arr.length()-1;
        int temp;
        while(peak!=end){
            int mid = peak + (end-peak)/2;
            temp = arr.get(mid);
            if(temp<arr.get(mid+1)){
                peak = mid+1;
            }
            else if(temp>arr.get(mid+1)){
                end = mid;
            }
        }
        int ans = -1;
        int start = 0;
        end = peak;
        while(start<=end){
            int mid = start + (end-start)/2;
            temp = arr.get(mid);
            if(temp == t){
                ans = mid;
                break;
            }
            if(temp>t){
                end = mid-1;
            }
            else if(temp<t){
                start = mid+1;
            }
        }
        
        if(ans==-1){
            start = peak;
            end = arr.length()-1;
            while(start<=end){
                int mid = start + (end-start)/2;
                temp = arr.get(mid);
                if(temp == t){
                    ans = mid;
                    break;
                }
                if(temp>t){
                    start = mid+1;
                }
                else if(temp<t){
                    end = mid-1;
                }
            }
        }
        return ans;
    }
};