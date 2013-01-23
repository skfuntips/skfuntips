#ifndef ZHU_CHUANG_KOU_H
#define ZHU_CHUANG_KOU_H

#include <QMainWindow>


#include <boost/scoped_ptr.hpp>


class SourceWidget;
class ResultWidget;
class ProcessWidget;
class ParamListWidget;
class CompositeResourceWidget;
class ProcessThread;

namespace Ui{
class MainFrame;
}

class MainFrame:public QMainWindow{

    Q_OBJECT

public:

    MainFrame(QWidget* parent=0);

    virtual ~MainFrame();

private slots:

    void executeProcess();

    void on_action_about_triggered();

    void on_action_help_triggered();

    void on_pushButton_again_clicked();

    void processFinished();

    void on_checkBox_tuiGuang_stateChanged();

private:

    SourceWidget *SourceWidget_;
    ResultWidget *ResultWidget_;

    ProcessWidget *ProcessWidget_;
    ParamListWidget *ParamListWidget_;

    boost::scoped_ptr<Ui::MainFrame> ui_;

    boost::scoped_ptr<ProcessThread> ProcessThread_;

    CompositeResourceWidget *keywordsCompositeResourceWidget_;
    CompositeResourceWidget *highlightCompositeResourceWidget_;

    const QString shareString_;
};



#endif //ZHU_CHUANG_KOU_H
