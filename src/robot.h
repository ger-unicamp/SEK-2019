#ifndef ROBOT
#define ROBOT

#include "ev3dev.h"
#include <string>


namespace ev3 = ev3dev;
/**
 * Comentary: classe que representa o nosso robo terrestre (ev3). encapsula codigos para mover motores e 
 * sensores
 * 
 * @author: Natan
 * @since: 17/06/19
 */
class robot {
private:

    int time, speed;
    std::string stop_action;
    ev3::ultasonic_sensor front_dist, side_dist;
    ev3::gyro_sensor gyro;
    ev3::color_sensor col_sensor1, col_sensor2;
    ev3::touch_sensor touch;

    /**
     * Commentary:
     * 
     * @author:
     * @since:
     * @return:
     */
    int rotate();

public:

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     * @param max_speed:
     * @param stop_action:
     */
    robot(int max_speed, const std::string stop_action);

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     * @param speed:
     */
    void run_forever(int speed);

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     * @param time:
     * @param speed:
     */
    void run_timed(int time, int speed);

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     */
    void stop();

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     * @param stop_action:
     */
    void stop(std::string stop_action);

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     */
    void turn_left();

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     * @param ang:
     */
    void turn_left(int ang);

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     */
    void turn_right();

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     * @param ang:
     */
    void turn_right(int ang);

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     * @return:
     */
    int get_front_dist();

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     * @return:
     */
    int get_side_dist();

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     * @return:
     */
    bool touch();

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     * @param sensor:
     * @return:
     */
    int get_color(const std::string sensor);

    /**
     * Commentary:
     * 
     * @author:
     * @since: 
     * @param cond:
     * @param msg:
     * @return:
     */
    bool precondition(bool cond, const std::sting msg);
}

#endif
