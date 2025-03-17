#include <algorithm>
#include <ctime>
#include <iostream>

#define arraySize 32768

using namespace std;

int main()
{
    int data[arraySize];
    unsigned int i, c;
    double elapsedTime;

    for (c = 0; c < arraySize; ++c)
        data[c] = rand() % 256;

    //sort(data, data + arraySize);

    clock_t start = clock();
    long long sum = 0;

    for (i = 0; i < 100000; ++i)
    {
        for (unsigned c = 0; c < arraySize; ++c)
        {
            if (data[c] >= 128)
                    sum += data[c];
        }
    }

    elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    cout << elapsedTime << endl;
    cout << "sum = " << sum << endl;
}
