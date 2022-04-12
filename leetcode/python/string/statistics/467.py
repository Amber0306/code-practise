class Solution:
    def cut(self, s: str):
        results = []
        num = 0
        # x + 1 表示子字符串长度
        for x in range(len(s)):
            # i 表示偏移量
            for i in range(len(s) - x):
                results.append(s[i:i + x + 1])
        return results

    def findSubstringInWraproundString(self, p: str) -> int:
        seqlist = []
        seq = {'a':'b','b':'c','c':'d','d':'e','e':'f','f':'g','g':'h','h':'i','i':'j',
            'j':'k','k':'l','l':'m','m':'n','n':'o','o':'p','p':'q','q':'r','r':'s','s':'t',
            't':'u','u':'v','v':'w','w':'x','x':'y','y':'z','z':'a'}
        size = len(p)
        temp=''
        for i in range(0,size):
            temp+=p[i]
            if i>=0 and i+1 < size:
                if seq[p[i]]==p[i+1]:
                    continue;
                else:                    
                    if temp not in seqlist:
                        seqlist.append(temp)
                    temp=''
            else:
                if temp not in seqlist:
                        seqlist.append(temp)

        sets =  []
        for s in seqlist:
            li = self.cut(s)
            for l in li:
                if l not in sets:
                    sets.append(l)
            # abcd a b c d ab bc cd abc bcd abcd 4321=10 4*5/2
            # [abc, a, d]  [abc,d] a [abc, bcd] [a,b,c,ab,bc,abc,,b,c,d,bc,cd,bcd]
        return len(sets)

    
solu = Solution()
result1 = solu.findSubstringInWraproundString('a')
result2 = solu.findSubstringInWraproundString('cac')
result3 = solu.findSubstringInWraproundString('zaba')
print('end')