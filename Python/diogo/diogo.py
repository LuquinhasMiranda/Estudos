tanque = int(input())
maximo = tanque

while True:
    if tanque <= 0:
        print("Deives foi pego")
        break
        
    km = int(input())
    
    if km == 0:
        tanque = tanque-1
        
    elif km == 1:
        tanque = tanque + int(input())
        if tanque > maximo:
            tanque = maximo
        
    elif km == 2:
        tanque = tanque - int(input())
        
    elif km == -1:
        print("Deives chegou em casa")
        break