
class Solution:
    def firstUniqChar(self, s: str) -> int:
        length = len(s)
        dict = {}
        for i in range(0,length):
            char = s[i]
            if char in dict:
                num = dict[char]
                dict[char]=num+1
            else:
                dict[char]=1
        for i in range(0,length):
            if dict[s[i]]==1:
                return i
        return -1
    

solu = Solution()
solu.firstUniqChar("loveleetcode")