from datetime import datetime
from threading import Thread

def printTime(when, who):
    now = datetime.now()
    print(f"{who:>5} -> {when:>30} : {now.minute}:{now.second}.{now.microsecond}")
    
def work(name):
    printTime("start", name)
    contor = 0
    for j in range(20_000_000):
        contor += 1
    printTime(" end ", name)

if __name__ == "__main__":
    printTime("(before creating thread)", "main")
    t = Thread(target=work, args=(1,))
    printTime("(before running  thread)", "main")

    t.start()   
    
    printTime("(waiting thread)", "main")
    t.join()
    
    printTime("(all done)", "main")
