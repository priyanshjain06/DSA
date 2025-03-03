
// NOTE No need to check for complete tree
class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        // Iterate over the array, except the last level
        for (int i = 0; i <= (n - 2) / 2; i++)
        {
            // Left child index
            int left = 2 * i + 1;
            // Right child index
            int right = 2 * i + 2;

            // Check if the current node is greater than or equal to its left child
            if (arr[i] < arr[left])
            {
                return false;
            }

            // Check if the current node is greater than or equal to its right child
            if (right < n && arr[i] < arr[right])
            {
                return false;
            }
        }
        return true;
    }
};
