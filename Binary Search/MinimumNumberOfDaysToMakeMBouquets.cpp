/*
given an integer array bloomDay, an integer m and an integer k.

make m bouquets by useing k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/

class Solution
{
public:
    bool blommed(int day, int M, int K, vector<int> &bloomDay)
    {
        int flower = 0;
        int bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            // IF flower blommed
            if (bloomDay[i] <= day)
            {
                // increase flower
                flower++;

                // IF we find K flower then one bouquets is ready
                if (flower == K)
                {
                    // now try for next bouquets so we collect another 'k' flowers
                    flower = 0;

                    // increase bouquets
                    bouquets++;

                    // we want to make 'M' bouquets if we make 'M' bouquets so return true;
                    if (bouquets >= M)
                    {
                        return true;
                    }
                }
            }

            // IF flower not blommed
            else
            {
                // so no more adjacent flower so flower count is 0
                // now try to adjecent flower
                flower = 0;
            }
        }
        return bouquets >= M;
    }

    int minDays(vector<int> &bloomDay, int M, int K)
    {
        // answer lies b/w [1,1e9] , bcoz  1 <= bloomDay[i] <= 10e9
        // suppose the bloomDay = [1,1,1,1,1,1] m = 3 k = 1; -> answer is 1 bcoz
        // evey flower blommed at 1st day so in just 1 day we have 6 flower adjacent

        // so at any cost answer is minimum is 1 and maximum as 10e9
        int low = 1, high = 1e9;

        int ans = -1; // answer

        // apply binary search on [1,10e9]
        while (low <= high)
        {
            int day = low + (high - low) / 2;

            // after 'day' can we make 'M' bouquets by using 'K' adjacent flower
            // IF yes then no need to check bigger 'day' reduce to [low,day-1] and binary search on it
            if (blommed(day, M, K, bloomDay) == true)
            {
                ans = day;
                high = day - 1;
            }

            // IF no then we need to check bigger 'day'
            else
            {
                low = day + 1;
            }
        }
        return ans;
    }
};