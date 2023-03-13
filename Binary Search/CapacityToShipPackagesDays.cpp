/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/
class Solution
{
public:
    bool possible(vector<int> &weights, int days, int mid, int n)
    {
        int weight = 0;
        int d = 1;
        for (int i = 0; i < n; i++)
        {
            //if weight exceedes
            if (weight + weights[i] > mid)
            {
                //increase day b'coz we can't take more weight try to transport next day so d++;
                weight = weights[i];
                d++;
            }

            //if weight not exceeds
            else
            {
                weight += weights[i];
            }

            if (d > days)
                //indicates we not transport all the packages within 'days' we want more days
                return false;
        }
        return d <= days;
    }


    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int maxi = INT_MIN, sum = 0;

        // find maximum element ans sum of array
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }

        // The answer can be lies b/w the maximum element of array and sum of the array
        //   i.e. weight = [10,10,10,10] d = 4
        //   The answer is 10 b'coz at max the 10 capacity of ship can transport
        //   i.e. weight = [10,10,10,10] d= 1
        //   The answer is 40 bcoz only 1 day is given so capacity of ship is 40
        int low = maxi, high = sum;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // if possible to transport all the packages within 'days' at maximim capacity 'm' so we try to minimize answer
            //  search left side
            if (possible(weights, days, mid, n) == true)
            {
                ans = mid;
                high = mid - 1;
            }

            // else search right side
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};