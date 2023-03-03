#include <iostream>
using namespace std;

typedef struct Ponto{
    float x;
    float y;
} tPonto;

float calcule(const tPonto p1, const tPonto p2){
    float dist;
    dist = ((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y));
    
    return dist;
}

int argmin(const float dists[], int t){
    float c_dist = dists[0];
    int min_idx = 0;
    for(int i=1; i<t; i++){
        if (dists[i] < c_dist){
            c_dist = dists[i];
            min_idx = i;
        }
            
    }
    return min_idx;
}

int main()
{
    tPonto ponto1;
    int others;
    
    cin >> ponto1.x;
    cin >> ponto1.y;
    cin >> others;
    
    tPonto plano[others];
    float distances[others];
    
    
    
    for(int i=0; i<others; i++){
        cin >> plano[i].x;
        cin >> plano[i].y;
        distances[i] = calcule(ponto1 ,plano[i]);
    }
    
    tPonto min_point = plano[argmin(distances, others)];
    
    cout << "Ponto mais perto é (" << min_point.x << ", "<< min_point.y << ")" << endl; 
     
    
    return 0;
}