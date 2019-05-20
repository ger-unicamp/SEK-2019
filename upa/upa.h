#include "../ev3dev.h"
namespace ev3 = ev3dev;

namespace sek{
	ev3::large_motor leftMotor("outC");
        ev3::large_motor rightMotor("outB");
	ev3::medium_motor mMotor("outD");
	void andar_reto();
	void girar_esquerda();
	void girar_direita();
	void ultrassonico(ev3::ultrasonic_sensor ultra);
	void cor(ev3::color_sensor color);
}
