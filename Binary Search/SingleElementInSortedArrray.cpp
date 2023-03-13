/*
Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        // implement binary search
        int l = 0, h = n - 1;
        while (l <= h)
        {
            // mid of array
            int m = l + (h - l) / 2;

            // in case first element is single element then return it
            if (m == 0 && nums[m] != nums[m + 1])
                return nums[m];

            // single element between the array
            if ((nums[m] != nums[m - 1]) && (nums[m] != nums[m + 1]))
                return nums[m];

            /*
            /          *observe to become double element
            /              -> first occurence of elemnt is even index(0-base) and last occurence of index is odd
            /                 i.e.  element x x y y z z
            /                         index 0 1 2 3 4 5
            /
            /           IF
            /              double element last occurence is even
            /                          OR
            /              double element first occurence is odd
            /
            /              which means before that index One element is single
            /              i.e.   elemnet  x x x y y
            /                       index  0 1 2 3 4
            /
            /               so we move left side of array
            /
            /           ELSE
            /               we move right side of array
            */

            // find element left side
            else if ((nums[m] == nums[m - 1] && m % 2 == 0) || (nums[m] == nums[m + 1] && m % 2 != 0))
                h = m - 1;

            // find element right side
            else
                l = m + 1;
        }

        return -1;
    }
};