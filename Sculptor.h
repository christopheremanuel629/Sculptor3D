/**
 * @file Sculptor.h
 * @brief Define a classe Sculptor para manipulação de matrizes tridimensionais de Voxels.
 *
 * Este arquivo contém a definição da classe Sculptor, que permite criar,
 * modificar e exportar esculturas em 3D baseadas em Voxels.
 */

#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "Voxels.h"
#include <string>

/**
 * @class Sculptor
 * @brief Classe responsável pela manipulação de esculturas em 3D.
 */
class Sculptor {
private:
    Voxels ***v; /**< Matriz tridimensional de Voxels. */
    int nx, ny, nz; /**< Dimensões da matriz nos eixos x, y e z. */
    float r, g, b, a; /**< Parâmetros de cor (vermelho, verde, azul) e transparência (alfa). */

public:
    /**
     * @brief Construtor da classe Sculptor.
     *
     * Inicializa a matriz 3D com as dimensões especificadas.
     *
     * @param _nx Dimensão no eixo x.
     * @param _ny Dimensão no eixo y.
     * @param _nz Dimensão no eixo z.
     */
    Sculptor(int _nx, int _ny, int _nz);

    /**
     * @brief Destrutor da classe Sculptor.
     *
     * Libera a memória alocada para a matriz 3D.
     */
    ~Sculptor();

    /**
     * @brief Define a cor e a transparência para os próximos voxels ativados.
     *
     * @param r Valor do vermelho (0 a 1).
     * @param g Valor do verde (0 a 1).
     * @param b Valor do azul (0 a 1).
     * @param a Valor da transparência (0 a 1).
     */
    void setColor(float r, float g, float b, float a);

    /**
     * @brief Ativa um voxel em uma posição específica.
     *
     * @param x Coordenada x.
     * @param y Coordenada y.
     * @param z Coordenada z.
     */
    void putVoxels(int x, int y, int z);

    /**
     * @brief Desativa um voxel em uma posição específica.
     *
     * @param x Coordenada x.
     * @param y Coordenada y.
     * @param z Coordenada z.
     */
    void cutVoxels(int x, int y, int z);

    /**
     * @brief Ativa todos os voxels em um intervalo definido.
     *
     * @param x0 Início do intervalo no eixo x.
     * @param x1 Fim do intervalo no eixo x.
     * @param y0 Início do intervalo no eixo y.
     * @param y1 Fim do intervalo no eixo y.
     * @param z0 Início do intervalo no eixo z.
     * @param z1 Fim do intervalo no eixo z.
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

    /**
     * @brief Desativa todos os voxels em um intervalo definido.
     *
     * @param x0 Início do intervalo no eixo x.
     * @param x1 Fim do intervalo no eixo x.
     * @param y0 Início do intervalo no eixo y.
     * @param y1 Fim do intervalo no eixo y.
     * @param z0 Início do intervalo no eixo z.
     * @param z1 Fim do intervalo no eixo z.
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

    /**
     * @brief Ativa todos os voxels que satisfazem a equação de uma esfera.
     *
     * @param xcenter Coordenada x do centro da esfera.
     * @param ycenter Coordenada y do centro da esfera.
     * @param zcenter Coordenada z do centro da esfera.
     * @param radius Raio da esfera.
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);

    /**
     * @brief Desativa todos os voxels que satisfazem a equação de uma esfera.
     *
     * @param xcenter Coordenada x do centro da esfera.
     * @param ycenter Coordenada y do centro da esfera.
     * @param zcenter Coordenada z do centro da esfera.
     * @param radius Raio da esfera.
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    /**
     * @brief Ativa todos os voxels que satisfazem a equação de uma elipsoide.
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
     * @brief Desativa todos os voxels que satisfazem a equação de uma elipsoide.
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
     * @param filename Nome do arquivo onde a escultura será salva.
     */
    void writeOFF(const std::string &filename);
};

#endif // SCULPTOR_H
