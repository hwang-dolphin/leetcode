#include <iostream>
using namespace std;

/*
	Intuition: Simple math understanding.  Numbers of available
			   spot for each type of vehicles subtracted by the number 
			   of each type of vehicles that wants a spot.

	RunTime: O(1), number of type of vehicles.

	Space Complexity: O(1)
*/



class ParkingSystem 
{
private:
    int bigSlot, mediumSlot, smallSlot;
    bool result;
    
public:
    ParkingSystem(int big, int medium, int small) 
    {
        bigSlot = big;
        mediumSlot = medium;
        smallSlot = small;
    }
    
    bool addCar(int carType) 
    {
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
    }
};


int main()
{
	ParkingSystem myObj(1,1,0);
	cout << myObj.addCar(1) << endl;
	cout << myObj.addCar(2) << endl;
	cout << myObj.addCar(3) << endl;
	cout << myObj.addCar(1) << endl;

	return 0;
}
