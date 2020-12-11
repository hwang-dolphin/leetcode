class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.bigSpot = big
        self.mediumSpot = medium
        self.smallSpot = small
        
    def addCar(self, carType: int) -> bool:
        if (carType == 1):
            if (self.bigSpot == 0):
                result = False
            else:
                self.bigSpot = self.bigSpot - 1
                result = True
                
        elif (carType == 2):
            if (self.mediumSpot == 0):
                result = False
            else:
                self.mediumSpot = self.mediumSpot - 1
                result = True
                
        elif (carType == 3):
            if (self.smallSpot == 0):
                result = False
            else:
                self.smallSpot = self.smallSpot - 1
                result = True
        
        return result

myObj = ParkingSystem(1,1,0)
print(myObj.addCar(1))
print(myObj.addCar(2))
print(myObj.addCar(3))
print(myObj.addCar(1))


