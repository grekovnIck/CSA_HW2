#ifndef ABC_HW2_GREKOV_NICKOLAY_CONTAINER_H
#define ABC_HW2_GREKOV_NICKOLAY_CONTAINER_H

#include "../transport_type/Transport.h"
#include <fstream>

// Контейнер на основе одномерного конструктора
class Container {
public:
    Container();
    ~Container();

    // Ввод содержимого контейнера в указанный файл
    void In(FILE *file);
    // Случайный ввод содержимого контейнера
    void Random(int size);
    // Вывод содержимого контейнера в указанный файл
    void Out(FILE* &file);
    // Вычисление максимального расстояния
    void GetMaxDistance();
    // Случайный вывод содержимого контейнера
    void Parameters(FILE* file);
    // Сортировка контейнера
    void Sort();
private:
    // Очистка контейнера от памяти
    void Clear();
    // Текущая длина
    int len;
    Transport* storage[10000];
};

#endif //ABC_HW2_GREKOV_NICKOLAY_CONTAINER_H
