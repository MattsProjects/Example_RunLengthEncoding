// Example_RunLengthEncoding.cpp
// This file shows an example of Run Length Encoding
// Author: Matthew Breit (github.com/mattsprojects)
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string RLE(const string &line)
{
    string strOutput = "";

    // parse the input string into a vector of numbers
    vector<int> numbers;
    string s = "";
    int number = 0;
    std::string::size_type sz;
    for (int i = 0; i < line.size() + 1; i++)
    {
        if (line[i] == ' ' || i == line.size())
        {
            number = stoi(s, &sz, 10);
            numbers.push_back(number);
            s = "";
        }
        else
            s = s + line[i];
    }

    // do RLE on vector of numbers and place in output vector.
    vector<int> output;
    int count = 0;
    int previous = numbers[0];
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] != previous)
        {
            output.push_back(count);
            output.push_back(previous);
            count = 1;
            previous = numbers[i];
        }
        else
            count++;
    }
    output.push_back(count);
    output.push_back(previous);

    // dump the output vector to a string and return it.
    for (int i = 0; i < output.size(); i++)
    {
        strOutput.append(to_string(output[i]));
        strOutput.append(" ");
    }

    return strOutput;
}

int TEST_RLE()
{
    string strTest = "12 32 32 56 56 87 87 87 87 87 55 43";
    string expected = "1 12 2 32 2 56 5 87 1 55 1 43";
    string result = "";

    result = RLE(strTest);

    cout << "TEST_RLE()" << endl;
    cout << "Input    : " << strTest << endl;
    cout << "Expected : " << expected << endl;
    cout << "Result   : " << result << endl;
    cout << endl;

    return 0;
}

int main()
{
    TEST_RLE();

    string line = "";
    string lineRLE = "";

    // get input line of numbers
    cout << "Enter numbers (separated by whitespace) : ";
    getline(cin, line);

    // do RLE
    lineRLE = RLE(line);
    cout << "RLE           : " << lineRLE << endl;
}