
from typing import List


class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        result = []
        for i in range(1,n+1):
            if i%3 ==0:
                s = 'Fizz'
                if i%5 == 0:
                    s += 'Buzz'
            elif i%5 == 0:
                s = 'Buzz'
            else:
                s = str(i)
            result.append(s)    
        return result
    

solu = Solution()
result = solu.fizzBuzz(16)