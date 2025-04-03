import time
from datetime import datetime
from threading import Thread

def printTime(when):
    now = datetime.now()
    print(f"{when} : {now.minute}:{now.second}.{now.microsecond}")

def work():
    printTime("start")
    contor = 0
    for j in range(20_000_000):
        contor += 1
    printTime(" end ")

for i in range(5):
    t = Thread(target=work, args=())
    t.start()

