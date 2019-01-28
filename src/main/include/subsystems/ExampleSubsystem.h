/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>

class ExampleSubsystem : public frc::Subsystem {
 public:
  ExampleSubsystem();
  void InitDefaultCommand() override;
  void Periodic() override;

  static std::shared_ptr<frc::Joystick> joy1;

  static std::shared_ptr<WPI_TalonSRX> tal1;
  static std::shared_ptr<WPI_TalonSRX> tal2;
  static std::shared_ptr<WPI_VictorSPX> vic1;

  static std::shared_ptr<WPI_TalonSRX> tal3;
  static std::shared_ptr<WPI_TalonSRX> tal4;
  static std::shared_ptr<WPI_VictorSPX> vic2;

  static std::shared_ptr<frc::SpeedControllerGroup> scg1;
  static std::shared_ptr<frc::SpeedControllerGroup> scg2;

  static std::shared_ptr<frc::DifferentialDrive> diff;


 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
};
