#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Employee {
public:
    string id;
    string name;
    string surname;
    string departmentID;
    string position;

};
class HRMS {
public:
    void main() {
        wypelnienie();
        add({ "11","Jozef","Mlynarski","1562","Finance" }, "1562", 6843);
        printDepartment("1560");
        changeSalary("4", 5544.0);
        printSalaries();
        printSalariesSorted();
    }
private:
    vector <Employee> Pracownicy;
    map <string, string> Mapowanie;
    map <string, double> Salaries;
    void add(Employee employee, string departmentID, double salary) {
        for (vector<Employee>::iterator it = Pracownicy.begin(); it != Pracownicy.end(); ++it) {
            if (it->id.compare(employee.id) == 0) {
                cout << "Podane ID: " << it->id << " jest juz w sytemie, nie mozna utworzyc dwoch pracownikow z takim samym ID" << endl;
                int pom = std::stoi(Pracownicy.rbegin()->id);
                cout << "Ostatnie zajete ID: " << Pracownicy.rbegin()->id << endl << "Pierwsze wolne ID: " << ++pom << endl;
            }
        }
        Pracownicy.push_back(employee);
        Mapowanie[employee.id] = departmentID;
        Salaries[employee.id] = salary;
        Pracownicy.rbegin()->departmentID = departmentID;

    }
    void printDepartment(std::string departmentID) {
        cout << "Lista pracownikow departamentu " << departmentID << endl;

        for (map<string, string>::iterator it = Mapowanie.begin(); it != Mapowanie.end(); ++it) {
            if (it->second == departmentID) {
                int pom = std::stoi(it->first);
                pom--;
                cout << "ID Employee: " << Pracownicy[pom].id << "\t";
                cout << "Name and surname: " << Pracownicy[pom].name << " " << Pracownicy[pom].surname << "\t";
                cout << "Position: " << Pracownicy[pom].position << "\t";
                cout << "Departament: " << Pracownicy[pom].departmentID << endl;
            }

        }

    }
    void changeSalary(string employeeId, double salary) {
        bool czyistnieje = false;
        for (map<string, double>::iterator it = Salaries.begin(); it != Salaries.end(); ++it) {
            if (it->first == employeeId) {
                it->second = salary;
                czyistnieje = true;
            }
        }if (!czyistnieje) {
            cout << "Pracownik o podanym ID nie istnieje nie mozna zmienic mu pensji.";
        }

    }
    void printSalaries() {
        for (map<string, double>::iterator it = Salaries.begin(); it != Salaries.end(); ++it) {
            int pom = std::stoi(it->first);
            pom--;
            cout << "METODAPRINTSALARIES:" << "\n";
            cout << "ID Employee: " << Pracownicy[pom].id << "\t";
            cout << "Name and surname: " << Pracownicy[pom].name << " " << Pracownicy[pom].surname << "\t";
            cout << "Position: " << Pracownicy[pom].position << "\t";
            cout << "Departament: " << Pracownicy[pom].departmentID << "\t";
            cout << "Salary: " << it->second << endl;

        }
    }
    void printSalariesSorted() {
        // zamiana kontenera map na wektor wektorow
        typedef std::pair<std::string, double> pair;
        std::vector<pair> vec;
        std::copy(Salaries.begin(), Salaries.end(), std::back_inserter<std::vector<pair>>(vec));
        std::sort(vec.begin(), vec.end(),
                  [](const pair& l, const pair& r) {
                      if (l.second != r.second)
                          return l.second > r.second;
                      return l.first > r.first;
                  });

        cout << "METODA PRINTSALARIES SORTED:" << endl;
        for (auto const& pair : vec) {
            int pom = std::stoi(pair.first);
            pom--;
            cout << "ID Employee: " << Pracownicy[pom].id << "\t";
            cout << "Name and surname: " << Pracownicy[pom].name << " " << Pracownicy[pom].surname << "\t";
            cout << "Position: " << Pracownicy[pom].position << "\t";
            cout << "Departament: " << Pracownicy[pom].departmentID << "\t";
            cout << "Salary: " << pair.second << endl;



        }
    }

    void wypelnienie() {
        string Names[10] = { "Mateusz", "Damian", "Waldemar", "Krzysztof", "Wladyslaw", "Adam", "Karol", "Mariusz","Bartlomiej", "Andrzej" };
        string Surnames[10] = { "Nowak", "Kowal", "Dudek", "Grzywa", "Kowalski", "Malysz", "Lipa", "Brzoza", "Kot", "Lis" };
        string Positions[5] = { "Operator", "Finance", "HR", "IT", "Security" };
        double salary[10] = { 4099.5, 6847.4, 3333.4, 2600, 3800.66, 4851, 4565, 4112, 7231.5, 3500 };
        Employee A, B, C, D, E, F, G, I, J, K;
        Employee TAB[10] = { A, B, C, D, E, F, G, I, J, K };
        for (int i = 0; i < 10; i++) {
            int b = i + 1;
            TAB[i].id = std::to_string(b);
            TAB[i].name = Names[i];
            TAB[i].surname = Surnames[i];
            TAB[i].position = Positions[i % 5];
            add(TAB[i], "156" + std::to_string(i % 3), salary[i]);
        }
    }

};
int main() {

    HRMS Zadanie;
    Zadanie.main();
    getchar();
    return 0;
}
