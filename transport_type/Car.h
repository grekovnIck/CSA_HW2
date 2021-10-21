#ifndef ABC_HW2_GREKOV_NICKOLAY_CAR_H
#define ABC_HW2_GREKOV_NICKOLAY_CAR_H

#include <fstream>
#include "../rand.h"
#include "Transport.h"

// Класс Car - описывает объект автомобиля
class Car: public Transport {
public:
    // Ввод параметров автомобилей из файла
    void In(FILE *input_file);
    // Случайный ввод параметров автомобилей
    void RndIn();
    // Вывод параметров автомобилей в файл
    void Out(FILE* file);
    // Вычисление максимального расстояния
    int GetMaxDistance();
    // Вывод параметров автомобилей в файл
    // (Для создания тестовых данных)
    void Parameters(FILE* input_file);

private:
    const static int min_value = 1;
    const static int max_value = 1000;
    // Максимальная скорость автомобиля
    int max_speed;
};

#endif //ABC_HW2_GREKOV_NICKOLAY_CAR_H
