import time
from datetime import datetime


def printTime(when):
    now = datetime.now()
    print(f"{when} : {now.minute}:{now.second}.{now.microsecond}")

def work():
    printTime("start")
    time.sleep(3)
    printTime(" end ")
    
for i in range(5):
    work()