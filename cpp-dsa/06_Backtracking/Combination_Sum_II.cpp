/*LeetCode : 40 
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
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
        findCombination(i+1,(currTarget-cand[i]),cand,curr,res);
        curr.pop_back();
    }
}
int main(){
    vector<vector<int>> res;
    vector<int> curr;
    vector<int> cand ={10,1,2,7,6,1,5};
    sort(cand.begin(),cand.end());
    findCombination(0,8,cand,curr,res);
    for (const auto& subset : res) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "] ";
    }
    return 0;
}
