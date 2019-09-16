/*Good Subarrays

You are given an array A of size n. Each element of the array is a positive integer.

A subarray defined by (i, j) is called a good-subarray if the number of distint elements in (A[i], A[i+1], ...., A[j]) is not greater than B.

You are asked to tell the number of good-subarrays of each length 1 to n for the given array.


Input Format

The first argument is the array A
The second argument denotes the value B

Output Format

Return an array of integers where i'th integer denotes the number of good-subarrays of length (i+1)

Constraints

1 <= n, A[i] <= 100000
1 <= B <= n

For Example

Input 1:
    A = [1, 2, 2, 3, 1]
    B = 2

Output 1:
    5 4 2 0 0

Explanation:
    For length 1: [1], [2], [2], [3], [1] => Count = 5
    For length 2: [1, 2], [2, 2], [2, 3], [3, 1] => Count = 4
    For length 3: [1, 2, 2], [2, 2, 3] => Count = 2
    For length 4: => Count = 0
    For length 5: => Count = 0
*/

vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size(), l = 0, r = 0;
    vector<int> ret(n, 0);
    unordered_map<int, int> mp;
    while(r < n) {
        while(l <= r && mp.size() > B) {
            if(--mp[A[l]] == 0)
                mp.erase(A[l]);
            l++;    
        }
        if(mp.size() <= B && r - l - 1 >= 0)
            ret[r - l - 1]++;
        mp[A[r++]]++;
    }
    while(l <= r && mp.size() > B) {
        if(--mp[A[l]] == 0)
            mp.erase(A[l]);
        l++;    
    }
    if(mp.size() <= B && r - l - 1 >= 0)
            ret[r - l - 1]++;
    for(int i = n - 2; i >= 0; i--)
       ret[i] += ret[i + 1];
    return ret;
}

