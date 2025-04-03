import time
from datetime import datetime
from threading import Thread

def printTime(when):
    now = datetime.now()
    print(f"{when} : {now.minute}:{now.second}.{now.microsecond}")

def work_in_background():
    while True:
        printTime("working in background")
        time.sleep(1)

for i in range(5):
    thread = Thread(target=work_in_background, args=())
    thread.daemon = True
    thread.start()

time.sleep(5)
print("Main program complete")
