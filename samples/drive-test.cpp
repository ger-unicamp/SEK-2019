#include<bits/stdc++.h>
#include "ev3dev.h"

/*namespaces*/
using namespace std;
namespace ev3 = ev3dev;

/*funcao para tratamento de excessão*/
void precondition(bool cond, const std::string &msg) {
    if (!cond) throw std::runtime_error(msg);
}

int main(){
	//declaração dos motores e sensor
        ev3::large_motor leftMotor("outC");
        ev3::large_motor rightMotor("outB");
        ev3::touch_sensor ts;

        precondition(leftMotor.connected(), "motor no outB nao conectado");
        precondition(rightMotor.connected(), "motor no outC nao conectado");
        precondition(ts.connected(), "ts nao conectado");

        while(!ts.is_pressed()){
                rightMotor.set_speed_sp(200).run_forever();
                leftMotor.set_speed_sp(200).run_forever();
        }

        return 0;
}
