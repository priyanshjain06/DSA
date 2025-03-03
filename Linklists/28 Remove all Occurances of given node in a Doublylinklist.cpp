// class Solution
// {
// public:
//     void deleteAllOccurOfX(struct Node **head_ref, int x)
//     {
//         if (*head_ref == NULL) //FIXME
//             return;

//         Node *curr = *head_ref;  //FIXME 
//         while (curr)
//         {
//             Node *temp = curr;
//             curr = curr->next; //REVIEW - 
//             if (temp->data == x)
//             {
//                 if (temp->prev)
//                     temp->prev->next = temp->next;
//                 if (temp->next)
//                     temp->next->prev = temp->prev;

//                 if (*head_ref == temp) //REVIEW - if value is at head
//                     *head_ref = temp->next;
//                 delete temp;
//             }
//         }
//     }
// };
