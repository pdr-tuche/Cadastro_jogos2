#ifndef JANELA_H
#define JANELA_H
#include "fliperama.h"
#include <algorithm>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDateTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Janela; }
QT_END_NAMESPACE

class Janela : public QMainWindow
{
    Q_OBJECT

public:
    Janela(QWidget *parent = nullptr);
    ~Janela();

private slots:
    void on_Botao_clicked();
    void on_btn_Ordenar_por_nome_clicked();
    void on_btn_Ordenar_por_disponibilidade_clicked();
    void on_btn_salvar_clicked();
    void on_btn_carregar_arquivo_clicked();
    void on_btn_excluir_clicked();
    void on_btn_editar_clicked();
    void on_entrada_preco_returnPressed();
    void mostrar_hora();
private:
    Ui::Janela *ui;
    QString nome;
    int quantidade;
    double codigo;
    double preco;
    double media;
    Fliperama lista;

    void atualizar_estastisticas();
};
#endif // JANELA_H
