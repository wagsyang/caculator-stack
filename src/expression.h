#pragma once
#include <QObject>

/**
 * @brief expression operation
 * 
 */
class Expression: public QObject {
  Q_OBJECT
public:
    explicit Expression(QObject* parent = nullptr);

    static bool iExpStrValidate(QString midfixExpStr);
    static QString midfixToPostfix(QString midfixExpStr);
    static int caculatePostfix(QString postfixExpStr);
};

