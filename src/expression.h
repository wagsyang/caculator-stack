#pragma once

#include <QObject>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include <stack>
#include <map>

enum OPER_PRIORITY{
    PRIORITY_NO,
    PRIORITY_PLUS,
    PRIORITY_MINUS,
    PRIORITY_MUL,
    PRIORITY_DIV,
};

enum OPER_TYPE{
    TYPE_OPERATOR,
    TYPE_OPERANT,
};

/* The struct of elements in expression */
struct ope_rant_rator{
    OPER_TYPE type;
    OPER_PRIORITY prior;
    std::string content;
};


class Expression: public QObject {
  //Q_OBJECT
//class Expression{

public:
    explicit Expression(QObject* parent = nullptr);
//    Expression();

    bool expresionValidation(std::string exp_str);
    void caculateExpressionResult();
    int getExpressionResult();

private:
    bool generatePaticle(std::string exp_str);
    std::vector<ope_rant_rator> midfixToPostfix(std::vector<ope_rant_rator> midfix_vec);
    std::string _exp_str;
    std::vector<ope_rant_rator> _exp_paticle;
    int _caculate_result;
};
