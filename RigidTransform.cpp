#include <Eigen/Dense>
#include <drake/math/rigid_transform.h>
#include <drake/math/roll_pitch_yaw.h>
#include <drake/math/rotation_matrix.h>
#include <iostream>

int main() {
  // 定义点A的位姿 X_WA
  Eigen::Vector3d translation_WA(1.0, 2.0, 3.0); // 位于世界坐标系中的位置

  // 定义绕Z轴旋转90度 (π/2弧度)
  drake::math::RollPitchYaw<double> rpy_WA(0, 0, 0);
  drake::math::RotationMatrix<double> rotation_WA(rpy_WA);

  drake::math::RigidTransform<double> X_WA(rotation_WA, translation_WA);

  // 定义从点A到点B的位姿变化 X_AB
  Eigen::Vector3d translation_AB(0.5, 0.0, -0.5);    // 从A到B的位置变化
  drake::math::RollPitchYaw<double> rpy_AB(0, 0, 0); // 从A到B的旋转变化
  drake::math::RotationMatrix<double> rotation_AB(rpy_AB);
  drake::math::RigidTransform<double> X_AB(rotation_AB, translation_AB);

  // 计算点B的位姿 X_WB
  drake::math::RigidTransform<double> X_WB = X_WA * X_AB;

  // 输出点B的位姿
  Eigen::Vector3d translation_WB = X_WB.translation();
  drake::math::RollPitchYaw<double> rpy_WB(X_WB.rotation());

  std::cout << "Point B position: (" << translation_WB.x() << ", "
            << translation_WB.y() << ", " << translation_WB.z() << ")"
            << std::endl;
  std::cout << "Point B orientation (Roll, Pitch, Yaw): ("
            << rpy_WB.roll_angle() << ", " << rpy_WB.pitch_angle() << ", "
            << rpy_WB.yaw_angle() << ")" << std::endl;
  std::cout << "Point B position: (" << translation_WB.x() << ", "
            << translation_WB.y() << ", " << translation_WB.z() << ")"
            << std::endl;
  std::cout << "Point B orientation (Roll, Pitch, Yaw): ("
            << rpy_WB.roll_angle() << ", " << rpy_WB.pitch_angle() << ", "
            << rpy_WB.yaw_angle() << ")" << std::endl;
  std::cout << "Point B position: (" << translation_WB.x() << ", "
            << translation_WB.y() << ", " << translation_WB.z() << ")"
            << std::endl;
  std::cout << "Point B orientation (Roll, Pitch, Yaw): ("
            << rpy_WB.roll_angle() << ", " << rpy_WB.pitch_angle() << ", "
            << rpy_WB.yaw_angle() << ")" << std::endl;
  std::cout << "X_WB.value: " << X_WB.translation() << std::endl;

  return 0;
}
