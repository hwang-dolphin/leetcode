from typing import List

class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        myDict = {}
        answer = []
        acc = 0
        indexCounter = 0
        
        for i in range(0, len(items)):
            if (items[i][0] not in myDict.keys()):
                myDict[items[i][0]] = [items[i][1]]
            
            elif (items[i][0] in myDict.keys()):
                myDict[items[i][0]].append(items[i][1])
        
        for key, value in myDict.items():
            myDict[key].sort(reverse=True)
            
            for i in range(0, 5):
                acc = acc + myDict[key][i]
                indexCounter += 1
            
            average = acc // (indexCounter)
            
            answer.append([key, average])
            
            acc = 0
            indexCounter = 0
                
        return answer 


items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]

myObj = Solution()
answer = myObj.highFive(items)

for i in range(0, len(answer)):
	print(str(answer[i][0]) + ", " + str(answer[i][1]))


