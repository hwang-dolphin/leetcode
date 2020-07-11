

var queryTime = 4;
var startTime = [1,2,3];
var queryTime = [3,2,7];

var busyStudent = function(startTime, endTime, queryTime) 
{
    var counter = 0;
    
    for (var i = 0; i < startTime.length; i++)
    {
            if (queryTime >= startTime[i] && queryTime <= endTime[i])
            {
                counter++;
            }
    }
    
    return counter;
};




