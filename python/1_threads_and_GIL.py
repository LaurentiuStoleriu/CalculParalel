# -*- coding: utf-8 -*-
"""
Created on: Sun Feb 12 17:56:51 2023
author: Laurențiu STOLERIU
"""

import logging
import threading


def do_work(threadID):
    logging.info(f"Starting work in {threadID}")
    i = 0
    for _ in range(50000000):
        i += 1
    logging.info(f"Finished work in {threadID}")


if __name__ == '__main__':
    
    format = "%(asctime)s %(message)s"
    logging.basicConfig(format=format, level=logging.INFO)

    logging.info("Main    : START")
    
    thrd = []
    
    for threadID in range(5):
        t = threading.Thread(target=do_work, args=(threadID,))
        thrd.append(t)
        thrd[threadID].start()
        
    for threadID in range(5):
        thrd[threadID].join()
        
    
    logging.info("Main    : END")
    

