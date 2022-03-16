class Solution:
    def frequencySort(self, s: str) -> str:
        # sstr = sorted(s)
        # fre=[0]*52
        # for i in sstr:
        # hash store the frequency
        chardict = {}
        for i in s:
            if i not in chardict:
                chardict[i] = 1
            else:
                chardict[i] += 1
        # rank
        # newdict = { k, v for k, v in sorted(chardict.items(), key=lambda item:item[1],reverse=True)}
        newdict = dict(
            sorted(chardict.items(), key=lambda item: item[1], reverse=True))
        # get result
        result = ''
        for k, v in newdict.items():
            result += str(k)*v
        return result


solu = Solution()
print(solu.frequencySort('tree'))
print(solu.frequencySort('aaaccc'))
print(solu.frequencySort('Aabb'))
