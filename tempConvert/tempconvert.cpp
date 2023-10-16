//This file is part of TempConvert
//TempConvert is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//TempConvert is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//You should have received a copy of the GNU General Public License along with TempConvert If not, see <https://www.gnu.org/licenses/>
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
    //Get the text from the line edit
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

//Get the last result and send it to the label fot the conversion
void tempConvert::on_ComboBox_currentIndexChanged()
{
    ui->lineEditSaisie->setText(ui->result->text());
}

//When the key enter is pressed it calls the function on_Convert_clicked()
void tempConvert::on_lineEditSaisie_returnPressed()
{
    this->on_Convert_clicked();
}

//Leave the application
void tempConvert::on_Leave_clicked()
{
    QWidget::close();
}

