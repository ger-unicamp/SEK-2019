#include "upa.h"
#include <vector>
using namespace std;

int sek::ultrassonico(ev3::ultrasonic_sensor ultra){
  vector<int> vet;
  for(int i=0;i<10;i++){
    vet.push_back(ultra.distance_centimeters());
  }
  return ((vet[4]+vet[5])/2);
}


void sek::andar_reto(){
	sek::leftMotor.set_speed_sp(200).run_forever();
	sek::rightMotor.set_speed_sp(200).run_forever();
}

int main(){

	return 0;
}
