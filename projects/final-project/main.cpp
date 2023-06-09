#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Mountain {

private:
    string name;
    string country;
    double elevation;

public:
    Mountain(const string& Name, const string& Country, double Elevation){
        this->name = Name;
        this->country = Country;
        this->elevation = Elevation;
}
    string getName() const {
        return name;
}
    string getCountry() const {
        return country;
} 
    double getElevation() const {
        return elevation;
}
    void setName(const string& Name){
        this->name = Name;
}
    void setCountry(const string& Country){
        this->country = Country;
}
    void setElevation(double Elevation){
        this->elevation = Elevation;
}
    double toMeters() const {
        return elevation / 3.2808;
}
};

Mountain findMin(const vector<Mountain>& mountains) {
    Mountain smallest = mountains[0];

    for (const Mountain& mountain : mountains) {
        if (mountain.getElevation() < smallest.getElevation()) {
            smallest = mountain;
}
}
    return smallest;
}

int main() {
    vector<Mountain> title;

    title.push_back(Mountain("Chimborazo","Ecuador",20549));
    title.push_back(Mountain("Matterhorn", "Switzerland", 14692));
    title.push_back(Mountain("Olympus", "Greece (Macedonia)", 9573));
    title.push_back(Mountain("Everest", "Nepal", 29029));
    title.push_back(Mountain("Mount Marcy - Adirondacks", "United States", 5344));
    title.push_back(Mountain("Mount Mitchell - Blue Ridge", "United States", 6684));
    title.push_back(Mountain("Zugspitze", "Switzerland", 9719));

    cout << left << setw(30) << "Mountain" << setw(25) << "Country" << setw(18) << "Elevation (feet)" << "Elevation (meters)" << endl;
    cout << endl;
    
    for (const Mountain& mountain : title) {
        cout << left << setw(30) << mountain.getName() << setw(25) << mountain.getCountry() << setw(18) << mountain.getElevation() << mountain.toMeters() << endl;
}
    Mountain min = findMin(title);
    cout << endl;
    cout<< min.getName() << " is the smallest mountain in the list with a Elevation of " << min.getElevation() << " ft." << endl;

    return 0;
}