#include "mainwindow.h"
#include <stdio.h>
#include <QtWidgets>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->showMaximized();
    setFocusPolicy(Qt::StrongFocus);
    ui->setupUi(this);
    createActions();
    createToolBars();

    QPixmap *pixmap = new QPixmap(100, 100);
    pixmap->fill(Qt::black);
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem();

    QGraphicsScene *scene = new QGraphicsScene(0,0,100,100);



   // ui->viewport->setScene(scene);

    QPainter painter;
    painter.begin(pixmap);
    painter.setPen(QColor(0,255,0));
    painter.drawLine(20,20,30,30);
    painter.setPen(QColor(255,0,0));
    painter.drawEllipse(30,30,30,30);
    painter.end();
    pixmapItem->setPixmap(*pixmap);
     scene->addItem(pixmapItem);
     ui->viewport->setScene(scene);
    ui->viewport->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createToolBars()
{
    menuCG = addToolBar(tr("File"));
    menuCG->addAction(inserirObjeto);
}

void MainWindow::createActions()
//! [17] //! [18]
{
    inserirObjeto = new QAction(QIcon(":/imagens/new.png"), tr("&Adicionar novo objeto"),this);
    inserirObjeto->setShortcuts(QKeySequence::New);
    inserirObjeto->setStatusTip(tr("Add a new object"));
    connect(inserirObjeto, SIGNAL(triggered()), this, SLOT(adicionarObjeto()));

}
void MainWindow::adicionarObjeto()
{
    tabWidget = new QTabWidget;
    tabWidget->addTab(new PontoTab('a'), tr("Ponto"));
   // tabWidget->addTab(new RetaTab('a'), tr("Reta"));
   // tabWidget->addTab(new PoligonoTab('a'), tr("Polígono"));

    //buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok                                     | QDialogButtonBox::Cancel);

   // connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
   // connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
  //  mainLayout->addWidget(buttonBox);
    tabWidget->setWindowTitle("Adicionar Objeto");
    tabWidget->show();
}

//void MainWindow::accept(){}
//void MainWindow::reject(){}

void MainWindow::on_pushButton_up_clicked()
{
    printf("ENTROU PB UPPPPPP");

}
PontoTab::PontoTab(char nome,QWidget *parent)
    : QWidget(parent)
{
    QLabel *nomeLabel = new QLabel(tr("Nome do Ponto:"));
    QLineEdit *nomeEdit = new QLineEdit(parent);

    QLabel *xCoordinateLabel = new QLabel(tr("X:"));
    QLineEdit *xCoordinateEdit = new QLineEdit(parent);

     xCoordinateEdit->setFixedWidth(35);
     xCoordinateEdit->setMaxLength(3);

     QLabel *yCoordinateLabel = new QLabel(tr("Y:"));
     QLineEdit *yCoordinateEdit = new QLineEdit(parent);
     yCoordinateEdit->setFixedWidth(35);
     yCoordinateEdit->setMaxLength(3);

    QVBoxLayout *main2Layout = new QVBoxLayout;
    main2Layout->addWidget(nomeLabel);
    main2Layout->addWidget(nomeEdit);
    main2Layout->addWidget(xCoordinateLabel);
    main2Layout->addWidget(xCoordinateEdit);
    main2Layout->addWidget(yCoordinateLabel);
    main2Layout->addWidget(yCoordinateEdit);

    main2Layout->addStretch(1);
    setLayout(main2Layout);

}
