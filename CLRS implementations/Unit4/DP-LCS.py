def lcs_length(X, Y):
	
	m = len(X)
	n = len(Y)

	c = {}
	b = {}

	for i in range(m):
		for j in range(n):
			c[i,j] = 0  
			b[i,j] = 0  


	for i in range(1,m):
		for j in range(1,n):
			if X[i] == Y[j]:
				c[i,j] = c[i-1,j-1] + 1
				b[i,j] = "^\\"

			elif c[i-1,j] >= c[i,j-1]:
				c[i, j] = c[i-1,j]
				b[i, j] = "^|"

			else:
				c[i, j] = c[i, j-1]
				b[i, j] = "<--"

	return c, b

def print_LCS(b, X, i, j):

	if i == -1 or j == -1:
		return

	if b[i,j] == "^\\":
		print_LCS(b, X, i - 1, j - 1)
		print( X[i], end = " " )

	elif b[i,j] == "^|":
		print_LCS(b, X, i - 1, j)

	else:
		print_LCS(b, X, i, j - 1)


if __name__ == '__main__':
	X = ["0","A","B","C","B","D","A","B"]
	Y = ["-0","B","D","C","A","B","A"]

	c, b = lcs_length(X, Y)
	print()
	print_LCS(b, X, len(X) - 1, len(Y) - 1)
