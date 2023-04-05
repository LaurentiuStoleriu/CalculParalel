# -*- coding: utf-8 -*-
"""
Created on: Sun Feb 12 17:56:51 2023
author: Laurențiu STOLERIU
"""

import logging.config
import multiprocessing

config = {
    "version": 1,
    "formatters": {
        "default": {
            "format": "%(asctime)s %(message)s"
        }
    },
    "handlers": {
        "console": {
            "formatter": "default",
            "class": "logging.StreamHandler",
            "stream": "ext://sys.stdout"
        }
    },
    "loggers": {
        "my_logger": {
            "handlers": ["console"],
            "level": "INFO"
        }
    }
}

logging.config.dictConfig(config)


def do_work(procID):
    my_logger = logging.getLogger('my_logger')
    my_logger.info(f"Starting work in {procID}")
    i = 0
    for _ in range(50000000):
        i += 1
    my_logger.info(f"Finished work in {procID}")



if __name__ == '__main__':

    logging.info("Main    : START")
    
    ##multiprocessing.set_start_method('spawn')
    for threadID in range(5):
        p = multiprocessing.Process(target=do_work, args=(threadID,))
        p.start()
    
    logging.info("Main    : END")