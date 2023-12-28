#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <ctime>

using namespace std;

struct Data{
    int dia;
    int mes;
    int ano;
    int hora;

    void Data_Atual();
    void Adicionar_Dias(int Dias);

    void Passar_Dia();
    bool Passar_Hora();

    void Imprimir_Data();
};

#endif