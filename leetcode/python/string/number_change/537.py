class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        n1 = num1.split('+')
        A1 = int(n1[0])
        B1 = int(n1[1][:-1])
        n2 = num2.split('+')
        A2 = int(n2[0])
        B2 = int(n2[1][:-1])
        
        A = A1*A2 - B1*B2
        B = A1*B2 + A2*B1
        
        return str(A)+'+'+str(B)+'i'
    
    
solu = Solution()
print(solu.complexNumberMultiply('1+-1i','0+0i'))