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
    std::string midfixExpStr = expStr.toStdString();
    // check expression validation
    if(!Expression::iExpStrValidate(midfixExpStr)){
        emit infoExpressionInvalidate();
        return;
    }

    // caculate expression 
    int result = Expression::caculatePostfix(Expression::midfixToPostfix(midfixExpStr));
    QString resStr;
    emit sendCaculateResult(resStr.setNum(result));
}