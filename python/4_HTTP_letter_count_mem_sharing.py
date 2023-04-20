import time
import urllib.request
from threading import Thread

finished_count = 0
NUM_FILES = 30

def count_letters(url, frequency):
    response = urllib.request.urlopen(url)
    txt = str(response.read())
    for l in txt:
        letter = l.lower()
        if letter in frequency:
            frequency[letter] += 1
    global finished_count
    finished_count += 1

if __name__ == '__main__':
    frequency = {}

    for c in "abcdefghijklmnopqrstuvwxyz":
        frequency[c] = 0
    start = time.time()

    for i in range(1000, 1000+NUM_FILES):
        Thread(target=count_letters, args=(f"https://www.rfc-editor.org/rfc/rfc{i}.txt", frequency)).start()
    
    while finished_count < NUM_FILES:
        time.sleep(0.5)
    
    end = time.time()
    
    print(frequency)
    
    print(f"Done, time taken -> {(1000*(end - start)):.0f} ms")
