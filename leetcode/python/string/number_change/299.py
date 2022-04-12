class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        A = 0
        B = 0
        size = len(secret)
        dict1 = [0]*10
        dict2 = [0]*10
        # get A
        for i in range(0,size):
            ch1 = int(secret[i])
            ch2 = int(guess[i])
            if  ch1 == ch2:
                A+=1
            dict1[ch1]+=1
            dict2[ch2]+=1

        for i in range(0,10):
            B+=min(dict1[i],dict2[i])
        B = B-A
        return str(A)+'A'+str(B)+'B'



solu = Solution()
result1 = solu.getHint('1807','7810')
result2 = solu.getHint('1123','0111')