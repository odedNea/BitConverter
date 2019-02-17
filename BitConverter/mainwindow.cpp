#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkAccessManager>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::downloadFinished(QNetworkReply *reply)
{
    QString bitVal = reply->readAll();
    ui->label->setText(bitVal + " BIT");
}

void MainWindow::on_pushButton_clicked()
{
    QString str = ui->textEdit->toPlainText();
    QRegExp rx(" ");
    QStringList formats = str.split(rx, QString::SkipEmptyParts);
    ui->textEdit->clear();
    if (formats.length() != 2)
    {
        ui->label->setText("Please type in the following format: amount + ' ' + currency");

        return;
    }
    QString newURL = myURL;
    newURL.replace("%rep1",formats[1]).replace("%rep2",formats[0]);

    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &MainWindow::downloadFinished);
    const QUrl url = QUrl(newURL);
    QNetworkRequest request(url);

    man->get(request);
}


