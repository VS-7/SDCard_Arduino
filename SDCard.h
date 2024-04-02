#ifndef SDCARD_H
#define SDCARD_H

#include <SD.h>
#include <SPI.h>

class SDCard {
private:
    int _pinSS;
    File _file;

public:
    SDCard(int pinSS);
    bool initialize();
    bool openFile(const char* filename, uint8_t mode);
    void closeFile();
    bool writeFile(const char* data);
    void readFile();
};

#endif
