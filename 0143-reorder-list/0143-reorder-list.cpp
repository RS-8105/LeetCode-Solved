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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* middle = middleNode(head);

        ListNode* second = reverseList(middle->next);
        middle->next = nullptr;

        ListNode* first = head;

        while(second) {
            ListNode* front1 = first->next;
            ListNode* front2 = second->next;

            first->next = second;
            second->next = front1;

            first = front1;
            second = front2;
        }
    }
};
