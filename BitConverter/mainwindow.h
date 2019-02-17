#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QNetworkReply>
#include <QMainWindow>


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
    QString myURL = "https://blockchain.info/tobtc?currency=%rep1&value=%rep2";

private slots:
    void downloadFinished(QNetworkReply *);
    void on_pushButton_clicked();
};


#endif // MAINWINDOW_H
