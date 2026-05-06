/*
Leetcode: 19
Problem : Remove Nth Node From End of List
Pattern : LinkedList 
Time Complexity : O(N) ;N refers to no of nodes traversed 
Technique : Using fast anbd slow pointers;
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
   ListNode* dummy = new ListNode(0,head);
   ListNode* fast = dummy;
   ListNode* slow = dummy;
   for(int i =0; i < n;i++){
      fast=fast->next;
   }
   while(fast->next!=nullptr){
    fast=fast->next;
    slow=slow->next;
   }
   ListNode* temp = slow->next;
   slow->next = slow->next->next;
   temp->next=nullptr;
   delete temp;
   return dummy->next;
    
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = removeNthFromEnd(head,2);  
}