class Solution:
    def countAndSay(self, n: int) -> str:

        def portray(s: list):
            chars = []
            size = len(s)
            pre = 0
            for i in range(0,size):
                if s[i] == pre:
                    chars[-2] = chars[-2]+1
                else:
                    pre = s[i]
                    chars.append(1)
                    chars.append(pre)
            return chars

        pre = []
        now = [1,]
        while n > 1:
            pre = now
            now = portray(pre)
            n -= 1
        return ''.join([str(x) for x in now])
    
    
solu = Solution()
print(solu.countAndSay(4))