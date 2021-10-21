#ifndef ABC_HW2_GREKOV_NICKOLAY_TRUCK_H
#define ABC_HW2_GREKOV_NICKOLAY_TRUCK_H

#include <fstream>
#include "../rand.h"
#include "Transport.h"

// Класс Truck - описывает объект грузовик
class Truck: public Transport {
public:
    // Ввод параметров треугольника из файла
    void In(FILE *input_file);
    // Случайный ввод параметров грузовика
    void RndIn();
    // Вывод параметров грузовика в файл
    void Out(FILE *file);
    // Вычисление максимального расстояния
    int GetMaxDistance();
    // Вывод параметров грузовика в файл
    // (Для создания тестовых данных)
    void Parameters(FILE* input_file);

private:
    const static int min_value = 1;
    const static int max_value = 1000;
    // Грузоподъемность грузовика
    int truck_lifting;
};

#endif //ABC_HW2_GREKOV_NICKOLAY_TRUCK_H
