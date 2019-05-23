#include "upa.h"
#include <vector>
using namespace std;

float sek::ultrassonico(){
  vector<float> vet;
  for(int i=0;i<10;i++){
    vet.push_back(sek::ultrasonic.distance_centimeters());
  }
  return ((vet[4]+vet[5])/2);
}


void sek::andar_reto(){
	sek::leftMotor.set_speed_sp(200).run_forever();
	sek::rightMotor.set_speed_sp(200).run_forever();
}

void sek::girar_direita(){
	sek::leftMotor.set_stop_action("hold").stop_action();
	sek::rightMotor.set_stop_action("hold").stop_action();

	sek::leftMotor.set_stop_action("hold").set_time_sp(1500).set_speed_sp(300).run_timed();
	sek::rightMotor.set_stop_action("hold").set_time_sp(1500).set_speed_sp(-300).run_timed();

	int rightDistance = ultrassonico();
	int leftDistance = girar_esquerda();
	
	if(leftDistance < rightDistance){
		girar_direita();
		girar_direita();
	}
	
}

int sek::girar_esquerda(){
	sek::leftMotor.set_stop_action("hold").stop_action();
	sek::rightMotor.set_stop_action("hold").stop_action();

	sek::leftMotor.set_stop_action("hold").set_time_sp(3000).set_speed_sp(-300).run_timed();
	sek::leftMotor.set_stop_action("hold").set_time_sp(3000).set_speed_sp(300).run_timed();

	int rightDistance = ultrassonico();
	return rightDistance;

}

int main(){

	bool bSynchronous = false;
	const std::string soundfile = "r2d2_sound.wav";//colocar pathing aqui

	ev3::sound::play( soundfile, bSynchronous );
	/*void sound::play(const std::string &soundfile, bool bSynchronous)
	{
			std::ostringstream cmd;
			cmd << "/usr/bin/aplay -q " << soundfile;
			if (!bSynchronous) cmd << " &";
			std::system(cmd.str().c_str());
	}*/
	//método .str() :
	// retorna uma instancia de string copiada da string no buffer cmd
	//http://www.cplusplus.com/reference/sstream/ostringstream/str/
	//método .c_str() :
	//A pointer to the c-string(*char) representation of the basic_string(classe mãe de string) object's value.
	//http://www.cplusplus.com/reference/string/basic_string/c_str/

	return 0;
}
