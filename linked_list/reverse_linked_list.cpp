/*
Problem: Reverse Linked List
- Link: https://leetcode.com/problems/reverse-linked-list/

Approach:
- Use an iterative approach with three pointers: prev, curr, and next
- Traverse the list while reversing the direction of each node’s next pointer
- At each step:
     1. Store next node
     2. Reverse current node’s pointer
     3. Move prev and curr forward
- Return prev as the new head after traversal

Time Complexity: O(n)
- Each node is visited exactly once

Space Complexity: O(1)
- In-place reversal using constant extra space

Key Concepts:
- Pointer manipulation in singly linked lists
- In-place data structure transformation
- Iterative traversal with state tracking (prev/curr/next pattern)

Edge Cases Considered:
- Empty list (head == NULL)
- Single node list (no reversal needed)
- Two-node list (minimal pointer swap case)

Real-World Relevance:
- Common operation in low-level systems and memory-constrained environments
- Relevant in:
     - Reversing data streams or buffers
     - Undo/redo systems using linked structures
     - Network packet or pipeline transformations where direction/order must change
*/

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};