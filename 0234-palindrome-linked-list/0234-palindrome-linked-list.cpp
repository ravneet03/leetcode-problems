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
 ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr; 
        ListNode* curr = head;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* o = head;
        while(fast != NULL && fast->next!= NULL){
            slow = slow -> next;
            fast = fast->next -> next;
        }
        ListNode* newHead = reverseList(slow);
        ListNode* first = head;
        ListNode* second = newHead;
        while (second != NULL){
            if (first->val != second->val) {
            reverseList(newHead);  
            return false;
        }
        first = first->next; 
        second = second->next;
        }
        reverseList (newHead);
        return true;


    }
};