#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream inputFile("input2.txt");
    string currentLine;
    string forward = "forward";
    string up = "up";
    string down = "down";

    int horizontal = 0;
    int depth = 0;
    int aim = 0;
    while (inputFile >> currentLine)
    {
        if (currentLine.compare(forward) == 0)
        {
            int tempStringToInt;
            inputFile >> tempStringToInt;
            horizontal += tempStringToInt;
            depth += tempStringToInt * aim;
        }
        
        else if (currentLine.compare(down) == 0)
        {
            int tempStringToInt;
            inputFile >> tempStringToInt;
            //depth += tempStringToInt;
            aim += tempStringToInt;
        }
        else if (currentLine.compare(up) == 0)
        {
            int tempStringToInt;
            inputFile >> tempStringToInt;
            //depth -= tempStringToInt;
            aim -= tempStringToInt;
        }

    }
    cout << (horizontal * depth);
    return 0;
}