#include "Car.h"

// Ввод параметров обобщенного транспорта из файла
Transport* Transport::StaticInput(FILE *input_file) {
    int transport_type;

    if (fscanf(input_file, "%d\n", &transport_type) != 1) {
        throw 1;//"Incorrect input!"
    }
    Transport* transport;
    switch (transport_type) {
        // Car
        case 0:
            transport = new Car;
            break;
        // Bus
        case 1:
            transport = new Bus;
            break;
        // Truck
        case 2:
            transport = new Truck;
            break;
        default:
            throw 1;
    }
    transport->In(input_file);
    return transport;
}

// Случайный ввод обобщенного транспорта
Transport* Transport::StaticRandom()  {
    int transport_type = GetRandomInt(0, 2);
    Transport *transport;
    switch (transport_type) {
        // Car
        case 0:
            transport = new Car;
            break;
            // Bus
        case 1:
            transport = new Bus;
            break;
            // Truck
        case 2:
            transport = new Truck;
            break;
    }
    transport->RndIn();
    return transport;
}

