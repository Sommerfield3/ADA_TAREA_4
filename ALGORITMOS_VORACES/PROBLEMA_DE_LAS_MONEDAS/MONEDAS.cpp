#include <bits/stdc++.h>
using namespace std;
int monedasMin(vector<float> monedas,float cambio){
  if(cambio<=0){
    cout<<"No es posible calcular el cambio."<<endl;
    return 0;
  }
  sort(monedas.begin(), monedas.end(), greater<int>());
  int cantMonedas=0;
  int cambioAux=cambio;
  for(int i=0;i<monedas.size();i++){
    if(int(cambioAux/monedas[i])>0){
      cantMonedas+=int(cambioAux/monedas[i]);
      cambioAux-=monedas[i]*int(cambioAux/monedas[i]);
    }
  }
  return cantMonedas;
}
int main() {
  vector<float> monedasCent;
  float dineroTotal=5;
  float pago=1.11;
  float cambio=dineroTotal-pago;
  float cambioCent=cambio*100;//Agilizando
  monedasCent={200,100,50,20,10,5,2,1};
  int cantidad_Monedas=monedasMin(monedasCent,cambioCent);
  if(cantidad_Monedas==0){
    cout<<"No es posible calcular el cambio con las monedas disponibles."<<endl;
    return 0;
  }
  cout<<"La cantidad mínima de monedas del grupo disponible a usar para dar un cambio de "<<cambio<<" euros de un total de "<<dineroTotal<< " euros es: "<<cantidad_Monedas<<endl;
  return 0;
}