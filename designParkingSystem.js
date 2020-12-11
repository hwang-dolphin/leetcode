/**
 * @param {number} big
 * @param {number} medium
 * @param {number} small
 */
var bigSlot, mediumSlot, smallSlot;
var result;

var ParkingSystem = function(big, medium, small) 
{
    bigSlot = big;
    mediumSlot = medium;
    smallSlot = small;
};

/** 
 * @param {number} carType
 * @return {boolean}
 */
ParkingSystem.prototype.addCar = function(carType) {
      if (carType == 1)
        {
            if (bigSlot == 0)
            {
                result = false;
            }
            
            else
            {
                bigSlot--;
                result = true;
            }
        }
        
        else if (carType == 2)
        {
            if (mediumSlot == 0)
            {
                result = false;
            }
            
            else
            {
                mediumSlot--;
                result = true;
            }
        }
        
        else if (carType == 3)
        {
            if (smallSlot == 0)
            {
                result = false;
            }
            
            else
            {
                smallSlot--;
                result = true;
            }
        }
        
        return result;
};

var myObj = new ParkingSystem(1,1,0);

console.log(myObj.addCar(1));
console.log(myObj.addCar(2));
console.log(myObj.addCar(3));
console.log(myObj.addCar(1));



/** 
 * Your ParkingSystem object will be instantiated and called as such:
 * var obj = new ParkingSystem(big, medium, small)
 * var param_1 = obj.addCar(carType)
 */
