#ifndef ABC_HW2_GREKOV_NICKOLAY_BUS_H
#define ABC_HW2_GREKOV_NICKOLAY_BUS_H

#include <fstream>
#include "../rand.h"
#include "Transport.h"

// Класс Bus - описывает объект автобус
class Bus: public Transport {
public:
    // Ввод параметров автобуса из файла
    void In(FILE *input_file);
    // Случайный ввод параметров автобуса
    void RndIn();
    // Вывод параметров автобуса в файл
    void Out(FILE* file);
    // Вычисление максимального расстояния
    int GetMaxDistance();
    // Вывод параметров автобуса в файл
    // (Для создания тестовых данных)
    void Parameters(FILE* input_file);

private:
    const static int min_value = 1;
    const static int max_value = 1000;
    // Максимально количество пассажиров
    int max_passenger;
};
#endif //ABC_HW2_GREKOV_NICKOLAY_BUS_H
