#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cmath>

using namespace std;

int main(){

srand(time(NULL));

int a = 2; 
double result = 100000;
pair<int, int> arr[] = {
    {1351, 565},
    {1347, 565}

};

cout << a << endl;
/*
for (int i = 0; i < a; i++){
    int x,y;
    x= 100 + rand() % (1001);
    y= 100 + rand() % (1001);

    arr[i].first = x;
    arr[i].second = y;

}
*/
for (int i = 0; i < a; i++){
    for ( int j = 0; j < a; j++){
        pair <int,int> menor;
        pair <int,int> mayor;
        int cat1, cat2;
        double hypo;

        if(i==j){
            continue;
        }

        //En caso que ambos puntos tengan el mismo valor en X
        if(arr[i].first == arr[j].first){
            if(arr[i].second > arr[j].second){
                hypo = arr[i].second - arr[j].second;
            }else{
                hypo = arr[j].second - arr[i].second;
            }
            if(hypo < result){
                result = hypo;
            }
        }
        //En caso que ambos puntos tengan el mismo valor en Y
        if(arr[i].second == arr[j].second){
            if(arr[i].first > arr[j].first){
                hypo = arr[i].first - arr[j].first;
            }else{
                hypo = arr[j].first - arr[i].first;
            }
            if(hypo < result){
                result = hypo;
            }
        }
        //En caso de que uno de los puntos tenga ambas coordenadas mayores al otro
        if(arr[i].first < arr[j].first && arr[i].second < arr[j].second || arr[i].first > arr[j].first && arr[i].second > arr[j].second){
            if(arr[i].first < arr[j].first){
                menor.first = arr[i].first;
                menor.second = arr[i].second;
                mayor.first = arr[j].first;
                mayor.second = arr[j].second;
            }else{
                menor.first = arr[j].first;
                menor.second = arr[j].second;
                mayor.first = arr[i].first;
                mayor.second = arr[i].second;
            }
            cat1 = mayor.first - menor.first;
            cat2 = mayor.second - menor.second;
            hypo = (cat1*cat1) + (cat2*cat2);
            hypo = sqrt(hypo);
            if (result > hypo){
                result = hypo;
            }
        }
        
        //En caso que ambos puntos tengan solo una coordenada mayor que el otro
        if(arr[i].first < arr[j].first && arr[i].second > arr[j].second || arr[i].first > arr[j].first && arr[i].second < arr[j].second){
            if(arr[i].first<arr[j].first){
                menor.first = arr[i].first;
                mayor.first = arr[j].first;
            }else{
                menor.first = arr[j].first;
                mayor.first = arr[i].first;
            }
            if(arr[i].second<arr[j].second){
                menor.second = arr[i].second;
                mayor.second = arr[j].second;
            }else{
                menor.second = arr[j].second;
                mayor.second = arr[i].second;
            }
            cat1 = mayor.first - menor.first;
            cat2 = mayor.second - menor.second;
            hypo = (cat1*cat1) + (cat2*cat2);
            hypo = sqrt(hypo);
            if (result > hypo){
                result = hypo;
            }
        }
        
    }
}

cout<<"la menor distancia entre puntos es:"<< result <<endl;

}