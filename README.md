
## Système de Détection de Mouvement avec Arduino basée sur les capacités C++ et Python, visant à valider le module d'Architecture des Ordinateurs pour l'année universitaire 2023/2024.

![image](https://github.com/ZahraneRabhi/Smart-Camping/assets/88408227/974acf33-38a4-4561-9cf1-626b84329e03)
---
Ce projet met en œuvre un système de détection de mouvement à l'aide d'Arduino et Python. La carte Arduino est équipée de trois capteurs de mouvement PIR (infrarouge passif), d'un bouton, de LEDs et d'un Buzzer. Arduino communique avec un script Python via une connexion Serial. Le script est conçu pour recevoir les données Serial envoyées par le Micro-Controlleur et les stocker sous forme d'un ficher CSV pour une analyse ultérieure des données.

## Composants
- **Carte Arduino :** Le Micro-Controlleur avec des capteurs et actionneurs attachés.
- **Capteurs de mouvement PIR (3) :** Détectent le mouvement dans leur proximité.
- **Bouton :** Activer ou désactiver l'alarme
- **LEDs (verte et rouge) 🟢🔴:** Indiquer l'état de sécurité(.
- **Buzzer 🔊:** Émet une alarme en cas de détection de mouvement.

![image](https://github.com/ZahraneRabhi/Smart-Camping/assets/88408227/693e9824-2e27-465b-bfc0-32db0c046c18)
## Installation
1. Connectez la carte Arduino à votre ordinateur à l'aide d'un câble USB.
2. Ouvrez l'IDE Arduino et coller le code C++ fourni (motion_detection_arduino.ino).
3. Ouvrez LE compilateur Python de votre choix et collez le script.
4. Modifiez le script Python (motion_detection_python.py) si nécessaire, en particulier le port série ('COM4') pour correspondre à votre configuration.
5. Exécutez le script Python.
   
## Câblage Arduino
- **pinDetecteur_1 :**  Connectez à la broche 5 sur Arduino.
- **pinDetecteur_2 :** Connectez à la broche 6 sur Arduino.
- **pinDetecteur_3 :** Connectez à la broche 7 sur Arduino.
- **bzzerPin :** Connectez à la broche 12 sur Arduino.
- **bouttonPin :** Connectez à la broche 8 sur Arduino.
- **safeLedPin :** Connectez à la broche 2 sur Arduino.
- **dangerLedPin :** Connectez à la broche 3 sur Arduino.
  
## Utilisation
1. Exécutez le script Python pour commencer la surveillance du système de détection de mouvement.
2. Le système enregistre les données des capteurs dans un fichier CSV (detection_log.csv).
3. Les LEDs indiquent l'état de sécurité (Vert : Sécurisé, Rouge : Danger).
4. La sirène retentit en cas de détection de mouvement.
5. Appuyez sur le bouton pour désactiver manuellement l'alarme.
   
## Contributeurs
**Zahrane Rabhi**
