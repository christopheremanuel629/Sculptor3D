/***
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE
    CENTRO DE TECNOLOGIA - DEPARTAMENTO DE ENGENHARIA ELÉTRICA
    PROGRAMAÇÃO AVANÇADA (DCA 0803) - 2024.2

    Docente: Agostinho Brito.

    Autor: Christopher Emanuel de Lima Gomes.
    Matrícula: 20240012282



**/


#include <iostream>
#include "sculptor.h"
#include <cmath>


    class meuBalao {

    private:
        Sculptor ballon;

    public:

        meuBalao(int x, int y, int z) : ballon(x, y, z) {
        ballon.cutBox(0, x, 0, y, 0, z);
    }
    void criarBalao (){

        //Cor vermelha para balão
        ballon.setColor(1.0, 0.0, 0.0, 1.0);

        //Esfera do balão
        ballon.putSphere(100, 250, 100, 100);
        ballon.cutSphere(100,250,100,99);

        //Base para o ar quente
        ballon.putEllipsoid(100, 100, 100, 20, 1, 20);

        //Forma para o encaminhamento do ar quente
        for (int h = 0; h <= 52; h++){
            ballon.putEllipsoid(100, (100+h), 100, 21, 1, 21);
            ballon.cutEllipsoid(100, (100+h), 100, 20, 1, 20);
            }

        //Estrutura de fixação entre balão e o cesto
        for (int i = 0; i <=50; i++){
            ballon.putEllipsoid(100, (125+i), 100,(14+i), 1, (14+i));
            ballon.cutEllipsoid(100, (125+i), 100,(13+i), 1, (13+i));
            }
    }
    void criarCordas (){

        //Base para as cordas
        ballon.setColor(0.76,0.7,0.5, 1.0);
        ballon.putBox(76, 80, 40, 41, 76, 80);
        ballon.putBox(120, 124, 40, 41, 120, 124);
        ballon.putBox(76, 80, 40, 41, 120, 124);
        ballon.putBox(120, 124, 40, 41, 76, 80);

        ballon.putBox(78, 80, 38, 39, 78, 80);
        ballon.putBox(120, 122, 38, 39, 120, 122);
        ballon.putBox(78, 80, 38, 39, 120, 122);
        ballon.putBox(120, 122, 38, 39, 78, 80);

        ballon.putBox(79, 80, 37, 37, 79, 80);
        ballon.putBox(120, 121, 37, 37, 120, 121);
        ballon.putBox(79, 80, 37, 37, 120, 121);
        ballon.putBox(120, 121, 37, 37, 79, 80);

        //Cordas
        ballon.setColor(0.63, 0.32, 0.18, 1.0);
        ballon.putBox(77, 79, 42, 88, 77, 79);
        ballon.putBox(121, 123, 42, 88, 121, 123);
        ballon.putBox(77, 79, 42, 88, 121, 123);
        ballon.putBox(121, 123,42, 88, 77, 79);

        //Cordas ramificadas para o centro

        for( int c = 0; c <= 46; c++) {
            ballon.putBox((77+c), (78+c), (89), (89), (77+c), (78+c));
            ballon.putBox((121-c), (122-c), (89), (89), (121-c), (122-c));
            ballon.putBox((77+c), (78+c), (89), (89), (121-c), (122-c));
            ballon.putBox((121-c), (122-c), (89), (89), (77+c), (78+c));
        }

        //Cordas até o balão
        ballon.putBox(77, 79, 89, 175, 77, 79);
        ballon.putBox(121, 123, 89, 175, 121, 123);
        ballon.putBox(77, 79, 89, 175, 121, 123);
        ballon.putBox(121, 123,89, 175, 77, 79);


        //Estrutura de fixação das cordas
        ballon.setColor(0.80, 0.52, 0.25, 1.0);
        ballon.putBox(75, 81, 81, 86, 75, 81);
        ballon.putBox(75, 81, 81, 86, 119, 125);
        ballon.putBox(119, 125, 81, 86, 75, 81);
        ballon.putBox(119, 125, 81, 86, 119, 125);

        //Estrutura de fixação entre as cordas
        ballon.setColor(0.80, 0.52, 0.25, 1.0);
        ballon.putBox(82, 119, 81, 86, 75, 81);
        ballon.putBox(82, 119, 81, 86, 119, 125);
        ballon.putBox(119, 125, 81, 86, 82, 119);
        ballon.putBox(75, 81, 81, 86, 82, 125);

    }

    void criarCesto (){

        //Cubo do cesto e retidado da parte interna
        ballon.setColor(0.80, 0.52, 0.25, 1.0);
        ballon.putBox(80, 120, 0, 40, 80, 120);
        ballon.cutBox(82, 118, 2, 40, 82, 118);

        //Detalhes
        for (int l = 0; l <= 10; l++){
                ballon.cutBox(85+l,115-l,40-l,40-l,80,81);
                ballon.cutBox(85+l,115-l,40-l,40-l,119,120);
                ballon.cutBox(80,81,40-l,40-l,85+l,115-l);
                ballon.cutBox(119,120,40-l,40-l,85+l,115-l);
            }
    }

    void criarMacarico(){

        //Encapsulamento do fogo (mola)

        ballon.setColor(0.71,0.72,0.69, 1.0);
        for(int m = 0; m <= 5; m++){
            ballon.putEllipsoid(100,(100 - 2*m),100, 10, 1, 10);
            ballon.cutEllipsoid(100,(100 - 2*m),100, 9, 1, 9);
            ballon.putVoxels(109,(99-2*m),(102-m));
            ballon.cutVoxels(109,(100-2*m),(102-m));
            ballon.cutVoxels(109,(100-2*m),(103-m));

        }
            //Retirando o voxels extra
            ballon.cutVoxels(109,89,97);


            //Criando a "base" para o fogo
            ballon.setColor(0.32,0.34,0.33,1.0);
            ballon.putEllipsoid(100,(90),100, 5, 1, 5);
            ballon.cutVoxels(100,91,100);

            //Estrutura do fogo
            ballon.setColor(1.0, 0.271, 0.0, 0.7);
            ballon.putBox(98,102,91,104, 98,102);

            //Tentativa de criar a sensação do fogo
            for (int l = 0; l <= 3; l++){
                ballon.cutBox((98+l),(102-l),(104-l),(104-l), (98+l),(102-l));
                ballon.cutBox((98+l),(102-l),(104-l),(104-l), (98),(98));
                ballon.cutBox((98+l),(102-l),(104-l),(104-l), (102),(102));
                ballon.cutBox((98),(98),(104-l),(104-l), (98+l),(102-l));
                ballon.cutBox((102),(102),(104-l),(104-l), (98+l),(102-l));
            }
            //Detalhes do fogo
                ballon.cutBox(99,101,102,102,99,101);
                ballon.cutVoxels(100,101,100);
    }

    void criarEnfeites(){
        //Criando aros dourados em volta do balao
        ballon.setColor(0.937,0.749,0.016, 0.7);
        ballon.putEllipsoid(100, 250, 100, 101,1,101);
        ballon.cutEllipsoid(100, 250, 100, 100,1,100);
        ballon.putEllipsoid(100, 275, 100, 101,1,101);
        ballon.cutEllipsoid(100, 275, 100, 100,1,100);
        ballon.putEllipsoid(100, 225, 100, 101,1,101);
        ballon.cutEllipsoid(100, 225, 100, 100,1,100);
        }

     void salvarOFF(const std::string &nomeArquivo) {
        ballon.writeOFF(nomeArquivo);
    }
};
int main() {


    meuBalao desenho(600, 600, 600);

    desenho.criarEnfeites();
    desenho.criarMacarico();
    desenho.criarCordas();
    desenho.criarBalao();
    desenho.criarCesto();

    // Salvando o resultado no formato OFF
    desenho.salvarOFF("balloon.off");

    std::cout << "Balão criado e salvo como 'balloon.off'" << std::endl;
    return 0;
}


