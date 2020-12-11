/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
    var result = [];
        
    var minimumPtr, maximumPtr;
        
    if (nums.length == 0)
    {
        return result;
    }
        
    else if (nums.length == 1)
    {
        result.push(String(nums[0]));
        return result;
    }
    
    minimumPtr = 0;
    maximumPtr = 0;
        
    for (let i = 1; i < nums.length; i++)
    {
        if (nums[i] - nums[i - 1] == 1)
        {
            maximumPtr = i;
                
            if (i == nums.length - 1)
            {
                result.push(String(nums[minimumPtr]) + "->" + String(nums[maximumPtr]));
            }
        }
            
        else
        {
            if (minimumPtr == maximumPtr)
            {
                result.push(String(nums[minimumPtr]));
            }
                
            else if (minimumPtr != maximumPtr)
            {
                result.push(String(nums[minimumPtr]) + "->" + String(nums[maximumPtr]));
            }
                
            minimumPtr = i;
            maximumPtr = i;
                
            if (i == nums.length - 1)
            {
                result.push(String(nums[minimumPtr]));
            }
        }
    }
    
    return result;
};

var nums = [0,1,2,4,5,7];

var answer = summaryRanges(nums);

console.log(answer);
