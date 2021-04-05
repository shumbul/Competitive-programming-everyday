// Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/
// Author - Shumbul Arifa

class Solution:
    def findComplement(self, n: int) -> int:
        c = ""
        b = bin(n).replace("0b","")
        b = str(b)
        for i in range(0,len(b)):
            if b[i] == '0':
                c = c + "1"
            else:
                c = c + "0"
        # print(" b ", b, "\n c ", c)
        return int(c,2)