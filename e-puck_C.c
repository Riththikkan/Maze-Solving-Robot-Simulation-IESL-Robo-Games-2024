/*
 * File:          wall_follower.c
 * Description:   Wall-following behavior for a Webots E-puck robot
 */

#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/distance_sensor.h>
#include <stdio.h>

/* Macros */
#define TIME_STEP 64
#define MAX_SPEED 6.28
#define SENSOR_THRESHOLD 85

int main(int argc, char **argv) {
  /* Initialize Webots */
  wb_robot_init();

  /* Motor initialization */
  WbDeviceTag left_motor = wb_robot_get_device("left wheel motor");
  WbDeviceTag right_motor = wb_robot_get_device("right wheel motor");

  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);
  wb_motor_set_velocity(right_motor, 0.0);

  /* Distance sensor initialization */
  WbDeviceTag prox_sensors[8];
  char prox_sensor_name[50];
  for (int ind = 0; ind < 8; ++ind) {
    sprintf(prox_sensor_name, "ps%d", ind);
    prox_sensors[ind] = wb_robot_get_device(prox_sensor_name);
    wb_distance_sensor_enable(prox_sensors[ind], TIME_STEP);
  }

  double left_speed = 0.0;
  double right_speed = 0.0;

  while (wb_robot_step(TIME_STEP) != -1) {
    /* Sensor readings */
    double left_wall_sensor = wb_distance_sensor_get_value(prox_sensors[5]);
    double left_corner_sensor = wb_distance_sensor_get_value(prox_sensors[6]);
    double front_sensor = wb_distance_sensor_get_value(prox_sensors[7]);
    double right_wall_sensor = wb_distance_sensor_get_value(prox_sensors[2]);

    /* Wall detection logic */
    bool left_wall = left_wall_sensor > SENSOR_THRESHOLD;
    bool left_corner = left_corner_sensor > 85;
    bool front_wall = front_sensor > SENSOR_THRESHOLD;
    bool right_wall = right_wall_sensor > SENSOR_THRESHOLD;

    /* Behavior logic */
    if (front_wall && left_wall) {
      /* Wall on left and wall on front: Turn right */
      left_speed = MAX_SPEED;
      right_speed = -MAX_SPEED;
      if (left_corner) {
      left_speed = MAX_SPEED;
      right_speed = -MAX_SPEED;
    }
    } else if (!left_wall && !right_wall && front_wall) {
      /* No wall on left, no wall on right, and wall on front: Turn right */
      left_speed = MAX_SPEED;
      right_speed = -MAX_SPEED ;
      if (left_corner) {
      left_speed = MAX_SPEED;
      right_speed = -MAX_SPEED;
    }
    } else if (!left_wall) {
      /* No wall on left: Turn left */
      left_speed = MAX_SPEED/4;
      right_speed = MAX_SPEED;
      if (left_corner) {
      left_speed = MAX_SPEED;
      right_speed = -MAX_SPEED;
    }
    } else if (left_wall) {
      /* Wall on left: Move forward */
      left_speed = MAX_SPEED;
      right_speed = MAX_SPEED;
      if (left_corner) {
      left_speed = MAX_SPEED;
      right_speed = -MAX_SPEED;
    }
    }     
    else {
      /* No walls detected: Move forward */
      left_speed = MAX_SPEED;
      right_speed = MAX_SPEED;
    }

    /* Set motor velocities */
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
  }

  /* Cleanup */
  wb_robot_cleanup();
  return 0;
}