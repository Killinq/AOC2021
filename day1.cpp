#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream inputfile("input.txt");
    vector<int> itholdsthings;
    int val;
    int prevVal = 1000000;
    int counterpt1 = 0;
    int counterpt2 = 0;
    while (inputfile >> val)
    {
       if (prevVal < val)
       {
           counterpt1++;
       }
       prevVal = val;
       itholdsthings.push_back(val);
       
    }
    cout << counterpt1 << endl;
    for (int i = 0; i < itholdsthings.size()-3; i++)
    {
        // if no cheese
        /*int firstSum = itholdsthings.at(i) + itholdsthings.at(i+1) + itholdsthings.at(i+2);
        int secondSum = itholdsthings.at(i+1) + itholdsthings.at(i+2) + itholdsthings.at(i+3);
        
        if (secondSum > firstSum)
            counter++;*/

        if (itholdsthings.at(i) < itholdsthings.at(i+3))
            counterpt2++;
    }
    cout << counterpt2 << endl;
    
    return 0;
}