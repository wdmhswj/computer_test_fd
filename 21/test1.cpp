#include <climits>
#include <iostream>
#include <vector>

int main(){
    // 读取城市数目
    int n;
    std::cin>>n;

    // 读取2D数组
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX));
    int tmp=-1;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            std::cin>>tmp;
            if (i==j) {
                dist[i][j]=0;
                continue;
            }
            if (tmp>0) {
                dist[i][j]=tmp;
            }
        }
    }

    // 使用Floyd算法，求任意两点之间的最短路
    for(int k=0; k<n; ++k) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(dist[i][k]<INT_MAX && dist[k][j]<INT_MAX && dist[i][k]+dist[k][j]<dist[i][j]) {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    int min_dis =INT_MAX;   // 路径的最小值
    int city=0;
    for(int i=0; i<n; ++i) {
        int max_dis_to_i = 0;   // 到i点的最远的距离
        for(int j=0; j<n; ++j) {
            if(i==j) continue;
            max_dis_to_i = std::max(max_dis_to_i, dist[j][i]);
        }
        if(max_dis_to_i<min_dis) {
            min_dis=max_dis_to_i;
            city=i;
        }
    }
    std::cout<<city;
    return 0;
}