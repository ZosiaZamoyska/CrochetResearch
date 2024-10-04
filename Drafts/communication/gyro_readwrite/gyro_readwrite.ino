#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps612.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

MPU6050 mpu;

#define OUTPUT_READABLE_YAWPITCHROLL
#define INTERRUPT_PIN 2
#define LED_PIN 13

volatile bool mpuInterrupt = false;
void dmpDataReady() {
  mpuInterrupt = true;
}

bool dmpReady = false;
uint8_t mpuIntStatus;
uint8_t devStatus;
uint16_t packetSize;
uint16_t fifoCount;
uint8_t fifoBuffer[64];
const int buttonPin = 4;
bool startStitch = true;
Quaternion q;
VectorFloat gravity;
float ypr[3];

unsigned long startTime;

void setup() {
  Wire.begin();
  Wire.setClock(400000);

  Serial.begin(9600);
  while (!Serial);

  pinMode(buttonPin, INPUT);

  Serial.println(F("Initializing I2C devices..."));
  mpu.initialize();
  pinMode(INTERRUPT_PIN, INPUT);

  //Serial.println(F("Testing device connections..."));
  //Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

  //Serial.println(F("\nSend any character to begin DMP programming and demo: "));
  //while (Serial.available() && Serial.read());
  //while (!Serial.available());
  //while (Serial.available() && Serial.read());

  Serial.println(F("Initializing DMP..."));
  devStatus = mpu.dmpInitialize();

  mpu.setXGyroOffset(51);
  mpu.setYGyroOffset(8);
  mpu.setZGyroOffset(21);
  mpu.setXAccelOffset(1150);
  mpu.setYAccelOffset(-50);
  mpu.setZAccelOffset(1060);

  if (devStatus == 0) {
    mpu.CalibrateAccel(6);
    mpu.CalibrateGyro(6);
    Serial.println();
    mpu.PrintActiveOffsets();
    //Serial.println(F("Enabling DMP..."));
    mpu.setDMPEnabled(true);

    //Serial.print(F("Enabling interrupt detection (Arduino external interrupt "));
    //Serial.print(digitalPinToInterrupt(INTERRUPT_PIN));
    //Serial.println(F(")..."));
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();

    Serial.println(F("DMP ready! Waiting for first interrupt..."));
    dmpReady = true;
    packetSize = mpu.dmpGetFIFOPacketSize();
  } else {
    Serial.print(F("DMP Initialization failed (code "));
    //Serial.print(devStatus);
    //Serial.println(F(")"));
  }

  startTime = millis();
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  if (!dmpReady) return;

  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
    unsigned long currentTime = millis();

#ifdef OUTPUT_READABLE_YAWPITCHROLL
    
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

    char buffer[100];
    dtostrf(currentTime, 10, 0, buffer);
    //Serial.print(buffer);
    Serial.print("\t");

    dtostrf(ypr[0] * 180 / M_PI, 7, 2, buffer);
    Serial.print(buffer);
    Serial.print("\t");

    dtostrf(ypr[1] * 180 / M_PI, 7, 2, buffer);
    Serial.print(buffer);
    Serial.print("\t");

    dtostrf(ypr[2] * 180 / M_PI, 7, 2, buffer);
    Serial.print(buffer);
    if (startStitch == true)
    {
      Serial.print("\tstart\n");
      startStitch = false;
    }
    Serial.print("\n");
     
    delay(100);
#endif

    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
