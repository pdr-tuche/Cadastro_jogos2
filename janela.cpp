#include "janela.h"
#include "ui_janela.h"

Janela::Janela(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Janela)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(mostrar_hora()));
    timer->start();

    QDateTime dia = QDateTime::currentDateTimeUtc();
    QString dia_texto = dia.toString();
    ui->data_dia->setText(dia_texto);
}

Janela::~Janela()
{
    delete ui;
}

void Janela::atualizar_estastisticas(){
    media = lista.media_preco();
    ui->label_show_media->setText(QString::number(media));
    ui->label_show_maior_preco->setText(QString::number(lista.maior_preco()));
    ui->label_show_menor_preco->setText(QString::number(lista.menor_preco()));
}

void Janela::on_Botao_clicked(){
    Jogo nintendo;
    //criando objeto.
    nome = ui->entrada_nome->text();
    codigo = ui->entrada_codigo->text().toDouble();
    quantidade = ui->entrada_quantidade->text().toInt();
    preco = ui->entrada_preco->text().toDouble();

    nintendo.setJogo(nome);
    nintendo.setCodigo(codigo);
    nintendo.setQuantidade(quantidade);
    nintendo.setPreco(preco);

    //validando informacoes do objeto para adicionar a lista
    if(lista.jogoExistente(nintendo) == true or
            lista.CodigoExistente(nintendo) == true or
            ui->entrada_nome->text() == "" or
            ui->entrada_preco->text() == "" or
            ui->entrada_codigo->text() == "" or
            ui->entrada_quantidade->text() == ""){
        QMessageBox::warning(this,"ERRO","houve um erro.\nOs atributos: nome do jogo, quantidade,"
                                         "preco ou codigo cadastrados com parametros invalidos.");
        return ;
    }
    if(nintendo.getJogo() == "INVALIDO" or
            nintendo.getQuantidade() == 0 or
            nintendo.getPreco() == 0.0){
        QMessageBox::warning(this,"ERRO","houve um erro.\nOs atributos: nome do jogo, quantidade,"
                                         "preco ou codigo cadastrados com parametros invalidos.");
        return;
    }
    //fim das validacoes

    lista.inserir_jogo(nintendo);
    ui->entrada_nome->setFocus();

    //fazendo tabela
    int qnt_linhas = ui->tabela->rowCount();
    ui->tabela->insertRow(qnt_linhas);
    for(int i=0;i<lista.size();i++){
            ui->tabela->setItem(qnt_linhas,0,new QTableWidgetItem(lista[i].getJogo()));
            ui->tabela->setItem(qnt_linhas,1,new QTableWidgetItem(QString::number(lista[i].getQuantidade())));
            ui->tabela->setItem(qnt_linhas,2,new QTableWidgetItem(QString::number(lista[i].getCodigo())));
            ui->tabela->setItem(qnt_linhas,3,new QTableWidgetItem(QString::number(lista[i].getPreco())));
    }
    atualizar_estastisticas();
    ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabela->setSelectionBehavior(QAbstractItemView::SelectRows);
    //final da tabela.

    ui->entrada_nome->clear();
    ui->entrada_codigo->clear();
    ui->entrada_quantidade->clear();
    ui->entrada_preco->clear();
    ui->entrada_nome->setFocus();
}


