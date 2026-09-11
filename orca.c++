#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class KomponenROV {
    protected:
    string Nama; string Status;

    public:
    KomponenROV (string s, string k) : Nama(s), Status(k) {};

    virtual void info() {
        cout << "Nama: " << Nama <<" Status: "<< Status << endl;
    }
};

class Thruster : public KomponenROV {
    public:
     double Power; 

    Thruster(string s, string k, double p) : KomponenROV(s, k), Power(p) {}
    virtual void info(){
        KomponenROV :: info();
        cout << "Power: " << Power << endl;
    };
};



class Sensor : public KomponenROV 
{
    public:
     double Nilai; 

    Sensor (string n, string s, double i) : KomponenROV(n, s),Nilai(i) {}
    virtual void info(){
        KomponenROV :: info();
        cout << "Nilai: " << Nilai << endl;
    };
}; 


int main() {
    vector<unique_ptr<KomponenROV>> komponenList;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string j, N, s;
        double nt;
        cin >> j >> N >> s >> nt;

        if (j == "Thruster") {
           komponenList.push_back( make_unique <Thruster> (N, s, nt));
        }
        else if (j == "Sensor") {
            komponenList.push_back( make_unique <Sensor> (N, s, nt));
        }
    }

    for (const auto& Komponen : komponenList){
        Komponen ->info();
    }

    return 0;
}
