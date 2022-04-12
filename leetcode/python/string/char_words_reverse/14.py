from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        length = len(strs)
        prefix = ''
        index=0
        if length<1:
            return prefix

        while index<200:
            if len(strs[0])<=index:
                    return prefix
            chr = strs[0][index]
            for i in range(1, length):
                if len(strs[i])<=index:
                    return prefix
                if strs[i][index] == chr:
                   continue
                else:
                    return prefix
            prefix = prefix+chr
            index = index+1        
        return prefix


def main():
    print('echo')
    solu = Solution()
    print(solu.longestCommonPrefix(["flower", "flow", "flight"]))
    print(solu.longestCommonPrefix(["dog", "racecar", "car"]))
    print(solu.longestCommonPrefix(["ab", "a"]))

if __name__ == '__main__':
    main()
