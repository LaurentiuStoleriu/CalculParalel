# -*- coding: utf-8 -*-
"""
Created on: Sun Feb 19 21:56:33 2023
author: Laurențiu STOLERIU
"""

import logging
#import urllib.request
import threading
import time



finished_count = 0


def count_letters(myBook, frq):
    
    #response = urllib.request.urlopen(myURL)
    #txt = str(response.read())
    
    with open(myBook) as f:
        txt = f.read()
    
    for lett in txt:
        letter = lett.lower()
        if letter in frq:
            frq[letter] += 1

    global finished_count
    finished_count += 1
    
    

if __name__ == '__main__':
    
    #format = "{asctime}.{msecs:03.0f} (message)"
    format = "%(asctime)s %(message)s"
    logging.basicConfig(format=format, level=logging.INFO)
    
    start = time.time()
    logging.info("START")

    
    frequency = {}
    for lett in "abcdefghijklmnopqrstuvwxyz":
        frequency[lett] = 0
    
    
    t1 = threading.Thread(target=count_letters, args=("Book_Dracula.txt", frequency))
    t2 = threading.Thread(target=count_letters, args=("Book_Karamazov.txt", frequency))
    t3 = threading.Thread(target=count_letters, args=("Book_Mysteries.txt", frequency))
    t4 = threading.Thread(target=count_letters, args=("Book_Quixote.txt", frequency))
    t5 = threading.Thread(target=count_letters, args=("Book_Romeo.txt", frequency))
    t1.start()
    t2.start()
    t3.start()
    t4.start()
    t5.start()
   

    while finished_count < 5:
        time.sleep(0.5)
    
    end = time.time()
    logging.info(f"END in {(1000*(end-start)):.0f} ms")
    
    print(frequency)