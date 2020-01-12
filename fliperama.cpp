#include "fliperama.h"

Fliperama::Fliperama(){}

void Fliperama::inserir_jogo(Jogo zelda){
    link.push_back(zelda);
}

int Fliperama::size(){
    return link.size();
}

Jogo Fliperama::operator[](int i){
    return link[i];
}

void Fliperama::ordernarPorNome(){
    std::sort(link.begin(),link.end(), alfabeticamente);
}

void Fliperama::ordenarPorQuantidade(){
    std::sort(link.begin(),link.end(), quant);
}

double Fliperama::media_preco(){
    double acumulador =0;
    for (int i=0;i<link.size();i++){
        acumulador+= link[i].getPreco();
    }
    return acumulador/link.size();
}

double Fliperama::maior_preco(){
    double preco = 0.0;
     for(int i=0;i<link.size();i++){
         if(link[i].getPreco() > preco)
             preco = link[i].getPreco();
     }
     return preco;
}

double Fliperama::menor_preco(){
    double preco = maior_preco();
     for(int i=0;i<link.size();i++){
         if(link[i].getPreco() < preco)
             preco = link[i].getPreco();
     }
     return preco;
}

bool Fliperama::jogoExistente(Jogo a){
    for(int i=0;i<link.size();i++){
        if(link[i].getJogo() == a.getJogo())
            return true;
    }
    return false;
}

bool Fliperama::CodigoExistente(Jogo a){
    for(int i=0;i<link.size();i++){
        if(link[i].getCodigo() == a.getCodigo())
            return true;
    }
    return false;
}

bool Fliperama::salvarJogos(QString arquivo){
    QFile file(arquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly))
        return false;
    else
        for(int i=0;i<link.size();i++){
                linha = link[i].getJogo() + ','
                        + QString::number(link[i].getQuantidade()) + ','
                        + QString::number(link[i].getCodigo()) + ','
                        + QString::number(link[i].getPreco()) + '\n';
                file.write(linha.toLocal8Bit());
            }
    return true;
}

bool Fliperama::carregarJogos(QString arquivo){
    QFile file(arquivo);
    if(!file.open(QIODevice::ReadOnly))
        return false;

    QString linha;
    Jogo xis;
    while(!file.atEnd()){
        linha = file.readLine();
        QStringList data = linha.split(",");

        xis.setJogo(data[0]);
        xis.setQuantidade(data[1].toInt());
        xis.setCodigo(data[2].toDouble());
        xis.setPreco(data[3].toDouble());

        inserir_jogo(xis);
    }
    return true;
}

int Fliperama::pesquisar_indice(QString a){
    for(int i=0;i<link.size();i++){
        if(link[i].getJogo() == a){
            return i;
        }
    }
}

void Fliperama::mudar_jogo(Jogo a, int i){
    for(int j=0;j<link.size();j++){
        if(j==i)
            link[j] = a;
    }
}

void Fliperama::apagar_na_lista(QString a){
    for(int i=0;i<link.size();i++){
        if(a == link[i].getJogo())
            link.erase(link.begin()+i);
    }
}

bool alfabeticamente(Jogo a, Jogo b){
    return a.getJogo().toUpper() < b.getJogo().toUpper();
}

bool quant (Jogo a, Jogo b){
    return a.getQuantidade() > b.getQuantidade();
}


