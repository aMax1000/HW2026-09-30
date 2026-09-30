#include <iostream>
#include <string>

using namespace std;

class CityUA {
private:
    string name;
    signed int population;

public:
    // Static constants
    static string language;
    static string capital;
    static string president;
    static int population_country;
    static int count;

    CityUA(string name,signed int population):
        name(name), 
        population(population){
        population_country += population;
        count++;
    }
    void Init(string name, signed int population) {
        this->setName(name);
        this->setPopulation(population);
    }

    ~CityUA() {
        population_country -= population;
        count--;
    }

    // Setters
    void setName(string name) {
        this->name = name;
    }

    void setPopulation(signed int population) {
        population_country -= this->population;
        population_country += population;
        this->population = population;
    }

    // Getters
    string getName() const {
        return name;
    }

    signed int getPopulation() const {
        return population;
    }


    void print()const {
        cout << "City: " << this->getName() << endl;
        cout << "Population: " << this->getPopulation() << endl;
    }
};

// Definition of static members
string CityUA::language = "ukrainian";
string CityUA::capital = "kiev";
string CityUA::president = "Volodimyr Zelenski";
int CityUA::population_country = 0;
int CityUA::count = 0;


// Testing
int main() {
    CityUA city1("Odesa", 1000000);
    CityUA city2("Lviv", 700000);

    // Test getters

    city1.print();
    cout << endl;

    city2.print();
    cout << endl;
    cout << "Country population: " << CityUA::population_country << endl<<endl;

    city1.setName("Kiev");
    city1.setPopulation(3000000);

    city2.Init("Chernihiv",300000);
    
    city1.print();
    cout << endl;

    city2.print();
    cout << endl;

    // Test static constants
    cout << "Language: " << CityUA::language << endl;
    cout << "Capital: " << CityUA::capital << endl;
    cout << "President: " << CityUA::president << endl;
    cout << "Country population: " << CityUA::population_country << endl;
    cout << "Count: " << CityUA::count << endl;

    return 0;
}