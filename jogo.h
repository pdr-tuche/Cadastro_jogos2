#ifndef JOGO_H
#define JOGO_H

#include <QMainWindow>

class Jogo{
private:
    QString jogo;
    int quantidade;
    double codigo;
    double preco;
public:
    Jogo();
    QString getJogo() const;
    void setJogo(const QString &value);
    int getQuantidade() const;
    void setQuantidade(int value);
    double getCodigo() const;
    void setCodigo(double value);
    double getPreco() const;
    void setPreco(double value);
};

#endif // JOGO_H
