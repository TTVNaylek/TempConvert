#include "tempconvert.h"
#include "ui_tempconvert.h"

tempConvert::tempConvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tempConvert)
{
    ui->setupUi(this);
    setFixedSize(400,150);
    setWindowIcon(QIcon(":/img/temperature.ico"));
}

tempConvert::~tempConvert()
{
    delete ui;
}



//Slot du bouton convertir
//gère la conversion et l'affichage
void tempConvert::on_Convert_clicked()
{
    //get the text from the line edit
    textValue = ui->lineEditSaisie->text();
    double degreeValue = textValue.toDouble();

    double tempResultInt = 0;
    QString tempResultStr = "";

    switch (ui->ComboBox->currentIndex()) {
    case 0:
        tempResultInt = degreeValue + 273.15;
        tempResultStr = QString::number(tempResultInt);
        ui->result->setText(tempResultStr + " K");
        break;
    case 1:
        tempResultInt = (degreeValue * (9/5)) + 32;
        tempResultStr = QString::number(tempResultInt);
        ui->result->setText(tempResultStr + " F");
        break;
    case 2:
        tempResultInt = degreeValue - 273.15;
        tempResultStr = QString::number(tempResultInt);
        ui->result->setText(tempResultStr + " C");
        break;
    case 3:
        tempResultInt = (degreeValue - 273.15) * (9/5) +32;
        tempResultStr = QString::number(tempResultInt);
        ui->result->setText(tempResultStr + " F");
        break;
    case 4:
        tempResultInt = (degreeValue - 32) * (5/9);
        tempResultStr = QString::number(tempResultInt);
        ui->result->setText(tempResultStr + " C");
        break;
    case 5:
        tempResultInt = (degreeValue - 32) * (5/9) + 273.15;
        tempResultStr = QString::number(tempResultInt);
        ui->result->setText(tempResultStr + " K");
        break;
    }

    //QObject::connect(degreeValue, SIGNAL(), , SLOT());
}



void tempConvert::on_Leave_clicked()
{
    QWidget::close();
}
