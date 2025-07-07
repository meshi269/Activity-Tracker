#include "Activity.h"
#include "DayLog.h"
#include <ncursesw/ncurses.h>  // Libreria per l'interfaccia testuale (NCurses)
#include <cctype>

int main() {
    // Inizializzazione NCurses
    initscr();  // Inizializza la finestra NCurses (chiamare sempre per prima)
    cbreak();  // Disabilita il buffering, leggendo i caratteri uno per uno
    noecho();  // Disabilita la visualizzazione automatica dei tasti premuti

    DayLog log;
    char choice;

    // Loop principale
    do {
        // Pulisci e mostra attività
        clear();
        printw("REGISTRO ATTIVITÀ\n\n");
        int row = 2;
        for (const auto& a : log.getActivities()) {
            mvprintw(row++, 2, "- %s: %s - %s",
                    a.getDescription().c_str(),
                    a.getStartTime().c_str(),
                    a.getEndTime().c_str());
        }
        mvprintw(row+2, 2, "Comandi: (A)ggiungi, (R)imuovi, (E)sci");
        refresh();

        // Gestione input
        choice = toupper(getch());
        switch (choice) {
            case 'A': {
                char desc[100], start[6], end[6];
                echo();
                mvprintw(10, 2, "Descrizione: ");
                getstr(desc);
                mvprintw(11, 2, "Ora inizio (HH:MM): ");
                getstr(start);
                mvprintw(12, 2, "Ora fine (HH:MM): ");
                getstr(end);
                noecho();

                Activity newActivity(desc, start, end);
                if (newActivity.isTimeRangeValid() && !log.hasOverlappingActivities(newActivity)) {
                    log.addActivity(newActivity);
                } else {
                    mvprintw(14, 2, "ERRORE: Orario non valido o sovrapposto!");
                    getch();
                }
                break;
            }
            case 'R':
                // (Implementa rimozione)
                break;
            case 'E':
                break;
            default:
                mvprintw(20, 2, "Comando non valido!");
                getch();
        }
    } while (choice != 'E');

    printw("\nPremi un tasto per uscire...");
    refresh();  // Aggiorna lo schermo per mostrare i cambiamenti
    getch();    // Aspetta che l'utente prema un tasto
    endwin();   // Termina la sessione NCurses e pulisce la memoria
    return 0;
}