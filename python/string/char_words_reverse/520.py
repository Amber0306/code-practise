class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        # 大写字母个数
        capital = 0
        length = len(word)
        #  首字母大写
        flag = False
        #  长度检测
        if length == 0:
            return False
        
        # 首字母检测
        first = ord(word[0])
        if first <=90:
            flag = True
            capital = capital + 1 
        
        #  计算大写字母个数
        for i in range(1, length):
            asc = ord(word[i])
            if asc >=65 and asc <=90:
                if not flag:
                    # 首字母不是大写，后面出现了大写
                    return False
                capital = capital + 1 

        if capital == 0 or capital == length or capital == 1:
            return True

        return False


def main():
    solution = Solution()
    print("hello,world")
    result = solution.detectCapitalUse('Google')
    print(str(result))
    result = solution.detectCapitalUse('USA')
    print(result)
    result = solution.detectCapitalUse('sEts')
    print(result)
    result = solution.detectCapitalUse('GattaV')
    print(result)


if __name__ == '__main__':
    main()