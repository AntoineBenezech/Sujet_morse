#include <iostream>
#include <sndfile.h>



std::string decoder_audio()
{
    std::string file_name;
    std::cout << "Entrez le nom du fichier audio WAV en morse : ";
    std::cin >> file_name;
    SF_INFO file_info;
    SNDFILE *file = sf_open(file_name.c_str(), SFM_READ, &file_info);
    if (file == NULL)
    {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        
    }
    if (file_info.samplerate != SAMPLE_RATE)
    {
        std::cout << "Le taux d'échantillonnage du fichier n'est pas celui attendu" << std::endl;
        
    }
    int sample_count = file_info.frames;
    short *samples = new short[sample_count];
    sf_read_short(file, samples, sample_count);
    sf_close(file);
    std::string morse_text;
    for (int i = 1; i < sample_count; i++)
    {
        if (samples[i] > 0)
        {
            int j = i + 1;
            while (j < sample_count && samples[j] > 0)
            {
                j++;
            }
            int duration = j - i;
            if (duration <= DOT_LENGTH * SAMPLE_RATE)
            {
                morse_text += ".";
            }
            else
            {
                morse_text += "-";
            }
            i = j;
        }
        else
        {
            int j = i + 1;
            while (j < sample_count && samples[j] <= 0)
            {
                j++;
            }
            int duration = j - i;
            if (duration >= CHAR_PAUSE_LENGTH * SAMPLE_RATE)
            {
                morse_text += " ";
            }
            i = j;
        }
    }
    return morse_text;
}
