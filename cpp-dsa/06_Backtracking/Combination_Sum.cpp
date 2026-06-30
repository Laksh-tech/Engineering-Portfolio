/*LeetCode : 39 
Problems :Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
Pattern : Array,BackTracking
Time Complexity: O(n^(target/min(candidates)))
Space Complexity: O(N)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findCombination(int startIndex,int currTarget,vector<int>& cand,vector<int>& curr,vector<vector<int>>& res){
    if(currTarget==0){
        res.push_back(curr);
        return;
    }
    if(currTarget < 0){
        return;
    }
    if(startIndex == cand.size()){
        return;
    }
    for(int i=startIndex;i < cand.size(); i++){
        if(i>startIndex && cand[i]==cand[i-1]){
            continue;
        }
        curr.push_back(cand[i]);
        findCombination(i,(currTarget-cand[i]),cand,curr,res);
        curr.pop_back();
    }
}
int main(){
    vector<vector<int>> res;
    vector<int> curr;
    vector<int> cand ={2,3,6,7};
    findCombination(0,7,cand,curr,res);
    for (const auto& subset : res) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "] ";
    }
    return 0;
}