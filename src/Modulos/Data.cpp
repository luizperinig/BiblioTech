#include "Data.hpp"

/**
 * @brief Recebe a data atual do sistema e armazena os valores.
 */
void Data::Data_Atual(){
    time_t dataatual = time(nullptr);
    tm* DataAtual = localtime(&dataatual);

    this->dia = DataAtual->tm_mday;
    this->mes = DataAtual->tm_mon + 1;
    this->ano = DataAtual->tm_year + 1900;
    this->hora = DataAtual->tm_hour;
}


/**
 * @brief Adiciona uma quantidade desejada de dias à data armazenada.
 * @param Dias A quantidade de dias a serem adicionados.
 */
void Data::Adicionar_Dias(int Dias){
    tm tmData = {0};
    tmData.tm_year = this->ano - 1900;
    tmData.tm_mon = this->mes - 1;
    tmData.tm_mday = this->dia;
    tmData.tm_hour = this->hora;

    time_t DataAtual = mktime(&tmData);
    DataAtual += Dias * 24*60*60;

    tm* tmDataNova = localtime(&DataAtual);
    this->hora = 18;
    this->dia = tmDataNova->tm_mday;
    this->mes = tmDataNova->tm_mon + 1;
    this->ano = tmDataNova->tm_year + 1900;
}


/**
 * @brief Avança um dia na data armazenada.
 */
void Data::Passar_Dia(){
    tm tmData = {0};
    tmData.tm_year = this->ano - 1900;
    tmData.tm_mon = this->mes - 1;
    tmData.tm_mday = this->dia;
    tmData.tm_hour = this->hora;

    time_t DataAtual = mktime(&tmData);
    DataAtual += 1 * 24*60*60;

    tm* tmDataNova = localtime(&DataAtual);
    this->hora = tmDataNova->tm_hour;
    this->dia = tmDataNova->tm_mday;
    this->mes = tmDataNova->tm_mon + 1;
    this->ano = tmDataNova->tm_year + 1900;
}


/**
 * @brief Avança uma hora na data armazenada.
 * 
 * @return True se a hora atual for igual a 18, False caso contrário.
 */
bool Data::Passar_Hora(){
    tm tmData = {0};
    tmData.tm_year = this->ano - 1900;
    tmData.tm_mon = this->mes - 1;
    tmData.tm_mday = this->dia;
    tmData.tm_hour = this->hora;

    time_t DataAtual = mktime(&tmData);
    DataAtual += 60*60;

    tm* tmDataNova = localtime(&DataAtual);
    this->hora = tmDataNova->tm_hour;
    this->dia = tmDataNova->tm_mday;
    this->mes = tmDataNova->tm_mon + 1;
    this->ano = tmDataNova->tm_year + 1900;

    if(this->hora == 18)
        return true;
    return false;
}


void Data::Imprimir_Data(){
    cout << dia << "/" << mes << "/" << ano << " " << hora << " horas" << endl;
}