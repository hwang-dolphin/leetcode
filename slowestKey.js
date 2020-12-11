/**
 * @param {number[]} releaseTimes
 * @param {string} keysPressed
 * @return {character}
 */
var slowestKey = function(releaseTimes, keysPressed) 
{
    let result = keysPressed[0];
    let longest = releaseTimes[0];
        
    for (let i = 1; i < releaseTimes.length; i++)
    {
        if ((releaseTimes[i] - releaseTimes[i - 1]) > longest)
        {
            longest = releaseTimes[i] - releaseTimes[i - 1];
            result = keysPressed[i];
        }
            
        else if ((releaseTimes[i] - releaseTimes[i - 1]) === longest)
        {
            result = (result > keysPressed[i]) ? result : keysPressed[i];
        }
    }
        
    return result;
};


var releaseTimes = [12,23,36,46,62];
var keysPressed = "spuda";

var answer = slowestKey(releaseTimes, keysPressed);

console.log(answer);
