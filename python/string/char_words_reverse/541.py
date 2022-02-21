class Solution:
    def reverseStr(self, s:str, k:int)->str:
        length = len(s) 
        num = length // k
        # 2k
        if length % (2*k) ==0:
            loop = length /(2*k)
            for i in range(0,loop):
                pass

        # k 
        # k-2k
        # 0-k


solu = Solution()
solu.reverseStr('abcdefghijk', 2)
