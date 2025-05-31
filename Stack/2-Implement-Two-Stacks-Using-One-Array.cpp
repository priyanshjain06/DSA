class TwoStack
{
    int *arr;
    int top1; // maintains left  side of the array (stack1)
    int top2; // maintains right side of the array (stack2)
    int size;

public:
    TwoStack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;         // REVIEW -
        arr = new int[s]; // REVIEW -
    }

    // Push in stack 1.
    void push1(int num)
    {
        // atleast a empty space present
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (top1 >= 0)
        {
            return arr[top1--];
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (top2 < size) // REVIEW -
        {
            return arr[top2++];
        }
        else
        {
            return -1;
        }
    }
};