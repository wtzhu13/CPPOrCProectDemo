#ifndef CHOOSELEVELSENCE_H
#define CHOOSELEVELSENCE_H

#include <QMainWindow>

namespace Ui {
class ChooseLevelSence;
}

class ChooseLevelSence : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseLevelSence(QWidget *parent = nullptr);
    ~ChooseLevelSence();

private:
    Ui::ChooseLevelSence *ui;
};

#endif // CHOOSELEVELSENCE_H
