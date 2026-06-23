/*
LEETCODE : 283
Problem :Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Pattern : Two Pointers, Array
Time Complexity: O(N) 
Space Complexity :O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MoveZeroes(vector<int>& nums){
    int in_pos = 0;
    for(int i = 0;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[i],nums[in_pos]);
            in_pos++;
        }
    }
}

int main(){
    vector<int> nums = {1,0,3,0,0,12};
    MoveZeroes(nums);    //Output: 1 3 12 0 0 0 
    for(int i = 0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}

