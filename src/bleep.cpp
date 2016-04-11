#include <eecs230.h>

// check if the input string matches a string inside the input vector of strings
bool checkWord(vector<string> list, string input){
    for(int i=0; i < list.size(); ++i) {
        if (input == list[i])
            return true;
    }
    return false;
}

vector<string> getBleepedWords() {
    vector<string> list;
    string temp;
    cout << "enter a list of words, separated by a space, followed by the word 'end': ";
    while (temp != "end") {
        cin >> temp;
        list.push_back(temp);
    }
    return list;
}

int main() {
    vector<string> bleepedList = getBleepedWords();

    while(true) { // infinite loop to act as a program that always asks for words
        string entered_word;
        cout << "enter a word to check, or if done, enter the word 'end': ";
        cin >> entered_word;

        if (entered_word == "end")
            return 0;

        if (checkWord(bleepedList, entered_word)) // check the word
            cout << "bleep!" << "\n";
        else
            cout << entered_word << " is clear!" << "\n";
    }

}
