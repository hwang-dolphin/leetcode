from typing import List


class RecentCounter:
    def __init__(self):
        self.myList = []
        
    def ping(self, t: int) -> int:
        self.myList.append(t)
        
        while ((t - self.myList[0]) > 3000):
            self.myList.remove(self.myList[0])
            
        return len(self.myList)

myObj = RecentCounter()
print(myObj.ping(1))
print(myObj.ping(100))
print(myObj.ping(3001))
print(myObj.ping(3002))
