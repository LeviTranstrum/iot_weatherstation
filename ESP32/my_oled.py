from machine import Pin, SoftI2C
import ssd1306
import gfx
from time import sleep

i2c = SoftI2C(scl=Pin(22), sda=Pin(21))

oled_width = 128
oled_height = 64
oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)
graphics = gfx.GFX(oled_width, oled_height, oled.pixel)

def print_welcome_screen():
    oled.fill(0)
    oled.text("EGR 314 Team 304", 0, 0)
    oled.text("Trent Packer",0,10)
    oled.text("Cayman Preston",0,20)
    oled.text("Brendon Salido",0,30)
    oled.text("Levi Transtrum",0,40)
    oled.text("Welcome!", 32, 54)
    oled.show()

    
def print_data(msg, x):
    print("print_data was called")
    my_string = msg.decode('utf-8') # or my_string = str(msg, 'utf-8')
    my_strings = my_string.split(" ")
    my_values = [float(item) for item in my_strings]
    oled.fill(0)
    for ii, item in enumerate(my_values):
        oled.text(str(item), x, 10*ii)
    oled.show()
    pass

def print_sensor_data(temp, hum):
    oled.fill(0)
    oled.text("EGR 314 Team 304", 0, 0)
    
    oled.text("Temp:", 0, 20)
    oled.text(str(temp), 64, 20)
    oled.text("C", 118, 20)

    oled.text("RH:", 0, 30)
    oled.text(str(hum), 64, 30)
    oled.text("%", 118, 30)
    oled.show()
    pass

def plot_data(msg):
    print("plot_data was called")
    my_string = msg.decode('utf-8') # or my_string = str(msg, 'utf-8')
    my_strings = my_string.split(" ")
    my_values = [float(item) for item in my_strings]
    max_val = max(my_values)
    
    oled.fill(0)
    oled.text(str(max(my_values)), 64, 0)
    oled.text(str(min(my_values)), 64, 54)
    
    for i in range(len(my_values)-1):
        i+=1
        graphics.line((i-1)*128//(len(my_values)-1), 64-int(64*my_values[i-1]/max_val), i*128//(len(my_values)-1), 64-int(64*my_values[i]/max_val), 1)
        oled.show()
