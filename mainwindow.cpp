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
    mundo = Mundo();
    pol = Poligono();

    ui->telaParaViewPort->update();
}

MainWindow::~MainWindow()
{
    delete ui;
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
   /* QLabel *nomeLabel = new QLabel(tr("Nome do Ponto:"));
    QLineEdit *nomeEdit = new QLineEdit(parent);

    QLabel *xCoordinateLabel = new QLabel(tr("X:"));
    QLineEdit *xCoordinateEdit = new QLineEdit(parent);

     xCoordinateEdit->setFixedWidth(35);
     xCoordinateEdit->setMaxLength(3);

     QLabel *yCoordinateLabel = new QLabel(tr("Y:"));
     QLineEdit *yCoordinateEdit = new QLineEdit(parent);
     yCoordinateEdit->setFixedWidth(35);
     yCoordinateEdit->setMaxLength(3);

     QPushButton *criarPonto = new QPushButton("Criar Ponto", this);
     QAction *createPonto = new QAction(tr("create Ponto"), this);
     createPonto->setCheckable(true);
   //  connect(createPonto,SIGNAL(triggered(bool)), this, SLOT(novoPonto()));

    QVBoxLayout *main2Layout = new QVBoxLayout;
    main2Layout->addWidget(nomeLabel);
    main2Layout->addWidget(nomeEdit);
    main2Layout->addWidget(xCoordinateLabel);
    main2Layout->addWidget(xCoordinateEdit);
    main2Layout->addWidget(yCoordinateLabel);
    main2Layout->addWidget(yCoordinateEdit);
    main2Layout->addWidget(criarPonto);

    main2Layout->addStretch(1);
    setLayout(main2Layout);
*/
}

void MainWindow::novoPonto(){
    if(ui->nomePonto_Edit->text()==""){
        ui->console->setText("O nome do ponto e obrigatorio!");
        return;
    }
    Ponto novo = Ponto(ui->nomePonto_Edit->text(),Coordenada(ui->pontox_Edit->text().toInt(), ui->pontoy_Edit->text().toInt()));
    mundo.adicionarObjeto(novo);
    ui->telaParaViewPort->setMundo(mundo);
    ui->listaObjetos->addItem(ui->nomePonto_Edit->text()+ " (Ponto) ");
    ui->telaParaViewPort->update();

    ui->nomePonto_Edit->setText("");
    ui->pontox_Edit->setText("");
    ui->pontoy_Edit->setText("");

    return;
}

void MainWindow::novaReta(){
    if(ui->nomereta_Edit->text()==""){
        ui->console->setText("O nome da reta e obrigatorio!");
        return;
    }
    Reta nova = Reta(ui->nomereta_Edit->text(),Coordenada(ui->retax1_Edit->text().toInt(),ui->retay1_Edit->text().toInt()), Coordenada(ui->retax2_Edit->text().toInt(),ui->retay2_Edit->text().toInt()));
    mundo.adicionarObjeto(nova);
    ui->telaParaViewPort->setMundo(mundo);
    ui->listaObjetos->addItem(ui->nomereta_Edit->text()+ " (Reta) ");
    ui->telaParaViewPort->update();

    ui->nomereta_Edit->setText("");
    ui->retax1_Edit->setText("");
    ui->retay1_Edit->setText("");
    ui->retax2_Edit->setText("");
    ui->retay2_Edit->setText("");
            return;
}
void MainWindow::novoPoligono(){
  //  ui->console->setText("novoPoligono");
    if(pol.quantidadeDePontos()<3 && ui->polx1_Edit->isModified() && ui->poly1_Edit->isModified() && ui->polx2_Edit->isModified() && ui->poly2_Edit->isModified() && ui->polx3_Edit->isModified() && ui->poly3_Edit->isModified()){
            addPontoPoligono();
    } else if(ui->nomepol_Edit->text()==""){
        ui->console->setText("O nome do poligono e obrigatorio!");
        return;
    }
    else if(pol.quantidadeDePontos()==0 || (!ui->polx1_Edit->isModified() && !ui->poly1_Edit->isModified() && !ui->polx2_Edit->isModified() && !ui->poly2_Edit->isModified())){
        ui->console->setText("Entre com pelo menos 3 pontos");
        return;
    }

    pol.adicionarNome(ui->nomepol_Edit->text());
    Poligono aux = pol;
    mundo.adicionarObjeto(aux);
    pol=Poligono();
    ui->telaParaViewPort->setMundo(mundo);
    ui->listaObjetos->addItem(ui->nomepol_Edit->text()+ " (Poligono) ");
    ui->telaParaViewPort->update();

    ui->polx2->setHidden(false);
    ui->poly2->setHidden(false);
    ui->polx2_Edit->setHidden(false);
    ui->poly2_Edit->setHidden(false);
    ui->polx3->setHidden(false);
    ui->poly3->setHidden(false);
    ui->polx3_Edit->setHidden(false);
    ui->poly3_Edit->setHidden(false);
    ui->nomepol_Edit->setText("");
    ui->polx1_Edit->setText("");
    ui->poly1_Edit->setText("");
    ui->polx2_Edit->setText("");
    ui->poly2_Edit->setText("");
    ui->polx3_Edit->setText("");
    ui->poly3_Edit->setText("");


    return;


}

void MainWindow::addPontoPoligono(){
if(pol.quantidadeDePontos()<3){
    pol.adicionarPonto(Coordenada(ui->polx1_Edit->text().toInt(),ui->poly1_Edit->text().toInt()));
    pol.adicionarPonto(Coordenada(ui->polx2_Edit->text().toInt(),ui->poly2_Edit->text().toInt()));
    pol.adicionarPonto(Coordenada(ui->polx3_Edit->text().toInt(),ui->poly3_Edit->text().toInt()));

    ui->polx2->setHidden(true);
    ui->poly2->setHidden(true);
    ui->polx2_Edit->setHidden(true);
    ui->poly2_Edit->setHidden(true);
    ui->polx3->setHidden(true);
    ui->poly3->setHidden(true);
    ui->polx3_Edit->setHidden(true);
    ui->poly3_Edit->setHidden(true);
}
else{
    pol.adicionarPonto(Coordenada(ui->polx1_Edit->text().toInt(),ui->poly1_Edit->text().toInt()));
}

    ui->polx1->setText("X"+QString::number( pol.quantidadeDePontos()+1)+" :");
    ui->poly1->setText("Y"+QString::number( pol.quantidadeDePontos()+1)+" :");

    ui->polx1_Edit->setText("");
    ui->poly1_Edit->setText("");

    return;

}

void MainWindow::zoomMinus(){
    ui->telaParaViewPort->zoom(false);
}

void MainWindow::zoomPlus(){
    ui->telaParaViewPort->zoom(true);
}

// Substituir numeros por constante, erro expanded from macro
void MainWindow::moveUp(){
    ui->telaParaViewPort->moverTela(1);
}

void MainWindow::moveDown(){
    ui->telaParaViewPort->moverTela(2);
}

void MainWindow::moveLeft(){
    ui->telaParaViewPort->moverTela(3);
}

void MainWindow::moveRight(){
    ui->telaParaViewPort->moverTela(4);
}

