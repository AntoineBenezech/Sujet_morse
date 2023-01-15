#include <iostream>
#include <vector>
#include <map>
#include "transcription.cpp"
#include "audio.cpp"
#include "decoder_audio.cpp"


int main(int argc ,char **argv){
    std::string input;
    std::cout<<"Coder morse 1"<<std::endl;
    std::cout<<"Décoder morse 2"<<std::endl;
    std::getline(std::cin, input);
    int x = std::stoi(input);
    if (x == 1){
        std::string message;
        std::cout<<"Taper le message à coder"<<std::endl;
        getline(std::cin, message);

        audio(to_morse(message));
    }
    else{
        std::cout<<from_morse(decoder_audio())<<std::endl;        
    }
    return 0;
}

 