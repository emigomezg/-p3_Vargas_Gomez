# Práctica 3: USB HID

Se implementó un sistema de protocolo USB bsándonos en el ejemplo de usb_examples/dev_hid_mouse_freertos. 
En este proyecto, se modificó el archivo "mouse.c" de la siguiente manera:

- Se agregó una estructura con banderas para los distintos procesos que se ejecutan. 
Estos procesos a su vez forman parte de una máquina de estados "global" y con estas banderas nos aseguramos de que 
se ejecuten correctamente. 

- Se agregó un buffer para el teclado. 

- Se agregó un estado para cada tarea a ejecutar. Cada una de estas tareas se diferenciaban entre, si era alguna función de
mouse o teclado. 

Se agregó un archivo también llamado "mouse_and_keyboard" con las funciones a realizar. Estas funciones se implementaron también como
máquinas de estado donde cada estado representaba un pasito neceseario para la ejecución total.

Si se ejecutaban correctamente devolvían un TRUE (1) a las banderas de las que se habló en el principio.

Cabe mencionar que los comandos implementados son de Windows, se decidió así por convención, ya que en un inicio cada quién quiso empezar
a implementar el sistema en su respectivo SO y nos dimos cuenta quie por los comandos, sería más fácil basarnos en un solo SO.

En Wireshark se pudieron comprobar los distintos textos descriptores de dispostivos, comunicaciones, configuración, etc. como
se ve en la imagen anexa a este repositorio.

Fue una práctica que nos permitió entender de mejor manera el funcionamiento de USB y realmente nos hizo comprender mejor la
que hay detrás del simple hecho de conectar algún dispostivo USB en nuestras computadoras.
Tambien fue importante poner un sistema operativo en común para así evitar problemas de conflictos de compatibilidad entre ambos SOs.

+Emiliano Gómez Guerrero IE708504
+Alberto Vargas Garrido IE710231
