#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "factory.hpp"

using namespace std;


void TwoWheeler::printVehicleInfo()
{
    cout << "I am two wheeler" << endl;
}

void ThreeWheeler::printVehicleInfo()
{
    cout << "I am three wheeler" << endl;
}

void FourWheeler::printVehicleInfo()
{
    cout << "I am four wheeler" << endl;
}

Vehicle* ConcreteVehicleFactory::createVehicle(int type)
{
        if (type == 1)
            return new TwoWheeler();
        else if (type == 2)
            return new ThreeWheeler();
        else if (type == 3)
            return new FourWheeler();
        else
            return NULL;
}

// Client code
int main() {
    ConcreteVehicleFactory* factory = new ConcreteVehicleFactory();
    Vehicle* vehicle1 = factory->createVehicle(1);
    vehicle1->printVehicleInfo();
    Vehicle* vehicle2 = factory->createVehicle(2);
    vehicle2->printVehicleInfo();
    Vehicle* vehicle3 = factory->createVehicle(3);
    vehicle3->printVehicleInfo();
    delete vehicle1;
    delete vehicle2;
    delete vehicle3;
    delete factory;
    return 0;
}
