from multiprocessing.context import Process
import multiprocessing
import time

def printArrayContent(array):
    while True:
        print(*array, sep=", ")
        time.sleep(0.5)
        
if __name__ == "__main__":
    #arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    arr = multiprocessing.Array('i', [1, 2, 3, 4, 5, 6, 7, 8, 9], lock=True)
    print("process started")
    p = Process(target=printArrayContent, args=([arr]))
    p.start()
    
    for i in range(1):
        time.sleep(2)
        arr[4] = 2023
        print("am schimbat arr[4]")