#include "./../Includes.h"
#include <regex>
string modifyHtmlString(string file_content_line);
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
                cout << "Read size: " << read.size();
                
                file_content = modifyHtmlString(read);
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

/***
 * Read current line and modify string from .md to .html
 * 
 * @param string file_content_line
 * 
 * @return string
 * */

string modifyHtmlString(string file_content_line) {
    int counter = 1;
    string file_content = "";
    if(file_content_line.size() >= 1 && file_content_line[0] == '#'){         
        for(int i = 0; i < file_content_line.size()-1; i++){

            if(file_content_line[i] == file_content_line[i+1] /*&& regex_search(read, regexExp) == false*/ ){
                counter++;

            }
        }
    }
    // remove '#' from current line
    file_content_line.erase(0, counter);
    
    switch(counter) {
        case 1:
            file_content = "<h1>" + file_content_line + "</h1>" + "</br>" + "\n";
            //cout << "Case 1 " << file_content << endl;
            break;
        case 2:
            file_content = "<h2>" + file_content_line + "</h2>" + "</br>" + "\n";
            //cout << "Case 2 " << file_content << endl;
            break;
        case 3:
            file_content = "<h3>" + file_content_line + "</h3>" + "</br>" + "\n";
            //cout << "Case 3 " << file_content << endl;
            break;
        case 4:
            file_content = "<h4>" + file_content_line + "</h4>" + "</br>" + "\n";
            //cout << "Case 4 " << file_content << endl;
            break;
        case 5:
            file_content = "<h5>" + file_content_line + "</h5>" + "</br>" + "\n";
            //cout << "Case 5 " << file_content << endl;
            break;
        case 6:
            file_content = "<h6>" + file_content_line + "</h6>" + "</br>" + "\n";
            //cout << "Case 6 " << file_content << endl;
            break;
        default:
            file_content = file_content_line + "</br>" + "\n";
            //cout << "Case default " << file_content << endl;
    }

    return file_content;
}