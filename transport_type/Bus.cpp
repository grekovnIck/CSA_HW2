#include "Bus.h"

// Ввод параметров автобуса из файла
void Bus::In(FILE *input_file) {
    int fuel_consumption, tank_capacity, max_passenger, check;
    check = fscanf(input_file, "%d %d %d\n", &fuel_consumption, &tank_capacity, &max_passenger);
    if(check != 3) {
        throw "Incorrect input data!";
    }
    this->fuel_consumption = fuel_consumption;
    this->tank_capacity = tank_capacity;
    this->max_passenger = max_passenger;
}

// Случайный ввод параметров грузовика
void Bus::RndIn() {
    fuel_consumption = GetRandomInt(min_value, max_value);
    max_passenger = GetRandomInt(min_value, max_value);
    tank_capacity = GetRandomInt(min_value, max_value);
}

// Вывод параметров грузовика в файл
void Bus::Out(FILE* file) {
    fprintf(file, "Bus; Max passenger  - %d; Fuel consumption per 100km - %d; Fuel tank capacity - %d; Max distance - %d.\n",
            max_passenger, fuel_consumption, tank_capacity, GetMaxDistance());
}

// Вычисление максимального расстояния грузовика
int Bus::GetMaxDistance() {
    return tank_capacity / fuel_consumption;
}

// Вывод в файл параметров грузовика для тестирования данных
void Bus::Parameters(FILE* file) {
    fprintf(file, "%d\n%d %d %d\n",1 , max_passenger, fuel_consumption, tank_capacity);
    /*char* data = new char[127];
    sprintf(data, "%d\n%d %d %d\n", 1, fuel_consumption, tank_capacity, max_passenger);
    return data;*/
}

