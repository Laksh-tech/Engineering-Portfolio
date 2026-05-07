/**
Leetcode: 141
Problem : Linked List Cycle
Pattern : LinkedList 
Time Complexity : O(N+M), where N size of list1 and M size of list2

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

bool hasCycle(ListNode *head) {
    if(head == nullptr) return false;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr&& fast->next!=nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            return true;
        }
        }
        return false;
}    

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout<<hasCycle(head);
}
    
