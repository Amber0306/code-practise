class Solution:
    def judgeCircle(self, moves: str) -> bool:
        left = 0
        right = 0
        up = 0
        down = 0
        for i in moves:
            if i == 'L':
                left+=1
            elif i =='R':
                right +=1
            elif i == 'U':
                up+=1
            elif i =='D':
                down +=1
            else:
                return False
        if left == right and up ==down:
            return True
        return False
    

solu = Solution()
result = solu.judgeCircle("LD")