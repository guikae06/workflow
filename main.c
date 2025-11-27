#include <stdio.h>
#include <unistd.h>       // voor sleep()
#include "../pigpio/pigpio.h"

int main()
{
    const unsigned int LED_PIN = 16; // GPIO16 = fysieke pin 36

    // pigpio initialiseren
    if (gpioInitialise() < 0)
    {
        printf("Fout bij initialisatie van pigpio!\n");
        return 1;
    }

    // Stel pin in als output
    gpioSetMode(LED_PIN, PI_OUTPUT);

    printf("LED knippert op GPIO %u...\n", LED_PIN);

    while (1) // oneindige loop
    {
        gpioWrite(LED_PIN, 1); // LED aan
        sleep(1);              // wacht 1 seconde

        gpioWrite(LED_PIN, 0); // LED uit
        sleep(1);              // wacht 1 seconde
    }

    gpioTerminate(); // opruimen (komt hier nooit)
    return 0;
}
