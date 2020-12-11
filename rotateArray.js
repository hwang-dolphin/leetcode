"use strict";

var rotate = function(nums, k) 
{
    var numsTemp = [];
    
    for (let i = 0; i < nums.length; i++)
    {
        numsTemp.push(nums[i]);
    }
        
    for (let i = 0; i < nums.length; i++)
    {
        nums[parseInt((i + k) % nums.length)] = numsTemp[i];
    }
};

var nums = [1,2,3,4,5,6,7];
var k = 3

rotate(nums, k);

for (let i = 0; i < nums.length; i++)
{
	console.log(nums[i]);
}


