//
// Created by Shanwer on 2023/10/31.
//

//This head file is unused due to its undefined reference to template function, causing me lots of trouble
#ifndef CHECK_RESULT_H
#define CHECK_RESULT_H

#include <string>

double calculateResult(std::string rpn);

template <typename T>
bool checkResult(T result, double calculatedResult);

#endif //CHECK_RESULT_H
