#include <iostream>
#include <map>
#include "Mottorolla.h"

using std::map;
using std::cout;
using std::cin;
using std::string;

class RomeArabian{
private: 
    map<int, char> Rome_to_Arabian;
public:
    RomeArabian() {
        Rome_to_Arabian = { {1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'} };
    }
    void ArabianToRome() {
        int Arabian;
        string Rome;
        FC::IsAInt("Enter a arabian num: ", Arabian);
        for(map <int, char> :: const_reverse_iterator ri = Rome_to_Arabian.crbegin(); ri != Rome_to_Arabian.crend(); ri++) {
            cout << Arabian / ri->first % 10 << "\n";
            for(;Arabian / ri->first % 10 > 0; Arabian -= ri->first ) {
                if(Arabian/ ri->first % 10 == 9) {
                    Rome.push_back(Rome_to_Arabian[ri->first/10]);
                    Arabian -= ri->first/10;
                    Rome.push_back(ri->second);
                } else Rome.push_back(ri->second);
                if (Arabian / ri->first % 10 == 4) {
                    Rome.push_back(Rome_to_Arabian[ri->first]);
                    Rome.push_back(Rome_to_Arabian[ri->first*5]);
                    Arabian -= 4;
                } else Rome.push_back(ri->second);
            }
        }
        cout << Rome;
    }
};
int main() {
    RomeArabian RA;
    RA.ArabianToRome();
    return 0;
}
