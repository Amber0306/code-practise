class Solution:
    def canConstruct(self,ransomNote:str,magazine:str)->bool:
        dict={}
        for i in magazine:
            if i not in dict:
                dict[i] = 1
            else:
                dict[i] = dict[i] + 1
        for j in ransomNote:
            if j not in dict:
                return False
            else:
                dict[j] = dict[j] - 1
                if dict[j] < 0:
                    return False
        return True
    
solu = Solution()
result = solu.canConstruct('aa','ab')