#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <QDropEvent>
#include <QMimeData>
#include <rar.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void dragEnterEvent(QDragEnterEvent *e)
    {
        if (e->mimeData()->hasUrls()) {
            e->acceptProposedAction();
        }

    }

    void dropEvent(QDropEvent *e)
    {
        foreach (const QUrl &url, e->mimeData()->urls()) {
           QString fileName = url.toLocalFile();
           RAR ob;
           if(ob.file(fileName))
               QMessageBox::information(this,"Success!","RAR file created successfully from your file in your directory");
           else
             QMessageBox::information(this,"Error","Drop Only Powerpoint or Word file here!");
                }
    }

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
