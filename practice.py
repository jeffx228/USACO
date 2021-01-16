def fill(s, numRows, mat):
        i = 0
        r = 0
        c = 0

        while i < len(s):
            while r < numRows-1 and i < len(s):
                mat[r][c] = s[i]
                i += 1
                r += 1
                
            while r > 0 and i < len(s):
                mat[r][c] = s[i]
                i += 1
                c += 1
                r -= 1
            
            for k in range(numRows):
                for l in range(len(s)):
                    print(mat[k][l], end='')
                print("")
        
        return mat

def convert(s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        ans = ""
        rows, cols = (numRows, len(s)) 

        arr = [[""]*cols for _ in range(rows)]
        
        for i in range(rows):
            for j in range(cols):
                arr[i][j] = ""
        
        arr = fill(s, numRows, arr)
        
        for i in range(numRows):
            for j in range(len(s)):
                if not arr[i][j] == None:
                    ans += arr[i][j]
        
        return ans

answer = convert("PAYPALISHIRING", 3)

print(answer)