#pragma once
#include <QObject>
#include <string>
#include <algorithm>
#include <iostream>

/**
 * @brief expression operation( operant:integer operator:+-/* ) 
 * 
 */
class Expression: public QObject {
  Q_OBJECT
public:
    explicit Expression(QObject* parent = nullptr);

    static bool iExpStrValidate(const std::string &midfixExpStr);
    static std::string midfixToPostfix(const std::string &midfixExpStr);
    static int caculatePostfix(const std::string &postfixExpStr);
};

