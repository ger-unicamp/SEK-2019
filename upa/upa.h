#include "../ev3dev.h"
namespace ev3 = ev3dev;

namespace sek{
	//variables
	ev3::ultrasonic_sensor ultrasonic;

	//functions
	ev3::large_motor leftMotor("outC");
        ev3::large_motor rightMotor("outB");
	ev3::medium_motor mMotor("outD");
	void andar_reto();
	int girar_esquerda();
	void girar_direita();
	float ultrassonico();
	void cor(ev3::color_sensor color);
}
