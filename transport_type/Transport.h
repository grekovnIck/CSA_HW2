#ifndef ABC_HW2_GREKOV_NICKOLAY_TRANSPORT_H
#define ABC_HW2_GREKOV_NICKOLAY_TRANSPORT_H

#include <fstream>

class Transport {
public:
    // Ввод обобщенного транспорта из файла
    static Transport* StaticInput(FILE* input);
    // Ввод транспорта из файла
    virtual void In(FILE* input) = 0 ;
    // Ввод случайного транспорта
    static Transport* StaticRandom();
    // Ввод случайного транспорта
    virtual void RndIn() = 0;
    // Вывод транспорта в файл
    virtual void Out(FILE *file) = 0;
    // Вывод транспорта в файл (для тестовых данных)
    virtual void Parameters(FILE* input) = 0;
    // Вычисление расстояние обобщенного транспорта
    virtual int GetMaxDistance() = 0;

    // Общие поля всех ТС
    // Емкость бака
    int tank_capacity;
    // Расход топлива на 100 км
    int fuel_consumption;
};
#endif //ABC_HW2_GREKOV_NICKOLAY_TRANSPORT_H