# -*- coding: utf-8 -*-
"""
Created on: Sun Feb 19 21:56:33 2023
author: Laurențiu STOLERIU
"""

import logging
#import urllib.request
import time


def count_letters(myBook, frq):
    
    #response = urllib.request.urlopen(myURL)
    #txt = str(response.read())
    
    with open(myBook) as f:
        txt = f.read()
    
    for lett in txt:
        letter = lett.lower()
        if letter in frq:
            frq[letter] += 1
    
    

if __name__ == '__main__':
    
    #format = "{asctime}.{msecs:03.0f} (message)"
    format = "%(asctime)s %(message)s"
    logging.basicConfig(format=format, level=logging.INFO)
    
    start = time.time()
    logging.info("START")

    
    frequency = {}
    for lett in "abcdefghijklmnopqrstuvwxyz":
        frequency[lett] = 0
    
    #for i in range(20):
    for book in {"Book_Dracula.txt", "Book_Karamazov.txt", "Book_Mysteries.txt", "Book_Quixote.txt", "Book_Romeo.txt"}:
        count_letters(book, frequency)
    
    end = time.time()
    logging.info(f"END in {(1000*(end-start)):.0f} ms")
    
    print(frequency)