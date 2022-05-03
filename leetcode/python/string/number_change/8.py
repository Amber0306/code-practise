class Solution:
    def myAtoi(self, s: str) -> int:
        size = len(s)
        nums = ['0','1','2','3','4','5','6','7','8','9']
        pre = ''
        idm = ['+','-']
        begin = False
        equat = ''
        for i in s:
            if i in nums:
                if not begin:
                    begin = True
                if begin or pre in nums:
                    equat +=i
            elif i in idm:
                if not begin:
                    equat  +=i
                    begin = True
            elif i == ' ':
                if begin:
                    break
            else:
                if begin:
                    break
            pre = i
        
        num = int(equat)
        min = -2147483648
        max = 214748364
        if num>= min and num <=max:
            return num
        elif num<min:
            return min
        elif num>max:
            return max
        else:
            return num
    
    
solu = Solution()
print(solu.myAtoi('   -0042'))
print(solu.myAtoi('4193 with words'))
print(solu.myAtoi('words and 978'))