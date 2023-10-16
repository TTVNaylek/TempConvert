//This file is part of TempConvert
//TempConvert is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//TempConvert is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//You should have received a copy of the GNU General Public License along with TempConvert If not, see <https://www.gnu.org/licenses/>
#ifndef TEMPCONVERT_H
#define TEMPCONVERT_H
#include <QWidget>
#include <QString>

namespace Ui {
class tempConvert;
}

class tempConvert : public QWidget
{
    Q_OBJECT

public:
    explicit tempConvert(QWidget *parent = nullptr);
    ~tempConvert();

private slots:
    void on_Convert_clicked();

    void on_Leave_clicked();

    void on_ComboBox_currentIndexChanged();


    void on_lineEditSaisie_returnPressed();

private:
    Ui::tempConvert *ui;
    QString textValue;
};

#endif // TEMPCONVERT_H
