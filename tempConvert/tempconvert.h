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

private:
    Ui::tempConvert *ui;
    QString textValue;
};

#endif // TEMPCONVERT_H
