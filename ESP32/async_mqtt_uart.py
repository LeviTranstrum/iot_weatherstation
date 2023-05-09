# Derived from: 
# * https://github.com/peterhinch/micropython-async/blob/master/v3/as_demos/auart.py
# * https://github.com/tve/mqboard/blob/master/mqtt_async/hello-world.py


from mqtt_async import MQTTClient, config
import uasyncio as asyncio
import time
from machine import UART
from machine import Pin
import my_oled
import logging
logging.basicConfig(level=logging.DEBUG)

MAXTX = 4

# Change the following configs to suit your environment
TOPIC_PUB_TEMP = 'EGR314/Team304/Temperature'
TOPIC_PUB_HUM = 'EGR314/Team304/Humidity'
TOPIC_PUB_MENU = 'EGR314/Team304/Menu'
TOPIC_PUB_FAN = 'EGR314/Team304/FanSpeed'

TOPIC_SUB = 'EGR314/Team304/FanSet'
MENU = 1
config.server = 'egr3x4.ddns.net' # can also be a hostname
config.ssid     = 'Levi'
config.wifi_pw  = 'FunkyFresh'
data = []

uart = UART(2, 9600,tx=16,rx=17)
uart.init(9600, bits=8, parity=None, stop=1,flow=0) # init with given parameters
led = Pin(2,Pin.OUT)

async def receiver():
    global MENU
    b = b''
    temp = 0
    hum = 0
    sreader = asyncio.StreamReader(uart)
    while True:
        res = await sreader.read(1)      
        if res==b't': # If you get a temperature reading...
            await client.publish(TOPIC_PUB_TEMP, b, qos=1) #Publish it
            temp = b
            b = b''
        elif res==b'h': # If you get a humidity reading...
            await client.publish(TOPIC_PUB_HUM, b, qos=1)
            hum = b
            b = b''
        elif res==b'm': # If you get a menu reading...
            await client.publish(TOPIC_PUB_MENU, b, qos=1)
            MENU = b
            b = b''
        elif res==b'f': # If you get a fan reading...
            await client.publish(TOPIC_PUB_FAN, b, qos=1)
            #print('published', b)
            b = b''
        elif res==b'w': # If you get a welcome screen command...
            my_oled.print_welcome_screen()
            b = b''        
        else:
            b+=res
            
        if MENU == b'1':
            my_oled.print_welcome_screen()
        else:
            my_oled.print_sensor_data(temp, hum) # Print it    


def callback(topic, msg, retained, qos):
    print('callback',topic, msg, retained, qos)
    while (msg):
        msg = msg.decode()
        msg = int(msg)
        msg = bytearray([msg])
        uart.write(msg)
        time.sleep(.01)
        msg = 0
        
        # toggle the onboard LED
        led.value(led.value()^1)

    # uart.write('\r\n')
    time.sleep(.01)
  
async def conn_callback(client): await client.subscribe(TOPIC_SUB, 1)

async def main(client):
    await client.connect()
    asyncio.create_task(receiver())
    while True:
        await asyncio.sleep(1)

config.subs_cb = callback
config.connect_coro = conn_callback

client = MQTTClient(config)
loop = asyncio.get_event_loop()
loop.run_until_complete(main(client))
