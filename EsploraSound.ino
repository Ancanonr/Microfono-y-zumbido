/ Pines
int pirPin = 2;  // Pin al que está conectado el sensor PIR
int ledPin = 13; // Pin del LED (puede ser el LED integrado)

// Variable para almacenar el estado del sensor
int pirState = LOW;

void setup() {
  pinMode(pirPin, INPUT);  // El PIR es una entrada
  pinMode(ledPin, OUTPUT); // El LED es una salida
  
  Serial.begin(9600);      // Iniciar la comunicación serial
}

void loop() {
  // Leer el estado del sensor PIR
  pirState = digitalRead(pirPin);
  
  // Si detecta movimiento, encender el LED
  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("ON");  // Enviar estado 'ON' por el puerto serial
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("OFF"); // Enviar estado 'OFF' por el puerto serial
  }
  
  delay(100);  // Pequeño retraso para no saturar el puerto serial
}
import processing.serial.*;  // Importar la librería de comunicación serial

Serial myPort;               // Variable para el puerto serial
String val;                  // Variable para almacenar los datos recibidos

void setup() {
  size(200, 200);            // Tamaño de la ventana
  
  // Listar todos los puertos disponibles
  println(Serial.list());
  
  // Abrir el puerto serial que usa Arduino (ajustar el número según tu puerto)
  myPort = new Serial(this, Serial.list()[0], 9600);
  
  // Ajuste para lectura de datos
  myPort.bufferUntil('\n');
}

void draw() {
  background(255);           // Fondo blanco
  
  // Si el valor recibido es 'ON', mostrar un círculo verde (LED encendido)
  if (val != null && val.trim().equals("ON")) {
    fill(0, 255, 0);         // Verde
  } else {
    fill(255, 0, 0);         // Rojo
  }
  
  // Dibujar un círculo en el centro de la ventana
  ellipse(width/2, height/2, 100, 100);
}

void serialEvent(Serial myPort) {
  // Leer los datos enviados por el puerto serial
  val = myPort.readStringUntil('\n');
  val = trim(val);  // Quitar espacios en blanco
}
