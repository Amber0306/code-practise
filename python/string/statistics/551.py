class Solution:
    def checkRecord(self, s: str) -> bool:
        absent=0
        pre = 'P'
        prepre = 'P'
        for i in s: 
            if i =='A':
                absent =absent + 1
                if absent >=2:
                    return False 
            elif i == 'L':
                if pre == 'L' and prepre =='L':
                    # 当前和往前两个都是L，返回false
                    return False
            # 继续遍历
            prepre = pre
            pre = i
        return True
    
solu = Solution()
result = solu.checkRecord('PPALLP')
        