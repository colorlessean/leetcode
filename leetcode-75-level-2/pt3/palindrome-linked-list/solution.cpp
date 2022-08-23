// #define VERBOSE

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
    bool isPalindrome(ListNode* head) {
        // find the length
        int length = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            length++;
            curr = curr->next;
        }
        
        #ifdef VERBOSE
        cout << length << endl;
        #endif
        
        // if odd we don't have to care about the middle element
        int middle = length / 2; // this will be rounded if we are odd
        
        vector<int> done_list;
        curr = head;
        
        for (int i = 0; i < middle; i++) {
            // done_list.insert(done_list.begin(), curr->val);
            done_list.push_back(curr->val);
            curr = curr->next;
        }
        
        #ifdef VERBOSE
        for (int i = 0; i < done_list.size(); i++) {
            cout << done_list[i] << " " << endl;
        }
        cout << endl;
        #endif
        
        // skip the middle element if odd number list
        if (length % 2 == 1) {
            curr = curr->next;
        }
        
        for (int i = done_list.size()-1; i >= 0; i--) {
            if (curr->val != done_list[i]) {
                return false;
            }
            else {
                curr = curr->next;
            }
        }
        
        return true;
    }
};

