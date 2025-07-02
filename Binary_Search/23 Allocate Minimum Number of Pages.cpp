// NOTE Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that :

// Each student gets at least one book.Each book should be allocated to only one student.Book allocation should be in a contiguous manner.You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.If the allocation of books is not possible.return -1

// REVIEW - Time Complexity:  O(N * log(sum(arr[])-max(arr[])+1))

// ANCHOR leetcode 410 Split Array Largest Sum

#include <iostream>
#include <vector>
#include <numeric>   //REVIEW - for accumulate
#include <algorithm> //REVIEW -
using namespace std;

int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size();
    int students = 1;
    long long currentPagePerStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentPagePerStudent + arr[i] <= pages)
        {
            // add pages to current student
            currentPagePerStudent = currentPagePerStudent + arr[i];
        }
        else
        {
            // add pages to next student
            students++;
            currentPagePerStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    // book allocation impossible:
    if (m > n) // m is students number
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0); // NOTE
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students <= m) // REVIEW <=
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low; // REVIEW -
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
