from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        half = int(len(s)/2)
        for i in range(0, half):
            # self.swap(s[i], s[-i-1])
            ch = s[i]
            s[i] = s[-i-1]
            s[-i-1] = ch

    # def swap(self, a: chr, b: chr) -> None:
    #     c = a
    #     a = b
    #     b = c

solu = Solution()
s = ["h","e","l","l","o"]
print(s)
solu.reverseString(s)
print(s)
