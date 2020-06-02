#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class CoffeeMachine {

    int* numproperties; // 0 - pressure, 1 - temperature, 2 - number of cups, 3 - price
    string colour; // colour of an instance
    bool canMakeCappuccino; // an instance can make cappuccino or not
    string model; // Model of a machine (ex.: Vitek VT-1525)
    fstream file;

    // Warming the machine
    void warm(int temp) {
        while (numproperties[1] < temp) {
            numproperties[1]++;
            cout << "Warming. Current temperature is " << numproperties[1] << endl;
        }
    }

public:
    // Default constructor
    CoffeeMachine(string filename = "coffee.txt")
    {
        numproperties = new int[4];
        file.open(filename);
        if (file.is_open()) {
            file >> colour;
            file >> model;
            file >> numproperties[0];
            file >> numproperties[1];
            file >> numproperties[2];
            file >> numproperties[3];
            file >> canMakeCappuccino;
        }
        else {
            colour = "black";
            model = "Vitek VT-1525";
            canMakeCappuccino = true;
            numproperties[0] = 15;
            numproperties[1] = 25;
            numproperties[2] = 1;
            numproperties[3] = 3500;
        }
    }

    // Destructor
    ~CoffeeMachine() {
        // Release allocated dynamic memory
        delete[] numproperties;
    }

    // Copying constructor
    CoffeeMachine(const CoffeeMachine& instance) :
        colour(instance.colour), model(instance.model),
        canMakeCappuccino(instance.canMakeCappuccino)
    {
        numproperties = new int[4];
        numproperties[0] = instance.numproperties[0];
        numproperties[1] = instance.numproperties[1];
        numproperties[2] = instance.numproperties[2];
        numproperties[3] = instance.numproperties[3];
    }

    // Make a cup of coffee
    void makeEspresso(bool hot = false) {
        cout << "Process of making coffee started" << endl;
        warm(hot ? 120 : 100);
        // It's just a notification to show how to use fields of class
        if (!canMakeCappuccino) cout << "Attention. This instance can't make cappuccino" << endl;
        cout << "Activating pump" << endl;
        cout << "Deactivating pump" << endl;
        cout << "Your drink is ready" << endl;
    }
    // Definition of a friendly operator function.
    friend ostream& operator<<(ostream& output, const CoffeeMachine& machine);

};

// Friendly operator function
ostream& operator<<(ostream& output, const CoffeeMachine& machine) {
    output << "Pressure: " << machine.numproperties[0] << endl;
    output << "Temperature: " << machine.numproperties[1] << endl;
    output << "Colour: " << machine.colour << endl;
    output << "Number of cups: " << machine.numproperties[2] << endl;
    output << "Price: " << machine.numproperties[3] << endl;
    output << "Model: " << machine.model << endl;
    output << (machine.canMakeCappuccino ? "This instance can make cappuccino" : "This instance can't make cappuccino") << endl;
    return output;
}

int main() {
    // Default constructor
    CoffeeMachine instance1;
    // Copying constructor
    CoffeeMachine instance2 = instance1;
    // Visualization
    cout << instance1 << endl;
    cout << instance2 << endl;
    // Calling public method of class
    instance1.makeEspresso();
    instance2.makeEspresso(true);
    return 0;
}