

#include <iostream>
#include <string>
#include <fstream>
#include <stack>  
using namespace std;
int main() {
    string
        maxword = "",
        line,
        buf;
    int count = 0;
    ifstream file("textfile.txt");
    while (!file.eof()) {
        file >> line;
        line += " ";
        for (int i = 0, length = line.length(); i < length; i++) {
            if (tolower(line[i]) >= 'a' && tolower(line[i]) <= 'z') {
                buf += line[i];
                count++;
            }
            else {
                if ((maxword.length() < buf.length()) && (count % 2 == 1))
                    maxword = buf;
                buf.clear();
                count = 0;
            }
        }
    }
    file.close();
    int length = maxword.length();
    stack <string> steck;
    for (int i = 0; i < length; i++) {
        steck.push(maxword.substr(0, 1));
        maxword.erase(0, 1); 
    }
    for (int i = 0; i < length; i++) {
        cout << steck.top();
        steck.pop();
    }
    cout << endl;
    system("pause");
    return 0;
}

