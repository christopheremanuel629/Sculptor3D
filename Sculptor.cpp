#include "Sculptor.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

 using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    this -> nx = _nx;
    this -> ny = _ny;
    this -> nz = _nz;
    this -> r = 0;
    this -> g = 0;
    this -> b = 0;
    this -> a = 0;

    v = new Voxels**[nx];
    for(int i = 0; i < nx; i++){

        v[i] = new Voxels*[ny];
        for(int j = 0; j < ny; j++){

            v[i][j] = new Voxels[nz];
            for(int k = 0; k < _nz; k++){

                this -> v [i][j][k].r = 0;
                this -> v [i][j][k].g = 0;
                this -> v [i][j][k].b = 0;
                this -> v [i][j][k].a = 0;
                this -> v [i][j][k].show = false;
            }
        }
    }
}

Sculptor::~Sculptor()
{
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
}
void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r = r;
    this->g = g;
    this->b = b ;
    this->a = alpha;
}

void Sculptor::putVoxels(int x, int y, int z){

    this -> v[x][y][z].r = this -> r;
    this -> v[x][y][z].g = this -> g;
    this -> v[x][y][z].b = this -> b;
    this -> v[x][y][z].a = this -> a;
    this -> v[x][y][z].show = true;

}

void Sculptor::cutVoxels(int x, int y, int z){

    this -> v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    x0 = (x0 < 0) ? 0 : x0;
    x1 = (x1 > this -> nx) ? this -> nx  : x1;
    y0 = (y0 < 0) ? 0 : y0;
    y1 = (y1 > this -> ny) ? this -> ny  : y1;
    z0 = (z0 < 0) ? 0 : z0;
    z1 = (z1 > this -> nz) ? this -> nz  : z1;

    for(int i = x0; i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            for(int k = z0; k <= z1; k++){
                this -> putVoxels(i, j, k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            for(int k = z0; k <= z1; k++){
                if (i >= 0 && i < nx && j >= 0 && j < ny && k >= 0 && k < nz) {
                v[i][j][k].show = false;
            }
        }
    }
}
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    putEllipsoid (xcenter, ycenter, zcenter, radius, radius, radius);
                }

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  cutEllipsoid (xcenter, ycenter, zcenter, radius, radius, radius);
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    int x0 = (xcenter - rx < 0)  ? 0 : xcenter - rx;
    int x1 = (xcenter + rx > this -> nx ) ? this -> nx : xcenter +rx;
    int y0 = (ycenter - ry < 0)  ? 0 : ycenter - ry;
    int y1 = (ycenter + ry > this -> ny ) ? this -> ny : ycenter +ry;
    int z0 = (zcenter - rz < 0)  ? 0 : zcenter - rz;
    int z1 = (zcenter + rz > this -> nz ) ? this -> nz : zcenter +rz;

    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1; k++){
                    if(pow( i - xcenter, 2) / pow(rx,2) + pow(j - ycenter, 2) / pow(ry, 2) + pow(k - zcenter, 2) / pow(rz,2) < 1) {
                    this -> putVoxels(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    int x0 = (xcenter - rx < 0)  ? 0 : xcenter - rx;
    int x1 = (xcenter + rx > this -> nx ) ? this -> nx : xcenter +rx;
    int y0 = (ycenter - ry < 0)  ? 0 : ycenter - ry;
    int y1 = (ycenter + ry > this -> ny ) ? this -> ny : ycenter +ry;
    int z0 = (zcenter - rz < 0)  ? 0 : zcenter - rz;
    int z1 = (zcenter + rz > this -> nz ) ? this -> nz : zcenter +rz;

    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1; k++){
                    if(pow( i - xcenter, 2) / pow(rx,2) + pow(j - ycenter, 2) / pow(ry, 2) + pow(k - zcenter, 2) / pow(rz,2) < 1) {
                    this -> cutVoxels(i, j, k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const std::string &filename) {
    std::cout << "Salvando o arquivo OFF com o nome: " << filename << std::endl;

    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo OFF: " << filename << std::endl;
        return;
    }

    file << "OFF" << std::endl;

    int countVoxels = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show ) {
                    countVoxels++;
                }
            }
        }
    }

    file << countVoxels * 8 << " " << countVoxels * 6 << " 0" << std::endl;
    file << std::fixed << std::setprecision(2);

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    file << i << " " << j << " " << k << std::endl;
                    file << i << " " << j + 1 << " " << k << std::endl;
                    file << i + 1 << " " << j + 1 << " " << k << std::endl;
                    file << i + 1 << " " << j << " " << k << std::endl;
                    file << i << " " << j << " " << k + 1 << std::endl;
                    file << i << " " << j + 1 << " " << k + 1 << std::endl;
                    file << i + 1 << " " << j + 1 << " " << k + 1 << std::endl;
                    file << i + 1 << " " << j << " " << k + 1 << std::endl;

                }
            }
        }
    }

    int voxelsIndex = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    int baseIndex = voxelsIndex * 8;
                    file << "4 " << baseIndex << " " << baseIndex + 1 << " " << baseIndex + 2 << " " << baseIndex + 3
                         << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    file << "4 " << baseIndex + 4 << " " << baseIndex + 5 << " " << baseIndex + 6 << " " << baseIndex + 7
                         << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    file << "4 " << baseIndex << " " << baseIndex + 3 << " " << baseIndex + 7 << " " << baseIndex + 4
                         << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    file << "4 " << baseIndex + 1 << " " << baseIndex + 2 << " " << baseIndex + 6 << " " << baseIndex + 5
                         << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    file << "4 " << baseIndex + 3 << " " << baseIndex + 2 << " " << baseIndex + 6 << " " << baseIndex + 7
                         << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    file << "4 " << baseIndex << " " << baseIndex + 1 << " " << baseIndex + 5 << " " << baseIndex + 4
                         << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    voxelsIndex++;
                }
            }
        }
    }

    file.close();
    std::cout << "Finalizado a escrita do objeto no arquivo: " << filename << std::endl;
}


