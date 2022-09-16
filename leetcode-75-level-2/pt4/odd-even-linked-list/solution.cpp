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
class Solution {
public:    
    ListNode* sortList(ListNode* head) {
        vector<int> vals;
        
        ListNode* curr = head;
        
        while (curr != NULL) {
            vals.push_back(curr->val);
            curr = curr->next;
        }
        
        // use the built in quick sort algorithm don't waste time with bubble sort
        sort(vals.begin(), vals.end());
        
        curr = head;
        int index = 0;
        
        while (curr != NULL) {
            curr->val = vals[index++];
            curr = curr->next;
        }
        
        return head;
    }
};

