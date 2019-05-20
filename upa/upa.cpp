#include "upa.h"

void sek::andar_reto(){
	sek::leftMotor.set_speed_sp(200).run_forever();
	sek::rightMotor.set_speed_sp(200).run_forever();
}

int main(){
	
	return 0;
}