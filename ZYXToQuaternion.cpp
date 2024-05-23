#include <Eigen/Geometry>
#include <cmath>
#include <iostream>

int main() {
  // 定义欧拉角，单位为弧度
  double roll = 0.5 * M_PI;  // 绕X轴旋转
  double pitch = 0.7 * M_PI; // 绕Y轴旋转
  double yaw = 0;            // 绕Z轴旋转

  // 创建欧拉角对象，旋转顺序为ZYX
  Eigen::Quaternion<double> quaternion =
      Eigen::AngleAxis<double>(yaw, Eigen::Vector3d::UnitZ()) *
      Eigen::AngleAxis<double>(pitch, Eigen::Vector3d::UnitY()) *
      Eigen::AngleAxis<double>(roll, Eigen::Vector3d::UnitX());

  // 输出四元数的各个分量
  std::cout << "Quaternion w: " << quaternion.w() << std::endl;
  std::cout << "Quaternion x: " << quaternion.x() << std::endl;
  std::cout << "Quaternion y: " << quaternion.y() << std::endl;
  std::cout << "Quaternion z: " << quaternion.z() << std::endl;

  return 0;
}