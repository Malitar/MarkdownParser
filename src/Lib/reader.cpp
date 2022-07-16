#include "./../Includes.h"

//Reader
void reader(){
    std::cout << "Test";
    fstream newFile;
    newFile.open("output.html", ios::out);

    try {
        if (newFile.is_open()){
            newFile << "Test Case \n";
            newFile << "This is a short description \n";
            newFile.close();
        }

        newFile.open("output.html", ios::in);

        if (newFile.is_open()){
            string outputter;
            while (getline(newFile, outputter)) {
                cout << outputter << "\n";
            }
            newFile.close();
        }
    } catch (exception e){
    }
}
