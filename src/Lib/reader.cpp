#include "./../Includes.h"
#include <regex>
//Reader
void reader(){
    std::cout << "Test";
    fstream newFile;
    newFile.open("output.html", ios::out);
    regex regexExp("[a-zA-Z0-9]*");
    int counter = 1;
    //ifstream readFile;
    ifstream file("markdown.md");

    try {
        if (newFile.is_open()){
            string read;
            string file_content = "";
            
            while(getline(file, read)){
                if(read.size() >= 1){
                    
                    for(int i = 0; i < read.size()-1; i++){

                        if(read[i] == read[i+1] /*&& regex_search(read, regexExp) == false*/ ){
                            counter++;

                        }
                    }
                }
                switch(counter) {
                    case 1:
                        file_content = "<h1>" + read + "</h1>" + "</br>" + "\n";
                        //cout << "Case 1 " << file_content << endl;
                        break;
                    case 2:
                        file_content = "<h2>" + read + "</h2>" + "</br>" + "\n";
                        //cout << "Case 2 " << file_content << endl;
                        break;
                    case 3:
                        file_content = "<h3>" + read + "</h3>" + "</br>" + "\n";
                        //cout << "Case 3 " << file_content << endl;
                        break;
                    case 4:
                        file_content = "<h4>" + read + "</h4>" + "</br>" + "\n";
                        //cout << "Case 4 " << file_content << endl;
                        break;
                    case 5:
                        file_content = "<h5>" + read + "</h5>" + "</br>" + "\n";
                        //cout << "Case 5 " << file_content << endl;
                        break;
                    case 6:
                        file_content = "<h6>" + read + "</h6>" + "</br>" + "\n";
                        //cout << "Case 6 " << file_content << endl;
                        break;
                    default:
                        file_content = read + "</br>" + "\n";
                        //cout << "Case default " << file_content << endl;
                }
                counter = 1;
                //file_content = read; 
                cout << file_content << endl;
                newFile << file_content;
            }
            //newFile << "#Test Case \n";
            //newFile << "This is a short description \n";
            newFile.close();
            
        }

        newFile.open("output.html", ios::in);

        if (newFile.is_open()){
            string outputter;
            while (getline(newFile, outputter)) {
                if(outputter[0] == '#' ){
                    cout << "<h1>" << outputter << "</h1>" << "\n";
                }
                cout << outputter << "\n";
            }
            newFile.close();
        }
    } catch (exception e){
    }
}
