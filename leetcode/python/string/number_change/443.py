
from typing import List


class Solution:
    def compress(self, chars: List[str]) -> int:
        size = len(chars)
        pre = ''
        lis = []
        for i in range(size):
            if chars[i] == pre:
                lis[-1] +=1
            else:
                lis.append(chars[i])
                lis.append(1)
            pre = chars[i]
            
        result = 0
        for i in range(1,len(lis),2):
            num = lis[i]
            if num ==1:
                result+=1
            elif num>1 and num<10:
                result+=2
            elif num>=10 and num<100:
                result+=3
            elif num>=100 and num<1000:
                result+=4
            else:
                result+=5
        return result
   
    
solu = Solution()
print(solu.compress(["a","a","b","b","c","c","c"]))
    