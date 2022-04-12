class Solution:
    def originalDigits(self,s:str)->str:
        ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"]
        chardict={"e":0,"g":0,"f":0,"i":0,"h":0,"o":0,"n":0,"s":0,"r":0,"u":0,"t":0,"w":0,"v":0,"x":0,"z":0}
        for c in s:
            if c not in chardict:
                chardict[c] = 1
            else:
                chardict[c] += 1
        # compare chardict with words
        # ['zero','one','two','three','four','five','six','seven','eight','nine']
        # ["e"0135789,"g"8,"f"45,"i"5689,"h"38,"o"0124,"n"179,
        # "s"67,"r"034,"u"4,"t"238,"w"2,"v"57,"x"6,"z"0]
        # 一次求出0 2 4 6 8
        # 一位求出5 3 7
        # 二位求出 0124->1 179->9
        result = ''
        if chardict['z']>0:
            num = chardict['z']
            result += '0'*num
            chardict['z'] -= num
            chardict['e'] -= num
            chardict['r'] -= num
            chardict['o'] -= num
        if chardict['w']>0:
            num = chardict['w']
            result += '2'*num
            chardict['t'] -= num
            chardict['w'] -= num
            chardict['o'] -= num
        if chardict['u']>0:
            num = chardict['u']
            result += '4'*num
            chardict['f'] -= num
            chardict['o'] -= num
            chardict['u'] -= num
            chardict['r'] -= num
        if chardict['x']>0:
            num = chardict['x']
            result += '6'*num
            chardict['s'] -= num
            chardict['i'] -= num
            chardict['x'] -= num
        if chardict['g']>0:
            num = chardict['g']
            result += '8'*num
            chardict['e'] -= num
            chardict['i'] -= num
            chardict['g'] -= num
            chardict['h'] -= num
            chardict['t'] -= num
        if chardict['h']>0:
            num = chardict['h']
            result += '3'*num
            chardict['t'] -= num
            chardict['h'] -= num
            chardict['r'] -= num
            chardict['e'] -= num*2
        if chardict['f']>0:
            num = chardict['f']
            result += '5'*num
            chardict['f'] -= num
            chardict['i'] -= num
            chardict['v'] -= num
            chardict['e'] -= num
        if chardict['v']>0:
            num = chardict['v']
            result += '7'*num
            chardict['s'] -= num
            chardict['e'] -= num*2
            chardict['v'] -= num
            chardict['n'] -= num
        if chardict['o']>0:
            num = chardict['o']
            result += '1'*num
            chardict['o'] -= num
            chardict['n'] -= num
            chardict['e'] -= num
        if chardict['i']>0:
            num = chardict['i']
            result += '9'*num
            chardict['n'] -= num*2
            chardict['e'] -= num
            chardict['i'] -= num
        return sorted(result)
    

solu = Solution()
solu.originalDigits('fviefuro')