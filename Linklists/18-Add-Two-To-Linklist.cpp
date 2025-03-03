// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode *dummyHeadNode = new ListNode(-1); 
//         ListNode *temp = dummyHeadNode; 
//         int carry = 0;

//         while (l1 != NULL || l2 != NULL) {
//             int sum = carry;  // Start sum with carry value
            
//             // Add values from l1 and move to the next node
//             if (l1 != NULL) {
//                 sum += l1->val; 
//                 l1 = l1 -> next; 
//             }
            
//             // Add values from l2 and move to the next node
//             if (l2 != NULL) {
//                 sum += l2 -> val; 
//                 l2 = l2 -> next; 
//             }

//             // Create a new node with the digit and adjust carry
//             temp -> next = new ListNode(sum % 10); 
//             carry = sum / 10; 
//             temp = temp -> next; //REVIEW - to avoid overwrite
//         }
        
//         // If there is a remaining carry, add it as a new node
//         if (carry > 0) {
//             temp -> next = new ListNode(carry); //REVIEW - 
//         }

//         return dummyHeadNode -> next; 
//          // Return the actual head of the result list
//     }
// };