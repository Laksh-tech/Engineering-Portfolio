/*
Leetcode: 21
Problem : Merge Two Sorted Lists
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
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode*  dummy = new ListNode(0);
    ListNode* tail = dummy;
    while(list1!=nullptr && list2!= nullptr){
        if(list1->val<=list2->val){
            tail->next = list1;
            list1=list1->next;
        }else{tail->next = list2;
            list2=list2->next;}
        tail=tail->next;
    }
    if(list1!=nullptr){
        tail->next = list1;
    }
    if(list2!=nullptr){
        tail->next = list2;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
}
int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    ListNode* res = mergeTwoLists(list1,list2);
    while(res!=nullptr){
        cout<<res->val<<" ";
        res=res->next;
    }   
}
