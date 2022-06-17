#pragma once

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include "expression.h"
#include <iostream>


class MidLayer : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MidLayer)

 public:
  MidLayer(QObject* parent = 0);
  ~MidLayer();

 signals:
  void infoExpressionInvalidate();
  void sendCaculateResult(QString result);
 

 public slots:
  void caculateExpression(QString expStr);

private:
  Expression* expression  = new Expression();
};

