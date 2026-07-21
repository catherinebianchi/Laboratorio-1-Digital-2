# Laboratorio-1-Digital-2
Contador de décadas y binario - Repaso GPIOs

Implementación de un contador de 4 bits en ESP32 (framework Arduino) que opera en dos modos seleccionables mediante un botón: contador de décadas y contador binario (0-15). El sistema utiliza 4 LEDs para mostrar el estado del contador en código binario/BCD, y 3 pushbuttons para incrementar, decrementar y cambiar de modo.

Funcionalidad
Modo 0: LEDs apagados (estado inicial).
Modo 1 (décadas): contador circular de 0 a 9, mostrado en binario sobre los 4 LEDs.
Modo 2 (binario): contador circular de 0 a 15, mostrado en binario sobre los 4 LEDs.
Cada cambio de modo reinicia el contador en 0.