void Janela::on_entrada_preco_returnPressed(){
    Jogo nintendo;
    //criando objeto.
    nome = ui->entrada_nome->text();
    codigo = ui->entrada_codigo->text().toDouble();
    quantidade = ui->entrada_quantidade->text().toInt();
    preco = ui->entrada_preco->text().toDouble();

    nintendo.setJogo(nome);
    nintendo.setCodigo(codigo);
    nintendo.setQuantidade(quantidade);
    nintendo.setPreco(preco);

    //validando informacoes do objeto para adicionar a lista
    if(lista.jogoExistente(nintendo) == true or
            lista.CodigoExistente(nintendo) == true or
            ui->entrada_nome->text() == "" or
            ui->entrada_preco->text() == "" or
            ui->entrada_codigo->text() == "" or
            ui->entrada_quantidade->text() == ""){
        QMessageBox::warning(this,"ERRO","houve um erro.\nOs atributos: nome do jogo, quantidade,"
                                         "preco ou codigo cadastrados com parametros invalidos.");
        return ;
    }
    if(nintendo.getJogo() == "INVALIDO" or
            nintendo.getQuantidade() == 0 or
            nintendo.getPreco() == 0.0){
        QMessageBox::warning(this,"ERRO","houve um erro.\nOs atributos: nome do jogo, quantidade,"
                                         "preco ou codigo cadastrados com parametros invalidos.");
        return;
    }
    //fim das validacoes

    lista.inserir_jogo(nintendo);
    ui->entrada_nome->setFocus();

    //fazendo tabela
    int qnt_linhas = ui->tabela->rowCount();
    ui->tabela->insertRow(qnt_linhas);
    for(int i=0;i<lista.size();i++){
            ui->tabela->setItem(qnt_linhas,0,new QTableWidgetItem(lista[i].getJogo()));
            ui->tabela->setItem(qnt_linhas,1,new QTableWidgetItem(QString::number(lista[i].getQuantidade())));
            ui->tabela->setItem(qnt_linhas,2,new QTableWidgetItem(QString::number(lista[i].getCodigo())));
            ui->tabela->setItem(qnt_linhas,3,new QTableWidgetItem(QString::number(lista[i].getPreco())));
    }
    atualizar_estastisticas();
    ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabela->setSelectionBehavior(QAbstractItemView::SelectRows);
    //final da tabela.

    ui->entrada_nome->clear();
    ui->entrada_codigo->clear();
    ui->entrada_quantidade->clear();
    ui->entrada_preco->clear();
    ui->entrada_nome->setFocus();
}


void Janela::on_btn_Ordenar_por_nome_clicked(){
    lista.ordernarPorNome();
    ui->tabela->clearContents();

    for(int i=0;i<lista.size();i++){
        ui->tabela->setItem(i,0,new QTableWidgetItem(lista[i].getJogo()));
        ui->tabela->setItem(i,1,new QTableWidgetItem(QString::number(lista[i].getQuantidade())));
        ui->tabela->setItem(i,2,new QTableWidgetItem(QString::number(lista[i].getCodigo())));
        ui->tabela->setItem(i,3,new QTableWidgetItem(QString::number(lista[i].getPreco())));
    }
    ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabela->setSelectionBehavior(QAbstractItemView::SelectRows);
}


void Janela::on_btn_Ordenar_por_disponibilidade_clicked(){
    lista.ordenarPorQuantidade();
    ui->tabela->clearContents();

    for(int i=0;i<lista.size();i++){
        ui->tabela->setItem(i,0,new QTableWidgetItem(lista[i].getJogo()));
        ui->tabela->setItem(i,1,new QTableWidgetItem(QString::number(lista[i].getQuantidade())));
        ui->tabela->setItem(i,2,new QTableWidgetItem(QString::number(lista[i].getCodigo())));
        ui->tabela->setItem(i,3,new QTableWidgetItem(QString::number(lista[i].getPreco())));
    }
    ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabela->setSelectionBehavior(QAbstractItemView::SelectRows);
}


void Janela::on_btn_salvar_clicked(){
    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de jogos","","CSV(*.csv)");
        lista.salvarJogos(nomeArquivo);
}


void Janela::on_btn_carregar_arquivo_clicked(){
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de jogos","","CSV(*.csv)");
    lista.carregarJogos(nomeArquivo);
    //fazendo tabela
    for(int j=0;j<lista.size();j++){
        int qnt_linhas =j;
        ui->tabela->insertRow(qnt_linhas);

        for(int i=0;i<lista.size();i++){
            ui->tabela->setItem(i,0,new QTableWidgetItem(lista[i].getJogo()));
            ui->tabela->setItem(i,1,new QTableWidgetItem(QString::number(lista[i].getQuantidade())));
            ui->tabela->setItem(i,2,new QTableWidgetItem(QString::number(lista[i].getCodigo())));
            ui->tabela->setItem(i,3,new QTableWidgetItem(QString::number(lista[i].getPreco())));
        }
    }
    ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabela->setSelectionBehavior(QAbstractItemView::SelectRows);

    atualizar_estastisticas();
}



