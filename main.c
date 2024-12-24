#include <stdio.h>
#include <string.h>
 float similar_text(char *words1 , char *words2);// similar text fonksiyonu prototip
 int dosya_islemleri(); //dosya_islemleri fonksiyonu prototip
int main() {
 char kelime1[20];//En fazla 20 karakterli (harf dizisi)
 char kelime2[200][20];//En fazla 20 karakterli 200 tane kelime (kelime dizisi)
 char benzeyen_kelime[20];// En fazla 20 karakterli kelime
 int sayac=0;// sayac tanımlanıyor
  // Aranmak istenen kelime kullanıcıdan alınıyor.
  printf("Aramak isteginiz kelimeyi giriniz:");
  scanf("%s",&kelime1);

  // Words.txt dosyası bellekte ayırdığımız dosya adlı yere açılıyor. Words.txt dosyasındaki kelimeler kelime2 dizisinin içine aktarılıyor.
  // Sonrasında fonksiyonun kelime sayısını döndürüyor. Bu değeri de sayac değişkinine aktarıyor.

 sayac=dosya_islemleri( "C:\\Users\\90546\\words.txt", kelime2 );
 // Buradaki Dosya konumunu Kendi bilgisayrınızdaki Word.txt dosyasının adresini yazınınz

 // For döngüsünün içinde tanımladığımız similar_text fonksiyonu çalışıyor.
 // Klavyeden girdiğimiz kelimeyi kelime2 dizisindeki elemanlarla karşılaştırıyor.
 // İf koşulu sayesinde her bir karşılaştırmadan sonra kıyaslama yapılıyor.
 // Kıyaslama esnasında çok benzeyen kelime strcpy fonksiyonu ile benzeyen_kelime değişkenine aktarılıyor.
 // Ve similar_text fonksiyonunda dönen eşleşme değeri de enfazla_eslesme değişkenine aktarılıyor.
  double enfazla_uyusma=0.0;
  for(int i=0;i<sayac;i++) {
   float uyusma = similar_text(kelime1,kelime2[i]);
   if (uyusma>enfazla_uyusma) {
    enfazla_uyusma=uyusma;
    strcpy(benzeyen_kelime,kelime2[i]);// Eslenen kelime benzeyen kelimeye kopyalanıyor
   }
  }
  // Eşleşme oranı 0 dan büyük ise bulunan kelime ile Eşlenme oranı yazdırılıyor.
  // 0 dan büyük değil ise ekrana Eslesme yok yazdırılıyor.
  if (enfazla_uyusma>0) {
   printf("Bunu Demek Istediniz:%s  Benzerlik Orani:(%.2f) \n ",benzeyen_kelime,enfazla_uyusma);
  }
  else {
   printf("No matching(Eslesme yok)\n ");
  }
  return 0;

}

// similar_text fonksiyonu verilen iki char dizisindeki harfleri kıyaslar ve benzeme oranı döndürür.

float similar_text(char *words1, char *words2 ) {
 int gecici;
// Verilen iki paremetrenin kaç harften oluştuğu strlen komutuyla hesaplanıyor.
 int uzunluk1=strlen(words1);
 int uzunluk2=strlen(words2);

 // Kısa olan kelime belirleniyor ve uzunluğu gecici değişkenine aktarılıyor.
 if(uzunluk1>uzunluk2) {
  gecici=uzunluk2;
 }
 else {
  gecici=uzunluk1;
 }
 //Girilen 2 char karakter dizisinin harflerini , for döngüsü içerisinde karşılaştırıyor.
 // Eşleşen her harf için ayni_kelime değişkeni bir artıyor.
 // En son fonksiyon eşleşme oranına dönüyor.
 int ayni_kelime=0;
 for(int i=0;i<gecici;i++) {
  if (words1[i] == words2[i]) {
   ayni_kelime++;
  }
 }

 return (float)ayni_kelime/uzunluk2;
}

// Dosya işlemleri fonksiyonu
// Fopen komutuyla dosya açılıyor ve içindeki veriler okunuyor.
// Dosyanın içindeki kelimeler veriye yazdırılıyor.
int dosya_islemleri(char *filename , char veri[100][20]) {
 FILE *dosya = fopen(filename,"r");
 if(dosya==NULL) { // Dosya açma işlemi başarısız ise aşağıdaki işlemler uygulanıyor
  printf("Dosya acma islemi basarisiz oldu");
 }
 int sayac=0;
 while(!feof(dosya)) { // Dosyanın son kelimesine gelesiye kadar döngü devam ediyor
  fscanf(dosya,"%s",veri[sayac]);
  sayac++;
 }
 fclose(dosya);// Dosya kapatılıyor
return sayac; // Sayac döndürülüyor

}