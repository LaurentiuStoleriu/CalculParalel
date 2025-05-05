import time
from threading import Thread, Lock

money = 100
mutex = Lock()


def zece():
    return 10

def depuneBani():
    global money, mutex
    for i in range(1_000_000):
        mutex.acquire()
        money += zece()
        mutex.release()

def extrageBani():
    global money, mutex
    for i in range(1_000_000):
        mutex.acquire()
        money -= zece()
        mutex.release()

Thread(target=depuneBani, args=()).start()
Thread(target=extrageBani, args=()).start()

time.sleep(3)

print(f"In cont au ramas: {money}")
