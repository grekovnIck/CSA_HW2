#include "Car.h"

// Ввод параметров грузовика из файла
void Car::In(FILE *input_file) {
    int fuel_consumption, tank_capacity, max_speed, check;
    check = fscanf(input_file, "%d %d %d", &fuel_consumption, &tank_capacity, &max_speed);
    if(check != 3) {
        throw "Incorrect input data!";
    }
    this->fuel_consumption = fuel_consumption;
    this->tank_capacity = tank_capacity;
    this->max_speed = max_speed;
}

// Случайный ввод параметров грузовика
void Car::RndIn() {
    fuel_consumption = GetRandomInt(min_value, max_value);
    max_speed = GetRandomInt(min_value, max_value);
    tank_capacity = GetRandomInt(min_value, max_value);
}

// Вывод параметров грузовика в файл
void Car::Out(FILE* file) {
    fprintf(file, "Car; Max speed - %d; Fuel consumption per 100km - %d; Fuel tank capacity - %d; Max distance - %d.\n",
            max_speed, fuel_consumption, tank_capacity, GetMaxDistance());
}

// Вычисление максимального расстояния грузовика
int Car::GetMaxDistance() {
    return tank_capacity / fuel_consumption;
}

// Вывод в файл параметров грузовика для тестирования данных
void Car::Parameters(FILE* file) {
    fprintf(file, "%d\n%d %d %d\n",0 , max_speed, fuel_consumption, tank_capacity);
    /*char* data = new char[127];
    sprintf(data, "%d\n%d %d %d\n", 0, fuel_consumption, tank_capacity, max_speed);
    return data;*/
}
