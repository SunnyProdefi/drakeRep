cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0 LANGUAGES CXX)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
# 设置 Drake 的安装路径
list(APPEND CMAKE_PREFIX_PATH "/opt/drake")

# 寻找 Drake 和 Eigen 库
find_package(drake CONFIG REQUIRED)
add_executable(eigenEx1 RigidTransform.cpp)
target_link_libraries(eigenEx1 Eigen3::Eigen drake::drake)

add_executable(ToQuaternion ToQuaternion.cpp)
target_link_libraries(ToQuaternion Eigen3::Eigen drake::drake)

add_executable(ZYXToQuaternion ZYXToQuaternion.cpp)
target_link_libraries(ZYXToQuaternion Eigen3::Eigen)