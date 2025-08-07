int POT = 34;                      // Pin de Entrada Analógica - 12 Bits, que equivalen a un número variable entre 0 - 4095
int LED = 25;                      // Pin de Salida Analógica - 8 bits, que equivalen a un número variable entre 0 - 255
int BRILLO = 0;                   // Variable que almacenará el valor del potenciómetro y lo pasará a un número entre 0 - 255

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  BRILLO = analogRead(POT)/16;    // BRILLO tomará un valor equivalente de 0-4095 y lo pasará a un número entre 0-255
  Serial.println(BRILLO);
  delay(1000);
  dacWrite(LED, BRILLO);   // Con esta función en el PIN 25 (Salida Analógica) envío un valor entre 0-255 equivalente al giro del Potenciómetro 
}
