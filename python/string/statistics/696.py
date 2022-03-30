class Solution:
    def find_all_indexes(self,input_str, substring):
        l2 = []
        length = len(input_str)
        index = 0
        while index < length:
            i = input_str.find(substring, index)
            if i == -1:
                return l2
            l2.append(i)
            index = i + 1
        return l2
    
    def countBinarySubstrings(self, s: str) -> int:
        index1 = self.find_all_indexes(s,'01')
        index2 = self.find_all_indexes(s,'10')
        size = len(s)
        num=0
        for index in index1:
            step=1
            num+=1
            while index-step>=0 and index +1+step <size:
                if s[index-step]=='0' and s[index+1+step]=='1':
                    num+=1
                    step+=1
                else:
                    break
        for index in index2:
            step=1
            num+=1
            while index-step>=0 and index +1+step <size:
                if s[index-step]=='1' and s[index+1+step]=='0':
                    num+=1
                    step+=1
                else:
                    break            
        return num
    
solu = Solution()
print(solu.countBinarySubstrings('10101'))