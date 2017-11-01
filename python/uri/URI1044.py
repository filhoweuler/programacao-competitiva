
#URI 1044
#Weuler Borges Santos Filho

line = str(input())
line = line.split(" ")

a = int(line[0])
b = int(line[1])

if a%b == 0 or b%a == 0:
	print("Sao Multiplos")
else:
	print("Nao sao Multiplos")