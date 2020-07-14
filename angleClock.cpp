#include <iostream>
using namespace std;

double angleClock(int hour, int minutes) 
{
        if (hour == 12)
        {
            hour = 0;
        }
        
        const double ONE_MINUTE_IN_MINUTE_DEGREE = 6;
        const double EACH_HOUR_DEGREE = 30;
        const double ADDITIONAL_HOUR_DEGREE = 0.5;
        
        double minutesDegree = minutes * ONE_MINUTE_IN_MINUTE_DEGREE;
        double hourDegree = (EACH_HOUR_DEGREE * hour) + (ADDITIONAL_HOUR_DEGREE * minutes);
        
        double clockAngle = (max(hourDegree, minutesDegree) - min(hourDegree, minutesDegree));
        
        return min(clockAngle, 360 - clockAngle);
}


int main()
{
	int hour = 4;
	int minutes = 50;

	double result = angleClock(hour, minutes);

	cout << result << endl;

	return 0;
}


