def countLetters(url, frequency):
    response = urllib.request.urlopen(url)
    txt = str(response.read())
    for l in txt:
        letter = l.lower()
        if letter in frequency:
            frequency[letter] = frequency[letter] + 1
    global finishedCount
    finishedCount += 1