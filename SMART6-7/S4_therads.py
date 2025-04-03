from datetime import datetime
from threading import Thread

def printTime(when, who):
    now = datetime.now()
    print(f"{who:>5} -> {when:>10} : {now.minute}:{now.second}.{now.microsecond}")

def work(name):
    printTime("start", name)
    contor = 0
    for j in range(20_000_000):
        contor += 1
    printTime(" end ", name)

for i in range(5):
    thread = Thread(target=work, args=(i,))
    thread.start()
