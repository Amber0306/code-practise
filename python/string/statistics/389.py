class Solution:
    def findTheDifference(self,s:str,t:str)->str:
        table={}
        for i in s:
            if i not in table:
                table[i] = 1
            else:
                table[i] = table[i] +1
        
        for j in t:
            if j not in table:
                return j
            else:
                table[j] = table[j]-1
                if table[j] <0:
                    return j
    
solu = Solution()
solu.findTheDifference('abcd','abced')