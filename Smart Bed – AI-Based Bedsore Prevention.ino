#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define NUM_ROWS 4
#define NUM_COLS 4

// FSR Matrix pins (example GPIO pins)
const int fsrPins[NUM_ROWS][NUM_COLS] = {
  {32, 33, 34, 35},
  {25, 26, 27, 14},
  {12, 13, 15, 2},
  {4, 5, 18, 19}
};

Adafruit_MPU6050 mpu;

float pressureThreshold = 500;  // Threshold for high pressure (adjust as needed)
float motionThreshold = 1.5;    // Threshold for significant motion (accelerometer)

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("Smart Bed – Bedsore Prevention System Starting...");

  // Initialize FSR pins
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      pinMode(fsrPins[r][c], INPUT);
    }
  }

  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("MPU6050 Initialized");
}

void loop() {
  // Read FSR matrix values
  int maxPressure = 0;
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      int val = analogRead(fsrPins[r][c]);
      if (val > maxPressure) maxPressure = val;
    }
  }

  // Read IMU data
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float accMagnitude = sqrt(a.acceleration.x * a.acceleration.x +
                            a.acceleration.y * a.acceleration.y +
                            a.acceleration.z * a.acceleration.z);

  Serial.print("Max Pressure: ");
  Serial.print(maxPressure);
  Serial.print(" | Acceleration Magnitude: ");
  Serial.println(accMagnitude);

  // Simple bedsore risk detection logic
  if (maxPressure > pressureThreshold && accMagnitude < motionThreshold) {
    Serial.println("ALERT: High bedsore risk detected! Patient immobile under high pressure.");
    // TODO: Send alert via Wi-Fi / cloud / buzzer / caregiver notification
  } else {
    Serial.println("Patient status normal.");
  }

  delay(2000);
}
