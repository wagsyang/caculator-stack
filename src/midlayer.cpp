#include "midlayer.h"

MidLayer::MidLayer(QObject* parent)
  : QObject(parent) 
{
    ;
}

MidLayer::~MidLayer()
{
    ;
}

void MidLayer::caculateExpression(QString expStr)
{   
    std::string expression_str = expStr.toStdString();
    // check expression validation
    if(! expression->expresionValidation(expression_str)){
        emit infoExpressionInvalidate();
        return;
    }

    // caculate expression
    expression->caculateExpressionResult();
    int result = expression->getExpressionResult();
    QString resStr;
    emit sendCaculateResult(resStr.setNum(result));
}
