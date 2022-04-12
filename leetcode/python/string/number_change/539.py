from typing import List
from xmlrpc.client import MAXINT

class Solution:
    def getDistance(self,h1:int,min1:int,h2:int,min2:int)->int:
        # time1-time2
        time1 = h1*60+min1
        time2 = h2*60+min2
        day = 24*60
        # print(str(time1+day-time2)+' '+str(time2+day-time1)+' '+str(time1-time2)+' '+str(time2-time1))
        if time1<=time2:
            return time2-time1
            # return min(time1+day-time2,time2-time1)
        else:
            return time2+day-time1
            # return min(time2+day-time1,time1-time2)
        # return min(time1+day-time2,time2+day-time1,)
    
    def getTime(self,time:str):
        hour = int(time[:2])
        minute = int(time[-2:])
        return hour,minute
    
    def findMinDifference(self, timePoints: List[str]) -> int:
        minTime = MAXINT
        size = len(timePoints)
        distance = 0
        for i in range(0,size):
            for j in range(i+1,size):
                # time1 = self.getTime(timePoints[i])
                h1,m1 = int(timePoints[i][:2]),int(timePoints[i][-2:])
                h2,m2 = int(timePoints[j][:2]),int(timePoints[j][-2:])
                time1 = h1*60+m1
                time2 = h2*60+m2
                day = 24*60
                if time1<=time2:
                    distance = min(time1+day-time2,time2-time1)
                else:
                    distance = min(time2+day-time1,time1-time2)
                if distance < minTime:
                    minTime = distance
        return minTime
            
    
    
solu = Solution()
print(solu.findMinDifference(["00:00","23:59","00:00"]))

# ideas
# 鸽巢原理，如果有超过24*60个参数，那么一定会有两个参数相同。
# 关于循环计数，列表排序后，求最短弧长，最短间隔一定在相邻的两个元素之间或者在首尾元素之间。