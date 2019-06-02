/**
*@file  upa.h
*@brief Arquivo header para código a ser utilizado no upa 2019
*@warning código não finalizado e não testado
*@todo implementar cor e função de som
*/

#include "../ev3dev.h"
namespace ev3 = ev3dev;

namespace sek{
	//variables
	ev3::ultrasonic_sensor ultrasonic;
	ev3::large_motor leftMotor("outC");
        ev3::large_motor rightMotor("outB");
	ev3::medium_motor mMotor("outD");
	
	//functions
	/**
	*Função andar reto usando o método run_forever do ev3
	*@author Natan
	*/
	void andar_reto();
	/**
	*Função girar esquerda usando o método run_timed do ev3 e o ultrasonic aqui declarado
	*@author Leandro
	*@return retorna a distancia vista na esquerda do robô
	*/
	int girar_esquerda();
	/**
	*Função girar direita usando o método run_timed do ev3 e o ultrasonic aqui declarado, avalia qual a menor
	*distancia e a segue
	*@author Leandro
	*/
	void girar_direita();
	/**
	*Função ultrassonico usa o método distanceRead do ultrasonic aqui declarado, avalia 10 distancias 
	*inserindo em um vetor e retorna a media dos valores no meio do vetor (maior precisão)
	*@author Natan
	*/
	float ultrassonico();
	/**
	*Função para avaliar a cor do sensor de cor ultizando métodos do color sensor aqui declarado
	*@todo não implementada
	*/
	void cor(ev3::color_sensor color);
}
