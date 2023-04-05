# -*- coding: utf-8 -*-
"""
Created on: Sun Feb 19 21:56:33 2023
author: Laurențiu STOLERIU
"""


import urllib.request
import threading
import time


finished_count = 0
NUM_FILES = 10


def count_letters(url, frequency, mutex):
    response = urllib.request.urlopen(url)
    txt = str(response.read())
    mutex.acquire()
    for l in txt:
        letter = l.lower()
        if letter in frequency:
            frequency[letter] += 1
    global finished_count
    finished_count += 1
    mutex.release()
    
    

if __name__ == '__main__':
    
    frequency = {}
    
    mutex = threading.Lock()
    
    for c in "abcdefghijklmnopqrstuvwxyz":
        frequency[c] = 0
        
    start = time.time()
    
    for i in range(1000, 1020):
        threading.Thread(target=count_letters, args=(f"https://www.rfc-editor.org/rfc/rfc{i}.txt", frequency, mutex)).start()
    
    while True:
        mutex.acquire()
        if finished_count == 20:
            break
        mutex.release()
        time.sleep(0.5)
    
    end = time.time()
    
    print(frequency)
    
    print(f"Done, time taken -> {(1000*(end - start)):.0f} ms")
