#include "./../Includes.h"

string modifyHtmlString(string file_content_line);
string modifyHtmlHeadings(string file_content_line);
//Reader
void reader(){

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
            string file_content_blockquote = "";
            
            while(getline(file, read)){
                if(read[0] == '>'){
                    
                    for(size_t i = 0; i < read.size(); i++){
                      file_content_blockquote.push_back(read[i]);
                    }
                    /* string curr = "</br>";
                    for(int i = 0; i < curr.size(); i++){
                        file_content_blockquote.insert(file_content_blockquote.end(), curr[i]);
                    } */
                    cout << "File content blockquote: " << file_content_blockquote << endl;
                    if(file.peek() == 62){ //ASCII VALUE FOR '>'
                        cout << "File Peek: " << file.peek() << endl;
                        continue;
                    }
                    
                }
                cout << read << endl;
                if(file_content_blockquote != ""){
                    
                    file_content_blockquote = modifyHtmlString(file_content_blockquote);
                    cout << read << endl;
                    file_content = file_content_blockquote;
                }else {
                    file_content = modifyHtmlString(read); 
                }
                //cout << file_content << endl;
                newFile << file_content;
            }
            newFile.close();
        }

        newFile.open("output.html", ios::in);

        if (newFile.is_open()){
            string outputter;
            while (getline(newFile, outputter)) {
                if(outputter[0] == '#' ){
                    //cout << "<h1>" << outputter << "</h1>" << "\n";
                }
                //cout << outputter << "\n";
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
    string file_content = file_content_line;
    //char c = file_content_line[0];
    if(file_content.size() == 0){
        file_content = "</br> \n";
        return file_content;
    }
    for(size_t i = 0; i < file_content_line.size()-1; i++){
        if(file_content_line[i] == '#'){
            file_content = modifyHtmlHeadings(file_content_line);
        }
        if(file_content_line[i] == '_'){
            
            for(size_t j = i+1; j < file_content_line.size(); j++){
                if(file_content_line[j] == '_'){
                    file_content_line.erase(j, 1);
                    file_content_line.erase(i, 1);
                    file_content_line.insert(j-1, "</i>");
                    file_content_line.insert(i, "<i>");
                    
                    file_content = file_content_line;
                }
            }
        }

        if(file_content_line[i] == '*' && file_content_line[i+1] == '*'){
            
            for(size_t j = i+2; j < file_content_line.size()-1; j++){
                if(file_content_line[j] == '*' && file_content_line[j+1] == '*'){
                    //cout << i << " | j:" << j << endl;
                    file_content_line.erase(j, 2);
                    file_content_line.erase(i, 2);
                    file_content_line.insert(j-2, "</strong>");
                    file_content_line.insert(i, "<strong>");
                    
                    file_content = file_content_line;
                    //cout << "File Content: " << file_content << endl << endl;
                }
            }
        }

        if(file_content_line[0] == '>'){
            
            for(size_t j = 0; j < file_content_line.size(); j++){
                if(file_content_line[j] == '>' ){
                    file_content_line.erase(j, 1);
                    cout << "file_content_line: " << file_content_line << endl;
                    //j = j - 1 + 6;
                    
                }else if(file_content_line[j] == ' ' && file_content_line[j-1] == ' '){
                    size_t counter = j-1;
                    file_content_line.erase(j-1, 2);
                    string curr = "</br> \n";
                    for(int k = 0; k < curr.size(); k++){
                        file_content_line.insert((file_content_line.begin() + counter), curr[k]);
                        counter++;
                    }
                    std::cout << file_content_line.size() << endl;
                    j = j + curr.size()-2;
                    std::cout << j << endl;
                    //file_content = file_content + "\n";
                } 
                if(file_content_line.size() -1 == j){
                    file_content_line.insert(j, "</blockquote> \n");
                    file_content_line.insert(0, "<blockquote>");
                    file_content = file_content_line;
                    break;
                }
            }
        }
    }
    
    if(file_content[file_content.size()-2] == ' ' && file_content[file_content.size()-1] == ' '){
        file_content.erase(file_content.size()-2, 2);
        string curr = "</br>";
        for(int i = 0; i < curr.size(); i++){
            file_content.insert(file_content.end(), curr[i]);
        }
        file_content = file_content + "\n";
    }
    
    return file_content;
}

string modifyHtmlHeadings(string file_content_line) {

    int counter = 0;
    string file_content = "";
        
    while(file_content_line[counter] == '#'){
        counter++;
    }
    //add +1 for <h> tag
    // remove '#' from current line
    file_content_line.erase(0, counter);
    file_content = "<h" + to_string(counter) + ">" + file_content_line + "</h" + to_string(counter) + ">" + "</br>  ";
    return file_content;
}