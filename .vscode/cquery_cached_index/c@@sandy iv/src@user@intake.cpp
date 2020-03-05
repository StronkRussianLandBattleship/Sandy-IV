#include "user/intake.hpp"
#include "user/lift.hpp"

/*README IF YOU WANT TO CHANGE ANY OF THESE MOTORS
  TO REVERSE:
    Set the third value in the constructor call to its current opposite;
    if it is 1 now, change it to 0, if it is 0 now, change it to 1.

  TO CHANGE PORT:
    Change the first value in the constructor call to the motor's new port.

  You can also mouse over the constructor to gain additional information about
  each parameter if you desire.
*/
Motor intakeL(5, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
Motor intakeR(2, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);

void initIntake()
{
  intakeL.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  intakeR.set_brake_mode(E_MOTOR_BRAKE_BRAKE);

  intakeL.tare_position();
  intakeR.tare_position();
}

void setIntake(std::string state)
{
  if(state == "in")
  {
    intakeL.move(-127);
    intakeR.move(-127);
  }
  else if(state == "out")
  {
    intakeL.move(127);
    intakeR.move(127);
  }
  else if(state == "off")
  {
    intakeL.move(0);
    intakeR.move(0);
  }
}

void controlIntake(Controller controller)
{
  if(controller.get_digital(E_CONTROLLER_DIGITAL_L1))
  {
    setIntake("out");
  }
  else if(controller.get_digital(E_CONTROLLER_DIGITAL_L2))
  {
    setIntake("in");
  }
  else
  {
    setIntake("off");
  }
}

void controlIntake(int btnIn, int btnOut)
{
  if(btnOut)
  {
    setIntake("out");
  }
  else if(btnIn)
  {
    setIntake("in");
  }
  else
  {
    setIntake("off");
  }
}
