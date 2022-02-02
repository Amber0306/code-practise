class Solution:
    def reverseWords(self, s: str) -> str:
        words  = s.split(' ')
        result = ''
        for word in words:
            word = ''.join(reversed(word))
            result = result+word+' '
        return result[:-1]

solu = Solution()
print(solu.reverseWords("Let's take LeetCode contest"))