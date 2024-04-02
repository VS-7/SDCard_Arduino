#include "SDCard.h"

SDCard::SDCard(int pinSS) {
    _pinSS = pinSS;
}

bool SDCard::initialize() {
    return SD.begin(_pinSS);
}

bool SDCard::openFile(const char* filename, uint8_t mode) {
    _file = SD.open(filename, mode);
    return _file;
}

void SDCard::closeFile() {
    if (_file) {
        _file.close();
    }
}

bool SDCard::writeFile(const char* data) {
    if (_file) {
        _file.println(data);
        return true;
    }
    return false;
}

void SDCard::readFile() {
    if (_file) {
        Serial.println("Conteúdo do Arquivo:"); // Imprime na tela

        while (_file.available()) { // Exibe o conteúdo do Arquivo
            Serial.write(_file.read());
        }
        _file.close(); // Fecha o Arquivo após ler
    } else {
        Serial.println("Erro ao Abrir Arquivo");
    }
}
