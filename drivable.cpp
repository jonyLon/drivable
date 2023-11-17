#include <iostream>
#include <conio.h>
using namespace std;

__interface IDrivable {
	void start();
	void stop();
	void up();
	void down();
    void print() const;
};

class Car : public IDrivable {
    string brand;
    const double maxSpeed;
	double speed;
	bool flag;
public:
    Car(const string& brand, const double& maxSpeed, const double& speed) : brand{ brand }, maxSpeed{ maxSpeed }, speed{speed} {

    }

    void start() {
        cout << "Start " << endl;
        flag = true;
    }
    void stop() {
        cout << "Stop " << endl;
        speed = 0;
        flag = false;
    }
    void up() {
        if (flag && speed < maxSpeed) {
            speed+=5;
        }
        cout << speed << endl;
    }
    void down() {
        if (flag && speed > 0) {
            speed-=5;
        }
        cout << speed << endl;
    }
    void print() const {
        cout << "-----------------Car-------------------" << endl;
        cout << "Brand: " << brand << "\tMax speed: " << maxSpeed << endl;
    }

};

class Horse : public IDrivable {
    string breed;
    const double maxSpeed;
    double speed;
    bool flag;
public:
    Horse(const string& breed, const double& maxSpeed, const double& speed) : breed{ breed }, maxSpeed{ maxSpeed }, speed{ speed } {

    }

    void start() {
        cout << "Start " << endl;
        flag = true;
    }
    void stop() {
        cout << "Stop " << endl;
        speed = 0;
        flag = false;
    }
    void up() {
        if (flag && speed < maxSpeed) {
            speed++;
        }

        cout << speed << endl;
    }
    void down() {
        if (flag && speed > 0) {
            speed--;
        }
        cout << speed << endl;
    }
    void print() const {
        cout << "-----------------Hourse-------------------" << endl;
        cout << "Breed: " << breed << "\tMax speed: " << maxSpeed << endl;
    }
};

class Driver {
    string name;
    IDrivable* vehicle;
public:
    Driver(string name, IDrivable* vehicle) :name{ name }, vehicle{vehicle} {}
    void setVehicle(IDrivable* vehicle) {
        this->vehicle = vehicle;
    }
    void testDrive() const {
        vehicle->print();
        char s;
        while (true)
        {
            s = _getch();
            if (s == 27) break;
            switch (s)
            {
            case 72:
                vehicle->start();
                break;
            case 80:
                vehicle->stop();
                break;
            case 43:
                vehicle->up();
                break;
            case 45:
                vehicle->down();
                //up:72, down 80, + 43, - 45
            }
        }
    };
};

int main()
{
    Car car("Ford", 200, 80);
    Horse hourse("Thoroughbred", 72, 30);
    Driver jo("Jo", &car);
    jo.testDrive();
    jo.setVehicle(&hourse);
    jo.testDrive();
}

