class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.split(" ")
        size = len(words)
        i=-1
        while abs(i)<=size and words[i] =='':
            i = i-1
        return len(words[i]) if abs(i)<=size else len(words[i+1])

solu = Solution()
print(solu.lengthOfLastWord("Hello World"))
print(solu.lengthOfLastWord(" "))