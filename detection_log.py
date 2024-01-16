import serial
import time
from csv import *

chemin = "detection_log.csv"
colonnes = ["trace_temps",
            "detecteur_1",
            "detecteur_2",
            "detecteur_3",
            "bouton",
            "alarm_status"]

ser = serial.Serial(port='COM4', baudrate=9600, timeout=1) # Spécification du canal de communication ('COM4') 

def obtenir_temp():
    temps_courant = time.gmtime()
    temps_format = time.strftime("%m/%d %H:%M:%S", temps_courant)
    return temps_format

def ecriture_csv():
    with open(chemin, 'w', newline="") as f:
        write = DictWriter(f, delimiter=",", fieldnames=colonnes)
        write.writeheader()

        while True:
            data = ser.readline().decode('utf-8').strip() # Récupération des données des Pins à partir du Arduino Serial
            if data:
                data = data.split(",")
                print(data)
                if(len(data) > 4 and data[-1] == "1"): # Vérifier si le Mouvement/Alarme a été activé (data[-1] == 1)
                    write.writerow({"trace_temps": obtenir_temp(),
                                    "detecteur_1": data[0], 
                                    "detecteur_2": data[1],
                                    "detecteur_3": data[2],
                                    "bouton": data[3],
                                    "alarm_status": data[4]})
            time.sleep(0.01) 


ecriture_csv()


