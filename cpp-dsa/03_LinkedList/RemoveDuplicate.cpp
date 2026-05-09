/*
Leetcode: 83
Problem : Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
Pattern : LinkedList , TwoPointer
Time Complexity: O(N); where N is the Length of LinkedList.

* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* deleteDuplicates(ListNode* head){
    ListNode* dummy = new ListNode(0,head);
    ListNode* ptr = head;
    while(ptr!=nullptr && ptr->next!=nullptr){
        if(ptr->val == ptr->next->val){
          ptr->next=ptr->next->next;  
        }else{ptr=ptr->next;}
    }
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    ListNode* res = deleteDuplicates(head);
    while(res!=nullptr){
        cout<<res->val<<" ";
        res=res->next;
    }  
}