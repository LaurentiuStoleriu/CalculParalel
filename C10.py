import time
from threading import Thread

money = 100

def zece():
    return(10)
# Simulăm o operațiune de depunere și extragere de bani
def depuneBani():
    global money
    for i in range(1_000_000):
        money += zece()

def extrageBani():
    global money
    for i in range(1_000_000):
        money -= zece()

Thread(target=depuneBani, args=()).start()
Thread(target=extrageBani, args=()).start()

time.sleep(3)

print(f"In cont au ramas: {money}")
