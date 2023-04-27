from multiprocessing.context import Process
import time

def printArrayContent(array):
    while True:
        print(*array, sep=", ")
        time.sleep(1)
        
if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]

    print("process started")
    p = Process(target=printArrayContent, args=([arr]))
    p.start()
    
    time.sleep(5)
    arr[4] = 2023
    print("am schimbat arr[4]")
