# class Solution:
#     def fractionAddition(self, expression: str) -> str:
#         minus = []
#         ele = []
        
#         if expression[0] != '-':
#             minus.append(True)
#         for i in expression:
#             if i == '-':
#                 minus.append(False)
#             if i == '+':
#                 minus.append(True)
                
        
#         # 这题太难，先通分再约分
from fractions import Fraction

class Solution:
    def fractionAddition(self, expression: str) -> str:
        # f = Fraction(str(eval(expression))).limit_denominator()
        ev = eval(expression)
        fr = Fraction(str(ev))
        f = fr.limit_denominator()
        print(str(f.numerator))
        print(str(f.denominator))
        return f'{f.numerator}/{f.denominator}'          
    

solu = Solution()
print(solu.fractionAddition('-1/2+1/2+1/3'))