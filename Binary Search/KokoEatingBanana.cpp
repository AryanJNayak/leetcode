/*

Koko loves to eat bananas. There are 'n' piles of bananas, the 'i'th pile has 'piles[i]' bananas.
The guards have gone and will come back in 'h' hours.

Koko can decide her bananas-per-hour eating speed of 'k'. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than 'k' bananas, she eats all of them instead and will not eat any more bananas during this hour 'h'.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer 'k' such that she can eat all the bananas within 'h' hours.


Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

*/

class Solution {
public:

    //check that koko eat bananas in hours at speed of k
    bool possible(vector<int>& piles, int h, int k) {
        //i.e. piles [] = {3,6,7,11}, h = 8, k = 3  
        int cnt = 0;
        int n = piles.size();

        for(int i = 0; i<n; i++) {
            //at every pile eat bananas in 'k' speed
            //  bananas    speed(k)      hour to eat bananas by k
            // piles[0]*1.0 / 3 = 3.0 / 3 = 1
            // piles[1]*1.0 / 3 = 6.0 / 3 = 2
            // piles[2]*1.0 / 3 = 7.0 / 3 = 3
            // piles[3]*1.0 / 3 = 11.0 / 3 = 4
            // cnt  = 11
            cnt+= ceil(piles[i]*1.0/k);

            // as we find at speed of 3 we not eat bananas in 8, 
            // we want to 11 hours to eat bananas or increase speed of eating bananas
            if (cnt>h)return false;
        }
        
        return cnt <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // always try to get our k is 'minimal'
        // k lies b/w  1 to 1e9 as h <= 1e9 and h >= piles.length
        //      i.e. h = 9 piles[] = {9,9,9,9,9}
        //      k = 1 because at 1 speed koko eat all piles
        int low = 1, high = 1e9;
        int k = high;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            //if possible to make koko eat bananas in h hours at k(mid) speed then also possible
            // to make koko eat bananas in h hours at grater then k(mid) speed so we do not need to check for grater speed
            // the speed is as minimal as that so  we try to decrece speed go left side of array
            if(possible( piles, h, mid) == true) { k = mid; high = mid-1; }

            //if not possible to make koko eat bananas in h hours at k(mid) speed then also not possible
            // to make koko eat bananas in h hours at less then k(mid) speed so we do not need to check for lesser speed
            // we make to increase speed
            else{ low = mid+1; }
        }
        return k;
    }
};