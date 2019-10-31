from sys import stdin, stdout  
  
def main(): 
	n = int(stdin.readline())
	for i in range(n):
		n, d = [int(x) for x in stdin.readline().split()] 
		h = [int(x) for x in stdin.readline().split()] 
		minH = min(h)
		maxH = max(h)
		cache = { 0: len(h) }
		t = [int(x) for x in stdin.readline().split()]
		res = ''
		cant = 0
		lastRigth = len(h)
		for time in t:
			if time < maxH and time > minH:
				for initPointIsland in cache:
					flagNewIsland = False
					flagFreeze = False
					for indexSky in range(initPointIsland, cache[initPointIsland]):
						print(indexSky,flagFreeze, "dsddj")
						if h[indexSky] <= time and not flagFreeze:
							flagFreeze = True
							if not flagNewIsland and initPointIsland - indexSky > 1:
								lastRigth = cache[initPointIsland]
								cache[initPointIsland] = indexSky
								flagNewIsland = True
								cant+=1
							elif not flagNewIsland and initPointIsland - indexSky == 1:
								cant+=1
						elif flagNewIsland:
							flagFreeze = False
							flagNewIsland = False
							cache[indexSky] = lastRigth
			if time < minH:
				cant = 1
			res+=(str(cant) + ' ')
		stdout.write(res + '\n')
if __name__ == "__main__": 
	main()