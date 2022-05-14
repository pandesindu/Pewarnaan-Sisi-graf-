#include<iostream>
using namespace std;
void pewarnaanSisiGrafLengkap(int ed[][3], int e) {
   int i, c, j;
   for(i = 0; i < e; i++) {
      
      c = 1; 
      flag:
         ed[i][2] = c;
         // Jika warna yang sama ditempati oleh salah satu sisi yang berdekatan,
         //  maka warna yang sekarang tidak dipakai dan 
         // program kembali ke flag untuk mengambil warna baru dan melanjutkan proses.
         for(j = 0; j < e; j++) {
            if(j == i)
               continue;
               if(ed[j][0] == ed[i][0] || ed[j][0] == ed[i][1] || ed[j][1] == ed[i][0] || ed[j][1] == ed[i][1]) {
                  if(ed[j][2] == ed[i][2]) {
                     c++;
                     goto flag;
                  }
               }
         }
   }
}
int main() {
   int i, node, jmlSisi, j, cnt = 0; // deklarasi variabel
   cout<<"masukan banyaknya titik graf anda: ";
   cin>>node;
   jmlSisi = (node*(node-1))/2; //jumlah sisi yang diberi warna yang sama  
   
   int ed[jmlSisi][3];
   for(i = 1; i <= node; i++) {
      for(j = i+1; j <= node; j++) {
         ed[cnt][0] = i;
         ed[cnt][1] = j;
         ed[cnt][2] = -1;
         cnt++;
         cout<<"sisi pada graf "<<ed[cnt-1][0]<<" "<<ed[cnt-1][1]<<" "<<endl;
      }
   }
   
   pewarnaanSisiGrafLengkap(ed ,jmlSisi);
   for(i = 0; i < jmlSisi; i++)
      cout<<"\n warna yang menghubungkan sisi :"<<ed[i][0]<<" dan sisi "<<ed[i][1]<<" adalah warna "<<ed[i][2]<<".";
}