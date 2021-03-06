#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QDnsLookup;
class QHostInfo;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
     QDnsLookup *dns;
private slots:
    void lookedUp(const QHostInfo &host);
    void handleServers();
};

#endif // MAINWINDOW_H
