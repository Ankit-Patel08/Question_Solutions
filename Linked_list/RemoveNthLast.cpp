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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(head->next == nullptr){  
        //     delete head;
        //     return nullptr;
        // }
        
        // int count = 0;
        // ListNode* temp = head;
        // while(temp->next != nullptr){
        //     count++;                             // this, with time complexity of 
        //     temp = temp->next;                   //  o(2*length of linked list)
        // }
        // count++;

        // int deletenode = count-n;

        // ListNode* curr = head;
        // ListNode* prev = nullptr;
        // while(deletenode--){
        //     prev = curr;
        //     curr = curr->next;
        // }
        // if(count == n){
        //     head = head->next;
        //     delete curr;
        // }else if((count-n+1) == count ){
        //     prev->next = nullptr;
        //     delete curr;
        // }
        // else{
        //     prev->next = curr->next;
        //     delete curr;
        // }
        // return head;

      ListNode* fast = head;
      ListNode* slow = head;
      for(int i = 0; i<n ;i++) fast =fast->next;

      if(fast == NULL){
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
      }
        
        while( fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;

        return head;
    }
};