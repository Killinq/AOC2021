#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream input ("input.txt");
    string currentColumn = "";
    int currentIndex = 0;
    int one = 0;
    int zero = 0;
    vector<string> oxygen;
    vector<string> co2;
   
    while (input >> currentColumn)
    {    
        if(currentColumn[0] == '0')
            zero++;
        else 
            one++;
    }

    input.clear();
    input.seekg(0);

    while (input >> currentColumn)
    {
        if (one >= zero)
        {
            if (currentColumn[0] == '1')
                oxygen.push_back(currentColumn);
            if (currentColumn[0] == '0')
                co2.push_back(currentColumn);
        }
        if (one < zero)
        {
            if (currentColumn[0] == '0')
                oxygen.push_back(currentColumn);
            if (currentColumn[0] == '1')
                co2.push_back(currentColumn);
        }
    }
    // start filtering them out
    currentIndex = 1;
    string co2Val = "";
    string oxygenVal = "a";
    for (int i = 1; i < 12; i++)
    {
        one = 0;
        zero = 0;
        for (int j = 0; j < oxygen.size(); j++)
        {
            if (oxygen.at(j).at(currentIndex) == '1')
                one++;
            else
                zero++;
        }
        for (int j = 0; j < oxygen.size(); j++)
        {
            if (one >= zero)
            {
                if (oxygen.at(j).at(currentIndex) == '0')
                {
                    oxygen.erase(oxygen.begin() + j);
                    if (oxygen.size() == 1)
                    {
                        oxygenVal = oxygen[0];
                    }
                    j--;
                }
            }
            else 
            {
                if (oxygen.at(j).at(currentIndex) == '1')
                {
                    oxygen.erase(oxygen.begin() + j);
                    if (oxygen.size() == 1)
                    {
                        oxygenVal = oxygen[0];
                    }
                        
                    j--;
                }
                    
            }
        }
        one = 0;
        zero = 0;
        for (int j = 0; j < co2.size(); j++)
        {
            if (co2.at(j).at(currentIndex) == '1')
                one++;
            else
                zero++;
        }
        for (int j = 0; j < co2.size(); j++)
        {
            if (one >= zero)
            {
                if (co2.at(j).at(currentIndex) == '1')
                {
                    co2.erase(co2.begin() + j);
                    if (co2.size() == 1)
                    {
                        co2Val = co2[0];
                    }
                    j--;
                }
            }
            else 
            {
                if (co2.at(j).at(currentIndex) == '0')
                {
                    co2.erase(co2.begin() + j);
                    if (co2.size() == 1)
                    {
                        co2Val = co2[0];
                    }
                        
                    j--;
                }
                    
            }
        }
        currentIndex++;
    }
    cout << oxygenVal << endl;
    cout << co2Val << endl;
}


int part1()
{
    ifstream input ("input.txt");
    string gamma = "";
    string epsilon = "";
    string currentColumn = "";
    int currentIndex = 0;
    int one = 0;
    int zero = 0;
    for (int i = 0; i < 12; i++)
    {
        while (input >> currentColumn)
        {
            
            if(currentColumn[currentIndex] == '0')
                zero++;
            else 
                one++;
        }
        if (one > zero)
            gamma.append("1");
        else
            gamma.append("0");
        one = 0;
        zero = 0;
        currentIndex++;
        input.clear();
        input.seekg(0);
    }
    //cout << gamma << endl;
    for (char x : gamma)
    {
        if (x == '1')
            epsilon.append("0");
        else
            epsilon.append("1");
    }
    //cout << epsilon;
    int gammaNumber = stoi(gamma, 0, 2);
    int epsilonNumber = stoi(epsilon, 0, 2); // it do be converting them to decimal doe
    //cout << gammaNumber << endl << epsilonNumber << endl;
    //cout << gammaNumber * epsilonNumber << endl;
    return gammaNumber * epsilonNumber;
}