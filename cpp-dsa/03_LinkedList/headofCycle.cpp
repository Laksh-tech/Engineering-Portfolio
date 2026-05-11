/**
Leetcode: 142
Problem : Linked List Cycle II 
Pattern : LinkedList , Two Pointers
Time Complexity : O(N), where N size of list

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
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* headofCycle(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5,head->next);
    cout<<headofCycle(head)->val;
  
}