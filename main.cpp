#include "Activity.h"
#include "DayLog.h"
#include <ncursesw/ncurses.h>  // Libreria per l'interfaccia testuale (NCurses)

int main() {
    initscr();      // Inizializza la finestra NCurses
    noecho();       // Disabilita l'echo dell'input da tastiera
    cbreak();       // Abilita la modalità "cbreak" (input immediato senza buffering)

    DayLog log;  // Crea un registro giornaliero

    // Aggiunge attività al registro
    log.addActivity(Activity("Studiare C++", "10:00", "12:00"));
    log.addActivity(Activity("Fare pausa", "12:00", "12:30"));

    // Stampa le attività a schermo
    printw("Registro delle Attività:\n");  // printw() è l'equivalente NCurses di printf()
    const auto& acts = log.getActivities();
    for (const auto& a : acts) {
        printw("- %s: %s - %s\n", a.getDescription().c_str(), a.getStartTime().c_str(), a.getEndTime().c_str());
    }

    printw("\nPremi un tasto per uscire...");
    refresh();  // Aggiorna lo schermo per mostrare i cambiamenti
    getch();    // Aspetta che l'utente prema un tasto
    endwin();   // Termina la sessione NCurses e pulisce la memoria
    return 0;
}