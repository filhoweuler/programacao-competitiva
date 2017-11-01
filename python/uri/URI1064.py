
#URI 1064
#Weuler Borges Santos Filho

pos = 0
avg = 0
for i in range(6):
	a = float(input())
	if a > 0:
		pos+=1
		avg+=a

print("%d valores positivos" %pos)
print(avg/pos)



