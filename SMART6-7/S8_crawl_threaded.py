import urllib.request
import time
from threading import Thread


finishedCount = 0
NUM_FILES = 50

def countLetters(url, frequency):
    response = urllib.request.urlopen(url)
    txt = str(response.read())
    for l in txt:
        letter = l.lower()
        if letter in frequency:
            frequency[letter] = frequency[letter] + 1
    global finishedCount
    finishedCount += 1


if __name__ == '__main__':
    frequency = {}
    for c in "abcdefghijklmnopqrstuvwxyz":
        frequency[c] = 0

    start = time.time()
    for i in range(1000, 1000+NUM_FILES):
        Thread(target=countLetters, args=(f"https://www.rfc-editor.org/rfc/rfc{i}.txt", frequency)).start()

    while finishedCount < NUM_FILES:
        time.sleep(0.5)                   

    end = time.time()

    print(frequency)
    print(f"Done, time taken -> {(1000*(end - start)):.0f} ms")
