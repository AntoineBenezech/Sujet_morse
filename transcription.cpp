#include<iostream>
#include <map>
#include <vector>




std::map<const char,const std::string> table_morse {      
    {' ', " "},
    {'\n', "\n"},
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {'0', "-----"},
    {'.', ".-.-.-"},
    {',', "--..--"},
    {'?', "..--.."},
    {'-', "-...-"},
    {'/', "-..-."},
    {'@', ".--.-."},
    {'+', ".-.-."},
    {'=', "-..."},
    {'\'', ".----"},
    {'(', "-.--"},
    {')', "-.--."},
    {'\"', ".-..-"},
};


std::string to_morse(const std::string& message){
    std::string signal;
    

    for (char e : message){
        std::string l = table_morse[e];
        signal += l;
        signal += ' ';
    }
    signal.pop_back();
    return signal;
}


std::string from_morse(std::string signal){
    std::string message;
    std::string buffer;
    for (char e : signal){
        if (e == ' '){
            if (size(buffer)>0){
                for (auto [key, value] : table_morse){
                    if (value == buffer){
                        message = message + key;
                    }
                }
                message += ' ';
            }
            else {
                message += ' ';
            }
            
            buffer.clear();

                                    
        }
        else{
            buffer += e;
        }
    }
    
    for (auto [key, value] : table_morse){
                if (value == buffer){
                    message = message + key;
                }
    }
    return(message);
};
