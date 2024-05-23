#include <Eigen/Dense>
#include <cmath>
#include <drake/math/roll_pitch_yaw.h>
#include <drake/math/rotation_matrix.h>
#include <iostream>

int main() {
  // 定义RPY角，单位为弧度
  double roll = 0;           // 滚转角
  double pitch = 0.5 * M_PI; // 俯仰角
  double yaw = 0;            // 偏航角

  // 使用RPY角创建一个RollPitchYaw对象
  drake::math::RollPitchYaw<double> rpy(roll, pitch, yaw);

  // 将RPY对象转换为RotationMatrix对象
  drake::math::RotationMatrix<double> rotation_matrix = rpy.ToRotationMatrix();

  // 从RotationMatrix对象获取四元数
  Eigen::Quaternion<double> quaternion = rotation_matrix.ToQuaternion();

  // 输出四元数的各个分量
  std::cout << "Quaternion w: " << quaternion.w() << std::endl;
  std::cout << "Quaternion x: " << quaternion.x() << std::endl;
  std::cout << "Quaternion y: " << quaternion.y() << std::endl;
  std::cout << "Quaternion z: " << quaternion.z() << std::endl;

  return 0;
}
