#include "tempconvert.h"
#include "ui_tempconvert.h"

tempConvert::tempConvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tempConvert)
{
    ui->setupUi(this);
    setFixedSize(400,150);
    setWindowTitle("Temperature Converter");
    setWindowIcon(QIcon(":/img/temperature.ico"));
}

tempConvert::~tempConvert()
{
    delete ui;
}

//Slot of convert button
//Manages conversion and display
void tempConvert::on_Convert_clicked()
{
    //get the text from the line edit
    textValue = ui->lineEditSaisie->text();
    double degreeValue = textValue.toDouble();

    if(textValue.isEmpty())
    {
        ui->result->setText("–.–");
        return;
    }
    else {
        double tempResultInt = 0;
        QString tempResultStr = "";

        //Switch change according to the index of the combobox
        switch (ui->ComboBox->currentIndex()) {
        case 0:
            tempResultInt = degreeValue + 273.15;
            tempResultStr = QString::number(tempResultInt);
            ui->result->setText(tempResultStr);
            ui->resultUnit->setText("K");
            break;
        case 1:
            tempResultInt = (degreeValue * (9/5)) + 32;
            tempResultStr = QString::number(tempResultInt);
            ui->result->setText(tempResultStr);
            ui->resultUnit->setText("F");
            break;
        case 2:
            tempResultInt = degreeValue - 273.15;
            tempResultStr = QString::number(tempResultInt);
            ui->result->setText(tempResultStr);
            ui->resultUnit->setText("C");
            break;
        case 3:
            tempResultInt = (degreeValue - 273.15) * (9/5) +32;
            tempResultStr = QString::number(tempResultInt);
            ui->result->setText(tempResultStr);
            ui->resultUnit->setText("F");
            break;
        case 4:
            tempResultInt = (degreeValue - 32) * (5/9);
            tempResultStr = QString::number(tempResultInt);
            ui->result->setText(tempResultStr);
            ui->resultUnit->setText("C");
            break;
        case 5:
            tempResultInt = (degreeValue - 32) * (5/9) + 273.15;
            tempResultStr = QString::number(tempResultInt);
            ui->result->setText(tempResultStr);
            ui->resultUnit->setText("K");
            break;
        }
    }
}

void tempConvert::on_ComboBox_currentIndexChanged()
{
    //Get the last result and send it to the label fot the conversion
    ui->lineEditSaisie->setText(ui->result->text());

}

void tempConvert::on_Leave_clicked()
{
    QWidget::close();
}

