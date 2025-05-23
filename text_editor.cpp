#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile(const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        cout << "Enter text (type 'END' on a new line to finish):\n";
        string line;
        while (getline(cin, line)) {
            if (line == "END") break;
            file << line << endl;
        }
        file.close();
        cout << "✅ File saved!\n";
    } else {
        cout << "❌ Error creating file.\n";
    }
}

void readFile(const string &filename) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "📖 File content:\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "❌ Error opening file.\n";
    }
}

void appendFile(const string &filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        cout << "Enter text to append (type 'END' to finish):\n";
        string line;
        while (getline(cin, line)) {
            if (line == "END") break;
            file << line << endl;
        }
        file.close();
        cout << "✅ Text appended!\n";
    } else {
        cout << "❌ Error opening file.\n";
    }
}

void clearFile(const string &filename) {
    ofstream file(filename, ios::trunc);
    if (file.is_open()) {
        cout << "🧹 File cleared!\n";
        file.close();
    } else {
        cout << "❌ Error clearing file.\n";
    }
}

int main() {
    string filename;
    int choice;

    cout << "📝 Welcome to Mini Text Editor\n";
    cout << "Enter filename (e.g., notes.txt): ";
    cin >> filename;
    cin.ignore(); // Clear newline from buffer

    do {
        cout << "\n📋 MENU\n";
        cout << "1. Create/Overwrite file\n";
        cout << "2. Read file\n";
        cout << "3. Append text\n";
        cout << "4. Clear file\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: createFile(filename); break;
            case 2: readFile(filename); break;
            case 3: appendFile(filename); break;
            case 4: clearFile(filename); break;
            case 5: cout << "👋 Goodbye!\n"; break;
            default: cout << "❌ Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
