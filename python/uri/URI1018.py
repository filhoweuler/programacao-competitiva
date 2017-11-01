
#URI 1018
#Weuler Borges Santos Filho

valor = int(input())
print(valor)
print("%d notas de R$ 100,00" %(valor/100))
valor = valor%100
print("%d notas de R$ 50,00" %(valor/50))
valor = valor%50
print("%d notas de R$ 20,00" %(valor/20))
valor = valor%20
print("%d notas de R$ 10,00" %(valor/10))
valor = valor%10
print("%d notas de R$ 5,00" %(valor/5))
valor = valor%5
print("%d notas de R$ 2,00" %(valor/2))
valor = valor%2
print("%d notas de R$ 1,00" %valor)