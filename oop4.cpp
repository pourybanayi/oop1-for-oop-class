//مدل ساده
#include <iostream>
#include <string>
using namespace std;

// کلاس والد Car
// کلاس والد Car
class Car {
private:
    bool fuelPump;
    bool electricalSystem;

public:
    Car() {
        fuelPump = false;
        electricalSystem = false;
    }

    // تابع مجازی start
    virtual string start() {
    fuelPump = true;
    electricalSystem = true;
    string result;
    result += "Fuel pump activated.\n";
    result += "Electrical system activated.\n";
    return result;
}
};


// کلاس فرزند Pride
class Pride : public Car {
public:
string start() override {
    string result = Car::start();
    result += "Radio turned on.\n";
    result += "Odometer activated.\n";
    return result;
}

};

// کلاس فرزند BMW
class BMW : public Car {
public:
    string start() override {
    string result = Car::start();
    result += "GPS turned on.\n";
    result += "Headlights turned on.\n";
    result += "Mirrors unfolded.\n";
    return result;
}

};

// تابع اصلی main
int main() {
    Car* car1 = new Pride();
    Car* car2 = new BMW();

    cout << "pride:\n" << car1->start() << endl;
    cout << " bmw:\n" << car2->start() << endl;

    delete car1;
    delete car2;

    return 0;
}
//مدل خفن تابعی
#include <iostream>
#include <string>
using namespace std;

// والد
class Car {
private:
    bool fuelPump;
    bool electricalSystem;

public:
    Car() {
        fuelPump = false;
        electricalSystem = false;
    }

    virtual string start() {
        fuelPump = true;
        electricalSystem = true;
        string result;
        result += "Fuel pump activated.\n";
        result += "Electrical system activated.\n";
        return result;
    }
};

// فرزند: پراید
class Pride : public Car {
private:
    string turnOnRadio() {
        return "Radio turned on.\n";
    }

    string activateOdometer() {
        return "Odometer activated.\n";
    }

public:
    string start() override {
        string result = Car::start();
        result += turnOnRadio();
        result += activateOdometer();
        return result;
    }
};

// فرزند: بی‌ام‌و
class BMW : public Car {
private:
    string turnOnGPS() {
        return "GPS turned on.\n";
    }

    string turnOnHeadlights() {
        return "Headlights turned on.\n";
    }

    string unfoldMirrors() {
        return "Mirrors unfolded.\n";
    }

public:
    string start() override {
        string result = Car::start();
        result += turnOnGPS();
        result += turnOnHeadlights();
        result += unfoldMirrors();
        return result;
    }
};

// تابع main
int main() {
    Car* car1 = new Pride();
    Car* car2 = new BMW();

    cout << "🚗 Pride:\n" << car1->start() << endl;
    cout << "🚘 BMW:\n" << car2->start() << endl;

    delete car1;
    delete car2;

    return 0;
}
