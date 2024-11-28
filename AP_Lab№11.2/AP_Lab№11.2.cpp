#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int CountWordsInFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return -1;
    }

    string line;
    int wordCount = 0;

        string word;

        while (file >> word) {
            wordCount++;
        }
    

    file.close();
    return wordCount;
}

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    int result = CountWordsInFile(filename);

    if (result >= 0) {
        cout << "Total words in the file: " << result << endl;
    }

    return 0;
}