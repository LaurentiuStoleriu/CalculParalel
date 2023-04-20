from multiprocessing.context import Process
import time

def printArrayContent(array):
    while True:
        print(*array, sep=", ")
        time.sleep(1)
        
if __name__ == "__main__":
    arr = [-1] * 10
    print("process started")
    p = Process(target=printArrayContent, args=([arr]))
    p.start()
    
    for i in range(10):
        time.sleep(2)