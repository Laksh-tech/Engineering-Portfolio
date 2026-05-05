/*
LEETCODE : 69
Problem : Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
Pattern : Binary Search, Math
Time Complexity: O(logN) 
Space Complexity :O(1)
*/
#include <iostream>
using namespace std;
int Sqrt(int x){
    if(x == 0 || x == 1) return x; 
    int low = 1; int high = x / 2;
    int ans = 0; 
    while(low <= high){
        long long mid = low + (high - low) / 2; 
        long long square = mid * mid;
        
        if(square == x) return mid;
        else if(square < x){
            ans = mid; // Only update ans when square is smaller
            low = mid + 1;
        }
        else {
            high = mid - 1; 
        }
    }
    return ans;
}

int main(){
    cout<<Sqrt(67);
}
