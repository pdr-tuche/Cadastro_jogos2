#include "jogo.h"
#include "ui_janela.h"

QString Jogo::getJogo() const
{
    return jogo;
}

void Jogo::setJogo(const QString &value)
{
   if(value.size() > 3 or value == "")
       jogo = value;
   else
       jogo = "INVALIDO";
}

int Jogo::getQuantidade() const
{
    return quantidade;
}

void Jogo::setQuantidade(int value)
{
    if(value <= 0)
        quantidade = 0;
    else
        quantidade = value;
}

double Jogo::getCodigo() const
{
    return codigo;
}

void Jogo::setCodigo(double value)
{
    codigo = value;
}

double Jogo::getPreco() const
{
    return preco;
}

void Jogo::setPreco(double value)
{
    if(value >=0)
        preco = value;
    else
        value = 0.0;
}

Jogo::Jogo(){}
