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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // get the length of the linked list
        int length = 0;
        
        ListNode* curr = head;
        while (curr != NULL) {
            length++;
            curr = curr->next;
        }
        
        #ifdef VERBOSE
        cout << length << endl;
        #endif
        
        // n is gauranteed to be less than the size of the linked list
        // no check needed to see if this is greater than or equal to 0
        int destination = length - n;
        int index = 0;
        
        // reset our pointer
        curr = head;
        ListNode * prev = NULL;
        while (curr != NULL && index != destination) {
            index++;
            prev = curr;
            curr = curr->next;
        }
        
        // so the first element
        if (prev == NULL) {
            head = head->next;
        }
        else {
            prev->next = curr->next;
        }

        return head;
    }
};

