cmake_minimum_required(VERSION 3.20)
project(ABC_HW2_Grekov_Nickolay)

set(CMAKE_CXX_STANDARD 17)

add_executable(ABC_HW2_Grekov_Nickolay main.cpp transport_type/Car.cpp transport_type/Truck.cpp transport_type/Bus.cpp transport_type/Car.h transport_type/Bus.h transport_type/Truck.h transport_type/Transport.cpp transport_type/Transport.h rand.h container/Container.cpp container/Container.h)
