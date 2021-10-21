#ifndef ABC_HW2_GREKOV_NICKOLAY_RAND_H
#define ABC_HW2_GREKOV_NICKOLAY_RAND_H

#include <cstdlib>
#include "transport_type/Car.h"
#include "transport_type/Bus.h"
#include "transport_type/Truck.h"

// Генерирует случайное число
static int GetRandomInt(int min_value, int max_value) {
    return min_value + rand() % (max_value+1);
}
#endif //ABC_HW2_GREKOV_NICKOLAY_RAND_H
