cmake_minimum_required(VERSION 3.25)
project(Data_Structure_Curriculum_Design)

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++") #否则在release构建中只能在clion内置终端运行

add_executable(Data_Structure_Curriculum_Design
        main.cpp HandleRequest.h GenerateArithmeticExpression.h ConvertToRPN.h SqCharStack.h SqCharStack.cpp
            HandleRequest.cpp GenerateArithmeticExpression.cpp ConvertToRPN.cpp SqDoubleStack.h SqDoubleStack.cpp HandleHistory.h HandleHistory.cpp)

#add_executable(test test.cpp)