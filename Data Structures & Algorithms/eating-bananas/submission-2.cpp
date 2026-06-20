class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 1;
        while (true) {
            long long totalTime = 0;
            for (int pile : piles) {
                totalTime += (pile + speed - 1) / speed;
            }

            if (totalTime <= h) {
                return speed;
            }
            speed++;
        }
    }
};