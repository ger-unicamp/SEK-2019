#include "upa.h"

void sek::andar_reto(){
	sek::leftMotor.set_sp_speed(200).run_forever();
	sek::rightMotor.set_sp_speed(200).run_forever();
}

