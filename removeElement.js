"use strict";

var removeElement = function(nums, val) 
{
    for (let i = 0; i < nums.length; i++)
    {
        if (nums[i] == val)
        {
            nums.splice(i, 1);
            i--;
        }
    }
        
    return nums.length;
};


var nums = [3,2,2,3];
var val = 3;

var answer = removeElement(nums, val);

for (let i = 0; i < nums.length; i++)
{
	console.log(nums[i]);
}

console.log("Size: " + answer);

