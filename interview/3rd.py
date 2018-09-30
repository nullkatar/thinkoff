import sys

def add(out_l, in_l):
	for l in in_l:
		out_l.extend(l) if type(l) == list else out_l.append(l)  

def main():
	user_args = sys.argv[1:]
	N, K = int(user_args[0]), int(user_args[1])
	if N == 1:
		return "1"
	l = inverse_row(N, K, start=1, end=N)

	print(" ".join(map(str, l)))

def inverse_row(N, K, start, end):
	try:
		l = []
		if K == 0:
			return [x for x in range(start, end + 1)]
		if K > 2 * N - 3:
			add(l, [end, inverse_row(N - 2, K - (2 * N - 3), start + 1, end - 1), start])
			return l

		n = (K + 3) / 2

		if (K + 3) % 2 == 0:
			g1 = [x for x in range(start + 1, start + n - 1)]
			g2 = [x for x in range(start + n, end + 1)]
			add(l, [start + n - 1, g1, start, g2])
			return l
		
		if n > 3:
			g1 = [x for x in range(start + 3, start + n - 1)]
			g2 = [x for x in range(start + n, end + 1)]
			add(l, [start + n - 1, start + 2, start + 1, g1, start, g2])
			return l
		
		if N - n >= 2:
			print(3)
			g1 = [x for x in range(start + 1, start + n - 1)]
			g2 = [x for x in range(start + n + 2, end + 1)]
			add(l, [start + n - 1, g1, start, start + n + 1, start + n, g2])
			return l

		if N - n == 1:
			g1 = [x for x in range(start + 1, start + n - 1)]
			add(l, [start + n - 1, g1, end, start])
			return l

main()
