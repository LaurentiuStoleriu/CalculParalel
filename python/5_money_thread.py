import time
from threading import Thread

money = 100

def depuneBani():
    global money
    for i in range(1_000_000):
        money += 10

def extrageBani():
    global money
    for i in range(1_000_000):
        money -= 10

# produce data races la python mai vechi de 3.9
Thread(target=depuneBani, args=()).start()
Thread(target=extrageBani, args=()).start()

time.sleep(3)

print(f"In cont au ramas: {money}")
