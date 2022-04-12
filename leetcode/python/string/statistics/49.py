
from typing import List


class Solution:
    def check(self, dict1: dict, dict2: dict) -> bool:
        for i in dict1:
            if i not in dict2:
                return False
            elif dict1[i] != dict2[i]:
                return False
        if len(dict1) != len(dict2):
            return False
        return True

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dictlist = []
        result = []
        # init dictlist
        size = len(strs)
        for i in range(0, size):
            dict0 = {}
            for j in strs[i]:
                if i not in dict0:
                    dict0[j] = 1
                else:
                    dict0[j] = dict0[j]+1
            dictlist.append(dict0)
        # check dict
        checklist = [False for _ in range(size)]
        for m in range(0, size-1):
            if not checklist[m]:
                for n in range(m+1, size):
                    if not checklist[n]:
                        # same
                        if self.check(dictlist[m], dictlist[n]):
                            tu = [strs[m], strs[n]]
                            result.append(tu)
                            checklist[m]=True
                            checklist[n]=True
                            break
        for k in range(0,size):
            if not checklist[k]:
                result.append([strs[k]])
        return result
    
    
        


solu = Solution()
result = solu.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
