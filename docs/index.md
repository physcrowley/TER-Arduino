# Code à télécharger

Ce site vous permet de télécharger des exemples de code pour les projets de robotique et d'ingénierie, notamment les activités pour les cours TER3M et TER4M enseignés par M. Crowley.

Les exemples sont en format `.zip` ou `.ino` pour Arduino IDE et en format `.zip` pour PlatformIO (VSCode).

## Programme d'initiation classique : Blink

* [Clignoter pour Arduino IDE](./arduinoide/blink/blink.ino) (`.zip`)
* [Clignoter pour PlatformIO](./platformio/blink-pio.zip) (`.zip`)

## Lié aux activités sur le site de M. Crowley
Source : [https://physcrowley.github.io/Robotique](https://physcrowley.github.io/Robotique)


### Test de servomoteurs

Utilise la bibliothèque `Servo.h` pour contrôler un servomoteur. Définit des fonctions pour le mouvement dans les deux sens et pour le retour à la position neutre ou l'arrêt. Vous devrez ajuster les valeurs de la durrée des impulsions selon le servomoteur que vous utilisez.

- [Servo-test pour Arduino IDE](./arduinoide/servo-test.zip) (`.zip`)
- [Servo-test pour PlatformIO](./platformio/servo-test-pio.zip) (`.zip`)

## Software Foundations with Arduino (Shieldbot) de CS2N

Source : [Software Foundations with Arduino (Shieldbot) de CS2N](https://www.cs2n.org/u/track_progress?id=290)

### Compilation des exemples de code dans l'activité _Sensing with Arduino (Shieldbot)_ de CS2N

Affichage du dossier brut sur ce site : [./CMRA_Act3/](./CMRA_Act3/)

## Exemple de Machine à états finis

Cet exemple est pour la caméra Pixy2, des moustaches tactiles et un haut-parleur piezoélectrique, comme dans [le défi proposé dans l'activité _Camera Programming with Arduino (Shieldbot)_](https://www.cs2n.org/u/mp/badge_pages/233). Le code implémente le diagramme d'états dans ces [notes de cours de M. Crowley](https://docs.google.com/document/d/1LxZwPFYOOgUi6hL9_VkzVpgnHcKnO2U3EskbVziUh4s/view) en modularisant les instructions de trois façons différentes.

- [PixyFSM.ino](./arduinoide/PixyFSM/PixyFSM.ino) (`.ino`) - code de base, purement procédural
- [PixyFSM_functions.ino](./arduinoide/PixyFSM_functions/PixyFSM_functions.ino) (`.ino`)- code découpé en fonctions
- [PixyFSM_header pour Arduino IDE](./arduinoide/PixyFSM_header.zip) (`.zip`) - code déclarant une classe (dans un fichier `.h`) pour les constantes et les fonctions du robot
- [PixyFSM_header pour PlatformIO](./platformio/PixyFSM_header_pio.zip) (`.zip`) - même code que ci-dessus, mais pour PlatformIO
