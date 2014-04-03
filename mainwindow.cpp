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

    /** Eixos X e Y **/
    Reta eixoX = Reta("eixoX",Coordenada(0,4000),Coordenada(0,-4000));
    Reta eixoY = Reta("eixoY",Coordenada(4000,0),Coordenada(-4000,0));
    eixoX.setColor(QColor(0,255,0,255));
    eixoY.setColor(QColor(0,255,0,255));
    mundo.adicionarObjeto(eixoX);
    mundo.adicionarObjeto(eixoY);

    pol = Poligono();

    ui->telaParaViewPort->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::novoPonto(){
    if(ui->nomePonto_Edit->text()==""){
        ui->console->setText("O nome do ponto e obrigatorio!");
        return;
    }
    Ponto novo = Ponto(ui->nomePonto_Edit->text(),Coordenada(ui->pontox_Edit->text().toInt(), ui->pontoy_Edit->text().toInt()));
    novo.setRandomColor();
    mundo.adicionarObjeto(novo);
    ui->telaParaViewPort->setMundo(mundo);
    ui->listaObjetos->addItem(ui->nomePonto_Edit->text()+ " (Ponto) ");
    ui->telaParaViewPort->update();

    ui->console->setText("Novo Ponto: "+ novo.toString());
    zerarCampos();
    return;
}

void MainWindow::novaReta(){
    if(ui->nomereta_Edit->text()==""){
        ui->console->setText("O nome da reta e obrigatorio!");
        return;
    }
    Reta nova = Reta(ui->nomereta_Edit->text(),Coordenada(ui->retax1_Edit->text().toInt(),ui->retay1_Edit->text().toInt()), Coordenada(ui->retax2_Edit->text().toInt(),ui->retay2_Edit->text().toInt()));
    nova.setRandomColor();
    mundo.adicionarObjeto(nova);
    ui->telaParaViewPort->setMundo(mundo);
    ui->listaObjetos->addItem(ui->nomereta_Edit->text()+ " (Reta) ");
    ui->telaParaViewPort->update();

    ui->console->setText("Nova Reta:"+ nova.toString());
    zerarCampos();
    return;
}
void MainWindow::novoPoligono(){
  //  ui->console->setText("novoPoligono");
    if(ui->nomepol_Edit->text()==""){
        // Se nao tem nome
        ui->console->setText("O nome do poligono e obrigatorio!");
        return;
    }else
        if(pol.quantidadeDePontos()<3 && ui->polx1_Edit->isModified() && ui->poly1_Edit->isModified() && ui->polx2_Edit->isModified() && ui->poly2_Edit->isModified() && ui->polx3_Edit->isModified() && ui->poly3_Edit->isModified()){
            //Preencheu todos os 3 pontos
            addPontoPoligono();
    }
    else{
        ui->console->setText("Preencha todos os pontos");
        return;
    }
    addPontoPoligono();
    pol.adicionarNome(ui->nomepol_Edit->text());
    pol.setRandomColor();
    mundo.adicionarObjeto(pol);
    ui->console->setText("Novo Poligono:"+ pol.toString());
    pol=Poligono();
    ui->telaParaViewPort->setMundo(mundo);
    ui->listaObjetos->addItem(ui->nomepol_Edit->text()+ " (Poligono) ");
    ui->telaParaViewPort->update();

    ocultarCamposPoligono(false);
    ui->polx1->setText("X1");
    ui->poly1->setText("Y1");

    zerarCampos();
    return;
}

void MainWindow::addPontoPoligono(){
    if(pol.quantidadeDePontos()<3){
        pol.adicionarPonto(Coordenada(ui->polx1_Edit->text().toInt(),ui->poly1_Edit->text().toInt()));
        pol.adicionarPonto(Coordenada(ui->polx2_Edit->text().toInt(),ui->poly2_Edit->text().toInt()));
        pol.adicionarPonto(Coordenada(ui->polx3_Edit->text().toInt(),ui->poly3_Edit->text().toInt()));
        ocultarCamposPoligono(true);
    }
    else{
        if(ui->polx1_Edit->isModified() && ui->poly1_Edit->isModified())
            pol.adicionarPonto(Coordenada(ui->polx1_Edit->text().toInt(),ui->poly1_Edit->text().toInt()));

    }

    ui->polx1->setText("X"+QString::number( pol.quantidadeDePontos()+1)+" :");
    ui->poly1->setText("Y"+QString::number( pol.quantidadeDePontos()+1)+" :");

    zerarCampos();
    return;
}

void MainWindow::zerarCampos(){
    //ponto
    ui->nomePonto_Edit->setText("");
    ui->pontox_Edit->setText("");
    ui->pontoy_Edit->setText("");

    //reta
    ui->nomereta_Edit->setText("");
    ui->retax1_Edit->setText("");
    ui->retay1_Edit->setText("");
    ui->retax2_Edit->setText("");
    ui->retay2_Edit->setText("");

    //poligono
    ui->nomepol_Edit->setText("");
    ui->polx1_Edit->setText("");
    ui->poly1_Edit->setText("");
    ui->polx2_Edit->setText("");
    ui->poly2_Edit->setText("");
    ui->polx3_Edit->setText("");
    ui->poly3_Edit->setText("");
}

void MainWindow::ocultarCamposPoligono(bool ocultar){
    ui->polx2->setHidden(ocultar);
    ui->poly2->setHidden(ocultar);
    ui->polx2_Edit->setHidden(ocultar);
    ui->poly2_Edit->setHidden(ocultar);
    ui->polx3->setHidden(ocultar);
    ui->poly3->setHidden(ocultar);
    ui->polx3_Edit->setHidden(ocultar);
    ui->poly3_Edit->setHidden(ocultar);
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

