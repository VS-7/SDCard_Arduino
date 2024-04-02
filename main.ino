#include <SDCard.h>

const int pinoSS = 53; // Pin 53 para Mega / Pin 10 para UNO
SDCard sdCard(pinoSS);

void setup() {
    Serial.begin(9600);
    pinMode(pinoSS, OUTPUT);

    if (!sdCard.initialize()) {
        Serial.println("Falha na inicialização do SD Card.");
        return;
    }

    Serial.println("SD Card pronto para uso.");

    if (sdCard.openFile("vitor.csv", FILE_WRITE)) {
        Serial.println("Escrevendo no Arquivo .csv");
        sdCard.writeFile("Vitor Passou aqui Misa, deu bom a parada");
        sdCard.closeFile();
        Serial.println("Terminado.");
        Serial.println(" ");
    } else {
        Serial.println("Erro ao Abrir Arquivo .csv");
    }

    if (sdCard.openFile("vitor.csv", FILE_READ)) {
        sdCard.readFile();
    } else {
        Serial.println("Erro ao Abrir Arquivo .csv");
    }
}

void loop() {
    // Como a função é executada somente uma vez, esta área permanece em branco
}
