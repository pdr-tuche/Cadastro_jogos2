#ifndef FLIPERAMA_H
#define FLIPERAMA_H

#include <QVector>
#include <algorithm>
#include <QFile>
#include "jogo.h"

class Fliperama{
private:
    QVector<Jogo>link;

public:
    Fliperama();
    void inserir_jogo(Jogo zelda);
    void mudar_jogo(Jogo a, int i);
    void apagar_na_lista(QString a);
    void ordernarPorNome();
    void ordenarPorQuantidade();
    double media_preco();
    double menor_preco();
    double maior_preco();
    bool jogoExistente(Jogo a);
    bool CodigoExistente(Jogo a);
    bool salvarJogos(QString arquivo);
    bool carregarJogos(QString arquivo);
    Jogo operator[](int i);
    int size();
    int pesquisar_indice(QString a);
};
//funcoes auxiliares para ordenacao
bool alfabeticamente(Jogo a, Jogo b);
bool quant (Jogo a, Jogo b);

#endif // FLIPERAMA_H
