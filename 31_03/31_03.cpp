#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileManager {
    string m_file_path;
public:
    FileManager(const string& file_path) {
        this->m_file_path = m_file_path;
    }

    bool read(string& data) {
        ifstream file(m_file_path);
        if (file.is_open()) {
            getline(file, data);
            file.close();
            return true;
        }
        return false;
    }
    bool write(const string& data) {
        ofstream file(m_file_path);
        if (file.is_open()) {
            file << data;
            file.close();
            return true;
        }
        return false;
    }
    bool remove() {
        if (std::remove(m_file_path.c_str()) == 0) {
            return true;
        }
        return false;
    }
};

class DataProcessor {
public:
    bool process(const string& data) {
        return true;
    }
};

int main() {
    FileManager file_manager("example.txt");
    string data;
    if (file_manager.read(data)) {
        DataProcessor processor;
        if (processor.process(data)) {
            if (file_manager.remove()) {
                cout << "File deleted\n";
            }
            else {
                cout << "Error deleting file\n";
            }
        }
        else {
            cout << "Error\n";
        }
    }
    else {
        cout << "Error\n";
    }
    return 0;
}
