class Solution
{
public:
    bool isPossible(int a,int b)
    {
        //code here
        if ((a == 1 && b == 2) || (a == 2 && b == 1) || 
            (a == 3 && b == 2) || (a == 2 && b == 3))
        {
            return true;
        }

        // Preorder (1) and Postorder (3) cannot construct a unique tree
        return false;
    }
};