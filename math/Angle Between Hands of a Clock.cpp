class Solution {
public:
    double angleClock(int hour, int minutes) {

        if(hour == 12) hour = 0;
        
        double minute_angle = (double) 360/60 * minutes;
        double hour_angle = (double) 360/12 * hour + (double) 360/720 * minutes;

        double diff = abs(minute_angle - hour_angle);

        return min(360 - diff,diff);
    }
};

