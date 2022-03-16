class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict1 = {}
        dict2 = {}
        for i in s:
            if i not in dict1:
                dict1[i]=1
            else:
                ++dict1[i];
        for i in t:
            if i not in dict2:
                dict2[i]=1
            else:
                ++dict2[i];
        for i in dict1:
            if i not in dict2:
                return False
            elif dict1[i] != dict2[i]:
                return False
        return True


solu = Solution()
print(solu.isAnagram('aa', 'a'))
