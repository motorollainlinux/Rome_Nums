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
            for(;Arabian / ri->first % 10 > 0; ) {
                if(Arabian / ri->first % 10 == 1 && Arabian - 9 == 0) {
                    Rome.push_back(Rome_to_Arabian[ri->first/5]);
                    Rome.push_back(Rome_to_Arabian[ri->first*2]);
                    Arabian -= 9;
                } else if (Arabian / ri->first % 10 == 4 && Arabian - 4 == 0) {
                    Rome.push_back(Rome_to_Arabian[ri->first]);
                    Rome.push_back(Rome_to_Arabian[ri->first*5]);
                    Arabian -= 4;
                } else {
                    Rome.push_back(ri->second);
                    Arabian -= ri->first;
                }
            }
        }
        cout << "In rome numberic is a: " << Rome << "\n";
    }
    void RomeToArabian() {
        string Rome;
        int Arabian = 0;
        FC::IsAMaskSymbols("Enter a rome number ", "IVXLCDM", Rome);
        
        for(map <int, char> :: iterator ri = Rome_to_Arabian.begin(); ri != Rome_to_Arabian.end(); ri++) {
            for(int i = Rome.length(); i >= 0; i--) {
                if(Rome[i] == ri->second) {
                    if(Rome[i-1] == 'I' && Rome[i] != 'I') {
                        Arabian += ri->first-1;
                    }else
                    Arabian += ri->first;
                }
            }
        }
        cout << "In arabian numberic is a: " << Arabian << "\n";
    }
};
int main() {
    RomeArabian RA;
    bool IsExit = false;
    int UserChoise = -2;
    do{
        FC::IsAInt("How you want?(0 - tranfer rome to arabian; 1 - tranfer arabian to rome; -1 - exit program): ", UserChoise);
        if(UserChoise == 0) 
        RA.RomeToArabian();
        else if(UserChoise == 1)
        RA.ArabianToRome();
        else if(UserChoise == -1)
        IsExit = true;
        else cout << "Invalid Enter!\n";
        UserChoise = -2;
    } while(!IsExit);
    return 0;
}
