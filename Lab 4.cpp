#include <iostream>
#include <string>
using namespace std;

class conferension {
private:
    int participants;

public:
    string name;
    string place;
    float price;
    conferension() {
    }

    conferension(string naming, string placing, float pricing, int number) {
        participants = number;
        name = naming ;
        place = placing;
        price = pricing;
    }

    string getPlace() {
        return place;
    }
    float getPrice() {
        return price;
    }
    string getName() {
        return name;
    }
    void setPlace(string a) {
        this->place = a;
    }
    void setNumber(int a) {
        this->participants = a;
    }
    void setPrice(float a) {
        this->price = a;
    }
    void setName(string a) {
        this->name = a;
    }
    int getParticipants()
    {
        return participants;

    }
};


int main() {
    string naming, placing;
    float pricing;
    int number;
    cout << "name : ";
    cin >> naming;
    cout << "\nplace : ";
    cin >> placing;
    cout << "\nprice : ";
    cin >> pricing;
    cout << "\nnumber : \n";
    cin >> number;
    conferension Expo(naming, placing, pricing, number);
    cout <<Expo.getName() << (" is a name of conferension\n");
    cout <<Expo.getPlace() << (" is a place\n");
    cout << Expo.getPrice() << (" $ price\n");
    cout << Expo.price << (" people\n");
    return 0;
}
