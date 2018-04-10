/*
  Function.cpp
  Implementasi Fungsi-fungsi yang sebelumnya sudah dideklarasi
*/

#include "Arduino.h"
#include "Function.h"

//Fungsi buat menghidupkan lampu built in
void Function::on ()
{
  digitalWrite (13, HIGH);
}

//Fungsi buat mematikan lampu built in
void Function::off ()
{
  digitalWrite (13, LOW);
}

//Fungsi buat bikin lampu kedap-kedip dengan delay
void Function::delay (string pilihan)
{
  _pilihan = pilihan;
  _idx = _pilihan.indexOf(" ");     //Mencari lokasi "spasi" pada string "delay x" atau "d x"
  _pilihan = _pilihan.substring(_idx+1);      //Memotong string pilihan, di ambil bagian yang ada angkanya (hanya mengambil x)
  _waktuDelay = _pilihan.toInt();     //Mengubah string menjadi integer
  
  //Kedipan hanya terlihat ketika lampu menyala dan delay tidak sama dengan nol
  //asumsi input User pada delay selalu >=0 (tidak bisa negatif)
  if (digitalRead(13) == HIGH) {
    if (_waktuDelay == 0) {
      digitalWrite (13, HIGH);
    }
    else {
      digitalWrite (13, LOW);
      delay (_waktuDelay);
      digitalWrite (13, HIGH);
      delay (_waktuDelay);
    }
  }
  else if (digitalRead(13) == LOW) {
    digitalWrite (13, LOW);
  }
}
