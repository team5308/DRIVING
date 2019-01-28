/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ExampleSubsystem.h"

#include "RobotMap.h"

std::shared_ptr<frc::Joystick> ExampleSubsystem::joy1;

std::shared_ptr<WPI_TalonSRX> ExampleSubsystem::tal1;
std::shared_ptr<WPI_TalonSRX> ExampleSubsystem::tal2;
std::shared_ptr<WPI_VictorSPX> ExampleSubsystem::vic1;

std::shared_ptr<WPI_TalonSRX> ExampleSubsystem::tal3;
std::shared_ptr<WPI_TalonSRX> ExampleSubsystem::tal4;
std::shared_ptr<WPI_VictorSPX> ExampleSubsystem::vic2;

std::shared_ptr<frc::SpeedControllerGroup> ExampleSubsystem::scg1;
std::shared_ptr<frc::SpeedControllerGroup> ExampleSubsystem::scg2;

std::shared_ptr<frc::DifferentialDrive> ExampleSubsystem::diff;

ExampleSubsystem::ExampleSubsystem() : frc::Subsystem("ExampleSubsystem") {
  joy1.reset(new frc::Joystick(0));

  tal1.reset(new WPI_TalonSRX(0));
  tal2.reset(new WPI_TalonSRX(1));
  vic1.reset(new WPI_VictorSPX(2));

  tal3.reset(new WPI_TalonSRX(3));
  tal4.reset(new WPI_TalonSRX(4));
  vic2.reset(new WPI_VictorSPX(5));

  scg1 = std::make_shared<frc::SpeedControllerGroup>(*tal1, *tal2, *vic1);
  scg2 = std::make_shared<frc::SpeedControllerGroup>(*tal3, *tal4, *vic2);

  diff.reset(new frc::DifferentialDrive(*scg1, *scg2));


}

void ExampleSubsystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

inline double abs(double x){
  if(x < 0){
    return -x;
  }
  else{
    return x;
  }
}

double suoqu(double x){
  if(abs(x) <= 0.14){
    return 0.0;
  }else{
    return x;
  }
}

void ExampleSubsystem::Periodic(){
  diff -> ArcadeDrive(suoqu(joy1 -> GetY()), suoqu(joy1 -> GetX()));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
