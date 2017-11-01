
#URI 1018
#Weuler Borges Santos Filho

line = str(input())
line = line.split(" ")

a = int(line[0])
b = int(line[1])
c = int(line[2])
d = int(line[3])

if (b > c) and (d > a) and (c + d > a + b) and (c > 0) and (d > 0) and (a % 2 == 0):
	print("Valores aceitos")
else:
	print("Valores nao aceitos")