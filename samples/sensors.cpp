#include<bits/stdc++.h>
#include "ev3dev.h"

/*namespaces*/
using namespace std;
namespace ev3 = ev3dev;

/*funcao de tratamento de excessões*/
void precondition(bool cond, const std::string &msg) {
    if (!cond) throw std::runtime_error(msg);
}

int main(){
	//declaração de sensores
        ev3::ultrasonic_sensor ultra;
        ev3::touch_sensor ts;
        ev3::gyro_sensor gs;
        ev3::color_sensor cs;

        precondition(ultra.connected(), "problema no ultra");
        precondition(ts.connected(), "problema no ts");
        precondition(gs.connected(), "problema no gyro");
        precondition(cs.connected(), "problema no color");

        while(!ts.is_pressed()){
                cout << "Ultrasonic: " << ultra.distance_centimeters() << endl;
                cout << "Gyro: " << gs.angle() << endl;
                cout << "Color: " << cs.color() << endl;
        }
        return 0;
}
