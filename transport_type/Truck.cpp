#include "Truck.h"

// Ввод параметров грузовика из файла
void Truck::In(FILE *input_file) {
    int fuel_consumption, tank_capacity, truck_lifting, check;
    check = fscanf(input_file, "%d %d %d", &fuel_consumption, &tank_capacity, &truck_lifting);
    if(check != 3) {
        throw "Incorrect input data!";
    }
    this->fuel_consumption = fuel_consumption;
    this->tank_capacity = tank_capacity;
    this->truck_lifting = truck_lifting;
}

// Случайный ввод параметров грузовика
void Truck::RndIn() {
    fuel_consumption =  GetRandomInt(min_value, max_value);
    truck_lifting = GetRandomInt(min_value, max_value);
    tank_capacity = GetRandomInt(min_value, max_value);
}

// Вывод параметров грузовика в файл
void Truck::Out(FILE *file) {
    fprintf(file, "Truck; Max truck lifting - %d; Fuel consumption per 100km - %d; Fuel tank capacity - %d; Max distance - %d.\n",
            truck_lifting, fuel_consumption, tank_capacity, GetMaxDistance());
}

// Вычисление максимального расстояния грузовика
int Truck::GetMaxDistance() {
    return tank_capacity / fuel_consumption;
}

// Вывод в файл параметров грузовика для тестирования данных
void Truck::Parameters(FILE* file) {
    fprintf(file, "%d\n%d %d %d\n",2, truck_lifting, fuel_consumption, tank_capacity);
}


