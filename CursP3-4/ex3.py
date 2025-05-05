import time
from datetime import datetime
from multiprocessing import Process


def printTime(when, who):
    now = datetime.now()
    print(f"{who:>5} -> {when:>30} : {now.minute}:{now.second}.{now.microsecond}")


def work(name):
    printTime("start", name)
    contor = 0
    for j in range(100_000_000):
        contor += 1
    printTime(" end ", name)

if __name__ == '__main__':
    printTime("(before creating procs)", "main")

    for procID in range(5):
        p = Process(target=work, args=(procID,))
        p.start()
        
    printTime("(all done)", "main")
