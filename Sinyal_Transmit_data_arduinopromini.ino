/*===============================================
 * title    : Program Uji Rangkaian Instrumentasi 
 * kelas    : 2D3 ELKA A
 * smt      : Gasal 2019/2020
 * board    : Arduino Pro Mini 
 * adc      : internal 5V
 * com      : serial 9600bps-N-8-1
=================================================*/
/*Define here*/
#define   LM35  A0

/*Deklarasi Variabel*/
unsigned int adc0;
float        vin, Vlm35, Temp;

void setup() {
  // put your setup code here, to run once:
  /*Konfigurasi ADC*/
  analogReference(DEFAULT);

  /*Konfigurasi Komunikasi Serial*/
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*Baca data ADC dan konversi ke dalam bentuk tegangan*/
  adc0=analogRead(A0);
  vin=(float)adc0/1024*5.0;
  /*Konversi vout ke tegangan keluaran LM35*/
  Vlm35=(vin/2.702)-0.35;   //vin=1.85 * 2.7 - 0.35 = 5v
  /*Konversi keluaran LM35 ke bentuk SUHU (degC)*/
  Temp=Vlm35*100;        //Temp = 1.50 * 100 = 150 deg
  /*Kirim data ke serial --> Virtual Terminal*/
  Serial.println("==================================");
  Serial.println("Temperature Monitoring dengan EWS");
  Serial.println("NAMA = FAHMI MASHURI");
  Serial.println("NRP  = 1103181001");
  Serial.print("ADC = ");
  Serial.println(adc0,DEC); //Serial.println(adc0,DEC);
  Serial.print("VOut = ");
  Serial.println(vin);
  Serial.print("Vtemp = ");
  Serial.println(Vlm35);
  Serial.print("TEMP = "); Serial.println(Temp);
  Serial.println("RELAY = ON");
 /* if(digitalRead(13) == HIGH){
    Serial.println("RELAY = ON");
  }else{
    Serial.println("RELAY = OFF");
  }*/
  Serial.println("==================================");
  delay(100);
}
