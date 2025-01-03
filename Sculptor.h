/**
 * @file Sculptor.h
 * @brief Define a classe Sculptor para manipula��o de matrizes tridimensionais de Voxels.
 *
 * Este arquivo cont�m a defini��o da classe Sculptor, que permite criar,
 * modificar e exportar esculturas em 3D baseadas em Voxels.
 */

#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "Voxels.h"
#include <string>

/**
 * @class Sculptor
 * @brief Classe respons�vel pela manipula��o de esculturas em 3D.
 */
class Sculptor {
private:
    Voxels ***v; /**< Matriz tridimensional de Voxels. */
    int nx, ny, nz; /**< Dimens�es da matriz nos eixos x, y e z. */
    float r, g, b, a; /**< Par�metros de cor (vermelho, verde, azul) e transpar�ncia (alfa). */

public:
    /**
     * @brief Construtor da classe Sculptor.
     *
     * Inicializa a matriz 3D com as dimens�es especificadas.
     *
     * @param _nx Dimens�o no eixo x.
     * @param _ny Dimens�o no eixo y.
     * @param _nz Dimens�o no eixo z.
     */
    Sculptor(int _nx, int _ny, int _nz);

    /**
     * @brief Destrutor da classe Sculptor.
     *
     * Libera a mem�ria alocada para a matriz 3D.
     */
    ~Sculptor();

    /**
     * @brief Define a cor e a transpar�ncia para os pr�ximos voxels ativados.
     *
     * @param r Valor do vermelho (0 a 1).
     * @param g Valor do verde (0 a 1).
     * @param b Valor do azul (0 a 1).
     * @param a Valor da transpar�ncia (0 a 1).
     */
    void setColor(float r, float g, float b, float a);

    /**
     * @brief Ativa um voxel em uma posi��o espec�fica.
     *
     * @param x Coordenada x.
     * @param y Coordenada y.
     * @param z Coordenada z.
     */
    void putVoxels(int x, int y, int z);

    /**
     * @brief Desativa um voxel em uma posi��o espec�fica.
     *
     * @param x Coordenada x.
     * @param y Coordenada y.
     * @param z Coordenada z.
     */
    void cutVoxels(int x, int y, int z);

    /**
     * @brief Ativa todos os voxels em um intervalo definido.
     *
     * @param x0 In�cio do intervalo no eixo x.
     * @param x1 Fim do intervalo no eixo x.
     * @param y0 In�cio do intervalo no eixo y.
     * @param y1 Fim do intervalo no eixo y.
     * @param z0 In�cio do intervalo no eixo z.
     * @param z1 Fim do intervalo no eixo z.
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

    /**
     * @brief Desativa todos os voxels em um intervalo definido.
     *
     * @param x0 In�cio do intervalo no eixo x.
     * @param x1 Fim do intervalo no eixo x.
     * @param y0 In�cio do intervalo no eixo y.
     * @param y1 Fim do intervalo no eixo y.
     * @param z0 In�cio do intervalo no eixo z.
     * @param z1 Fim do intervalo no eixo z.
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

    /**
     * @brief Ativa todos os voxels que satisfazem a equa��o de uma esfera.
     *
     * @param xcenter Coordenada x do centro da esfera.
     * @param ycenter Coordenada y do centro da esfera.
     * @param zcenter Coordenada z do centro da esfera.
     * @param radius Raio da esfera.
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);

    /**
     * @brief Desativa todos os voxels que satisfazem a equa��o de uma esfera.
     *
     * @param xcenter Coordenada x do centro da esfera.
     * @param ycenter Coordenada y do centro da esfera.
     * @param zcenter Coordenada z do centro da esfera.
     * @param radius Raio da esfera.
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    /**
     * @brief Ativa todos os voxels que satisfazem a equa��o de uma elipsoide.
     *
     * @param xcenter Coordenada x do centro da elipsoide.
     * @param ycenter Coordenada y do centro da elipsoide.
     * @param zcenter Coordenada z do centro da elipsoide.
     * @param rx Semi-eixo no eixo x.
     * @param ry Semi-eixo no eixo y.
     * @param rz Semi-eixo no eixo z.
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /**
     * @brief Desativa todos os voxels que satisfazem a equa��o de uma elipsoide.
     *
     * @param xcenter Coordenada x do centro da elipsoide.
     * @param ycenter Coordenada y do centro da elipsoide.
     * @param zcenter Coordenada z do centro da elipsoide.
     * @param rx Semi-eixo no eixo x.
     * @param ry Semi-eixo no eixo y.
     * @param rz Semi-eixo no eixo z.
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /**
     * @brief Salva a escultura em um arquivo no formato OFF.
     *
     * @param filename Nome do arquivo onde a escultura ser� salva.
     */
    void writeOFF(const std::string &filename);
};

#endif // SCULPTOR_H