void Janela::on_btn_excluir_clicked(){
    //apagando cadastro.
    int linha = ui->tabela->currentRow();
    QString jogo = ui->tabela->item(linha,0)->text();
    lista.apagar_na_lista(jogo);
    QMessageBox::information(this,"","Cadastro excluido.");

    //atualizando tabela
    ui->tabela->clearContents();
    for(int i=0;i<lista.size() and lista[i].getJogo() != "";i++){
        ui->tabela->setItem(i,0,new QTableWidgetItem(lista[i].getJogo()));
        ui->tabela->setItem(i,1,new QTableWidgetItem(QString::number(lista[i].getQuantidade())));
        ui->tabela->setItem(i,2,new QTableWidgetItem(QString::number(lista[i].getCodigo())));
        ui->tabela->setItem(i,3,new QTableWidgetItem(QString::number(lista[i].getPreco())));
    }
    ui->tabela->removeRow(linha);
    ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabela->setSelectionBehavior(QAbstractItemView::SelectRows);

    atualizar_estastisticas();
}

void Janela::on_btn_editar_clicked(){
    //crio um novo objeto e sobrescrevo do item selecionado na tabela
    int linha = ui->tabela->currentRow();
    Jogo temp;
    nome = ui->entrada_nome->text();
    codigo = ui->entrada_codigo->text().toDouble();
    quantidade = ui->entrada_quantidade->text().toInt();
    preco = ui->entrada_preco->text().toDouble();
    temp.setJogo(nome);
    temp.setQuantidade(quantidade);
    temp.setCodigo(codigo);
    temp.setPreco(preco);

    //validando informacoes do objeto para adicionar a lista
    if(lista.jogoExistente(temp) == true or
            ui->entrada_nome->text() == "" or
            ui->entrada_preco->text() == "" or
            ui->entrada_codigo->text() == "" or
            ui->entrada_quantidade->text() == ""){
        QMessageBox::warning(this,"ERRO","houve um erro.\nOs atributos: nome do jogo, quantidade,"
                                         "preco ou codigo cadastrados com parametros invalidos.");
        QMessageBox::information(this,"","Não foi possivel editar o cadastro.\nTente novamente.");
        return ;
    }
    if(temp.getJogo() == "INVALIDO" or
            temp.getQuantidade() == 0 or
            temp.getPreco() == 0.0){
        QMessageBox::warning(this,"ERRO","houve um erro.\nOs atributos: nome do jogo, quantidade,"
                                         "preco ou codigo cadastrados com parametros invalidos.");
        QMessageBox::information(this,"","Não foi possivel editar o cadastro.\nTente novamente.");
        return;
    }
    /*fim das validacoes
     *
     sobrescrevendo no vector*/
    lista.mudar_jogo(temp,linha);

    //atualizando tabela exatamente onde houve a alteracao
    ui->tabela->setItem(linha,0,new QTableWidgetItem(temp.getJogo()));
    ui->tabela->setItem(linha,1,new QTableWidgetItem(QString::number(temp.getQuantidade())));
    ui->tabela->setItem(linha,2,new QTableWidgetItem(QString::number(temp.getCodigo())));
    ui->tabela->setItem(linha,3,new QTableWidgetItem(QString::number(temp.getPreco())));

    ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabela->setSelectionBehavior(QAbstractItemView::SelectRows);

    atualizar_estastisticas();

    ui->entrada_nome->clear();
    ui->entrada_codigo->clear();
    ui->entrada_quantidade->clear();
    ui->entrada_preco->clear();
    ui->entrada_nome->setFocus();
    QMessageBox::information(this,"","Cadastro editado.");
}

void Janela::mostrar_hora(){
    QTime tempo = QTime::currentTime();
    QString tempo_texto = tempo.toString("hh : mm : ss");
    ui->relogio_digital->setText(tempo_texto);
}
