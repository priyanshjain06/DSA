/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

// REVIEW -  Here is the code :

// void solve(Node<int> *first, Node<int> *second)
// {
//     Node *curr1 = first;
//     Node *next1 = curr1->next;

//     Node *curr2 = second;
//     Node *next2 = curr2->next;

//     while (next1 != NULL && curr2 != NULL) //REVIEW -
//     {
//         if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
//         {
//             curr1->next = curr2;
//             curr2->next = next1;
//             curr1 = curr2; //REVIEW
//             curr2 = next2;
//         }
//         else
//         {
//             curr1 = curr1->next;
//             next1 = next1->next;
//         }
//         if (next1 == NULL)
//         {
//             curr1->next = curr2;
//            return  first; //REVIEW
//         }
//     }
//     return first; //REVIEW -
// }

// Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
// {
//     if(first == NULL)
//         return second;

//     if(second == NULL)
//         return first;

//     if(first -> data <= second -> data ){
//         solve(first, second);
//     }
//     else
//     {
//         solve(second, first);
//     }

// }