class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // loop over for each element
        int speed = 1;
        while(true) {
            long long totalTime = 0;
            for(int pile: piles) {
                totalTime += ceil((static_cast<double>(pile))/speed);
            }
            if(totalTime<=h) {
                return speed;
            }
            speed++;
        }
    }
};
