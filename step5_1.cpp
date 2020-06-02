#include <string>
#include <iostream>
using namespace std;


class CoffeeMachine {

    int* numproperties; // 0 - pressure, 1 - temperature, 2 - number of cups, 3 - price
    string colour; // colour of an instance
    bool canMakeCappuccino; // an instance can make cappuccino or not
    string model; // Model of a machine (ex.: Vitek VT-1525)

    // Warming the machine
    void warm(int temp) {
        while (numproperties[1] < temp) {
            numproperties[1]++;
            cout << "Warming. Current temperature is " << numproperties[1] << endl;
        }
    }

public:
    // Default constructor
    CoffeeMachine(int pressure = 15, int temperature = 25, string colour = "black", int numberOfCups = 1, bool canMakeCappuccino = false, int price = 3500, string model = "Vitek VT-1525") :
        colour(colour), model(model), canMakeCappuccino(canMakeCappuccino)
    {
        // Allocate dynamic memory
        numproperties = new int[4];
        numproperties[0] = pressure;
        numproperties[1] = temperature;
        numproperties[2] = numberOfCups;
        numproperties[3] = price;
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
    CoffeeMachine instance1 = CoffeeMachine(20, 23, "red");
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