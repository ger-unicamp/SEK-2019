#include "ev3dev.h"
namespace ev3 = ev3dev;

namespace sek{
	void andar_reto();
	void girar_esquerda();
	void girar_direita();
	void ultrassonico(ev3::ultrasonic_sensor ultra);
	void cor(ev3::color_sensor color);
}
