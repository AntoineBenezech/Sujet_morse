#include <iostream>
#include <fstream>
#include <string>

const int SAMPLE_RATE = 44100; // taux d'échantillonnage de l'audio en Hz
const int DOT_LENGTH = 1; // durée d'un point en secondes
const int DASH_LENGTH = 3; // durée d'un trait en secondes
const int PAUSE_LENGTH = 1; // durée d'une pause entre les lettres en secondes
const int CHAR_PAUSE_LENGTH = 3; // durée d'une pause entre les mots en secondes

void audio(std::string morse_text)
{
    std::cout<<"Nom du fichier crée"<<std::endl;   
    std::string nom;
    getline(std::cin, nom);
    std::ofstream output(nom, std::ios::binary);
    output.write("RIFF", 4);
    int filesize = 36 + (morse_text.length() * (SAMPLE_RATE * (DOT_LENGTH + PAUSE_LENGTH)));
    output.write((char*) &filesize, 4);
    output.write("WAVEfmt ", 8);
    int subchunk1size = 16;
    output.write((char*) &subchunk1size, 4);
    short int audioformat = 1;
    output.write((char*) &audioformat, 2);
    short int numchannels = 1;
    output.write((char*) &numchannels, 2);
    int samplerate = SAMPLE_RATE;
    output.write((char*) &samplerate, 4);
    int byterate = SAMPLE_RATE * numchannels * sizeof(short int);
    output.write((char*) &byterate, 4);
    short int blockalign = numchannels * sizeof(short int);
    output.write((char*) &blockalign, 2);
    short int bitspersample = 8 * sizeof(short int);
    output.write((char*) &bitspersample, 2);
    output.write("data", 4);
    int subchunk2size = filesize - 36;
    output.write((char*) &subchunk2size, 4);
    for (int i = 0; i < morse_text.length(); i++)
    {
        if (morse_text[i] == ' ')
        {
            for (int j = 0; j < CHAR_PAUSE_LENGTH * SAMPLE_RATE; j++)
            {
                short int sample = 0;
                output.write((char*) &sample, sizeof(short int));
            }
        }
        else
        {
            if (morse_text[i] == '.')
            {
                for (int k = 0; k < DOT_LENGTH * SAMPLE_RATE; k++)
                {
                    short int sample = 32767;
                    output.write((char*) &sample,sizeof(short int));        
                }
            }
            else if (morse_text[i] == '-')
            {
                for (int k = 0; k < DASH_LENGTH * SAMPLE_RATE; k++)
{
short int sample = 32767;
output.write((char*) &sample, sizeof(short int));
}
            }
            if (i < morse_text.length() - 1 && morse_text[i + 1] != ' ')
            {
                for (int j = 0; j < PAUSE_LENGTH * SAMPLE_RATE; j++)
                {
                    short int sample = 0;
                    output.write((char*) &sample, sizeof(short int));
                }
            }
        }
    }
    output.close();
    std::cout << "Fichier audio WAV créé :"<<nom << std::endl;
}

