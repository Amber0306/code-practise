from typing import List

class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sortScore = list(sorted(score,reverse=True))
        size = len(score)
        # if size == 0:
        #     return []
        # if size == 1: return ['Gold Medal']
        # if size == 2:
        #     if score[0]>score[1]:return ['Gold Medal','Silver Medal'] 
        #     else: return ['Silver Medal','Gold Medal']
        for i in range(0,size):
            ind = score.index(sortScore[i])
            if i == 0:
                score[ind] = 'Gold Medal'
            elif i == 1:
                score[ind] = 'Silver Medal'
            elif i == 2:
                score[ind] = 'Bronze Medal'
            else:
                score[ind] = str(i+1)
        return score

solu = Solution()
result = solu.findRelativeRanks([10,3,8,9,4])
print(result)