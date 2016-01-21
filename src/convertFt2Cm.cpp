#include "eecs230.h"

/*
 * Part 1: Foot-to-Centimeter Converter
 */

// ft2cm is a function that takes the input ftIn of type double
// and will return a double
double ft2cm(double ftIn) {
    return 12*2.54*ftIn;
}

// allow input of numbers, separated by spaces, and ended with a 0
// 12 4 5.5 0 will yield a vector of {12,4,5.5}
vector<double> getFtInput() {
    vector<double> inputs;
    int i = 0;
    double temp;
    cout << "input numbers to convert from feet to cm, followed by 0 to end: ";
    while (cin) {
        cin >> temp;
        if (temp == 0)
            break;
        else if (temp < 0)
            error("you have entered a negative number!");
        inputs.push_back(temp);
    }
    return inputs;
}

// convert an input of a vector of doubles in feet to centimeters
vector<double> convertFtv2Cmv(vector<double> inList) {
    vector<double> converted;
    for (int i = 0; i < inList.size(); ++i) {
        converted.push_back(ft2cm(inList[i]));
    }
    return converted;
}

// print out every value in inList
void coutTheOutput(vector<double> inList) {
    for (int i = 0; i < inList.size(); ++i) {
        cout << inList[i] << " ";
    }
}

// final assembly
int main()
try {
    vector<double> input = getFtInput();
    vector<double> converted = convertFtv2Cmv(input);
    coutTheOutput(converted);
}
catch (runtime_error& e) {
    cerr << "runtime error: " << e.what() << '\n';
    return 1;
}