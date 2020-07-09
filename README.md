# HTU21D Micropython ESP32

This is a micropython library to measure humidity & temperature data from the htu21d sensor on ESP32

## Example

This code works on ESP32 and it should be the same for ESP8266.

As the ESP32 has the I2C pins in SCL=22 and SDA=21, you should connect the sensor pins in the same way,  here is an example of how to make it run once the library has been charged to the microcontroller:

```python
lectura = HTU21D(22,21)
hum = lectura.humidity
temp = lectura.temperature
print('Humedad: ', + hum)
print('Temperatura: ', + temp)
```
