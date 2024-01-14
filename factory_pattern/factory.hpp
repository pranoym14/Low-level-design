#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// Abstract product class
class Vehicle {
public:
    virtual void printVehicleInfo() = 0;
    virtual ~Vehicle() {}
};
class TwoWheeler : public Vehicle {
    void printVehicleInfo();
};

class ThreeWheeler : public Vehicle {
     void printVehicleInfo();
};
class FourWheeler : public Vehicle {
     void printVehicleInfo();
};

class ConcreteVehicleFactory {
public:
    static Vehicle* createVehicle(int type);
};