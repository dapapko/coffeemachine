#include <string>
#include <iostream>
using namespace std;


class CoffeeMachine {

    int pressure; // pressure of pump
    int temperature; // temperature (used for "warming" method)
    string colour; // colour of an instance
    int numberOfCups; // number of cups (usually 1 or 2)
    bool canMakeCappuccino; // an instance can make cappuccino or not
    int price; // price of a machine
    string model; // Model of a machine (ex.: Vitek VT-1525)

    // Warming the machine
    void warm(int temp) {
        while(temperature < temp) {
            temperature++;
            cout << "Warming. Current temperature is " << temperature << endl;
        }
    }

public:
    // Default constructor
    CoffeeMachine(int pressure=15, int temperature = 25, string colour = "black", int numberOfCups=1, bool canMakeCappuccino=false, int price=3500, string model = "Vitek VT-1525"):
            pressure(pressure), temperature(temperature),
            colour(colour), numberOfCups(numberOfCups),
            canMakeCappuccino(canMakeCappuccino), price(price),
            model(model)
    {

    }

    // Copying constructor
    CoffeeMachine(const CoffeeMachine& instance):
            pressure(instance.pressure), temperature(instance.temperature),
            colour(instance.colour), numberOfCups(instance.numberOfCups),
            canMakeCappuccino(instance.canMakeCappuccino), price(instance.price),
            model(instance.model)
    {

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
    friend ostream &operator<<( ostream &output, const CoffeeMachine& machine );

};

// Friendly operator function
ostream &operator<<(ostream &output, const CoffeeMachine &machine) {
    output << "Pressure: " << machine.pressure << endl;
    output << "Temperature: " << machine.pressure << endl;
    output << "Colour: " << machine.pressure << endl;
    output << "Number of cups: " << machine.numberOfCups << endl;
    output << "Price: " << machine.price << endl;
    output << "Model: " << machine.model << endl;
    output << (machine.canMakeCappuccino ? "This instance can make cappuccino" : "This instance can't make cappuccino" ) << endl;
    return output;
}

int main() {
    // Default constructor
    CoffeeMachine instance1(20, 23, "red");
    // Copying constructor
    CoffeeMachine instance2 = instance1;
    // Visualization
    cout << instance1 << endl;
    cout << instance2 << endl;
    // Calling public method of class
    instance1.makeEspresso();
    instance2.makeEspresso(true);
}