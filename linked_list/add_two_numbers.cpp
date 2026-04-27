/*
Problem: Add Two Numbers
- Link: https://leetcode.com/problems/add-two-numbers/

Approach:
- Each linked list represents a number in reverse order (least significant digit first).
- Traverse both lists simultaneously, summing corresponding digits along with a carry value.
- Use a dummy head node to simplify list construction.
- At each step:
    sum = digit1 + digit2 + carry
    new digit = sum % 10
    carry = sum / 10
- Continue until both lists are exhausted, and handle any remaining carry.

Time Complexity: O(max(n, m))
- We traverse each list once.

Space Complexity: O(max(n, m))
- One new linked list is created to store and return the result.

Key Concepts:
- Linked list traversal
- Carry handling (similar to elementary addition)
- Dummy head pattern for cleaner list construction

Edge Cases Considered:
- Lists of different lengths
- Final carry after both lists are exhausted
- One or both input lists being null

Real-World Relevance:
- Mirrors how low-level systems handle arithmetic on streamed or chunked data
- Similar logic applies in:
     - Big integer arithmetic (when numbers exceed native types)
     - Data processing pipelines handling segmented inputs
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out = new ListNode();
        ListNode* curr = out;
        
        int a, b, sum;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL)
        {
            //check validity and store node values
            if(l1 == NULL)
                a = 0;
            else
                a = l1->val;
            
            if(l2 == NULL)
                b = 0;
            else
                b = l2->val;

            //add the sum
            sum = a + b + carry;

            //validate the sum is a digit between 0-9
            if(sum >= 10)
            {
                carry = sum / 10;
                sum = sum % 10;
            }
            else
                carry = 0;

            //create a new node and store that node in the result list
            curr->next = new ListNode(sum);
            curr = curr->next;

            //iterate to the next node in the lists
            if(l1 != NULL) l1 = l1->next;
            
            if(l2 != NULL) l2 = l2->next;

            //edge case: if both nodes are exhausted, proceed to store the remaining carry value
            if(l1 == NULL && l2 == NULL && carry != 0)
                curr->next = new ListNode(carry);
        }        
        
        return out->next;
    }
};
