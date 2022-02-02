class Solution:
    def isPalindrome(self, s: str) -> bool:
        length = len(s)
        left = 0
        right = length-1
        
        while left < right:
            while not s[left].isalnum() and left < right:
                left = left + 1
            while not s[right].isalnum() and left < right:
                right = right - 1
            if s[left].upper() != s[right].upper():
                return False
            left = left + 1
            right = right - 1

        return True


def main():
    print('hello')
    solu = Solution()
    print(solu.isPalindrome('A man, a plan, a canal: Panama'))
    print(solu.isPalindrome('race a car'))
    print(solu.isPalindrome('.,:'))



if __name__ =='__main__':
    main()