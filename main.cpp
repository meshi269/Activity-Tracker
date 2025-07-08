#include "Activity.h"
#include "DayLog.h"
#include <ncursesw\ncurses.h>
#include <cctype>
#include <regex>

int main() {
    // Inizializzazione NCurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

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
            case 'R': {
                const auto& actList = log.getActivities();

                if (actList.empty()) {
                    mvprintw(10, 2, "Nessuna attività da rimuovere.");
                    getch();
                    break;
                }
                char input[4];
                echo();
                mvprintw(10, 2, "Numero attività da rimuovere: ");
                getstr(input);
                noecho();
                int index = atoi(input);

                if (index > 0 && index <= static_cast<int>(actList.size())) {
                    log.removeActivity(index - 1);
                } else {
                    mvprintw(12, 2, "Indice non valido!");
                    getch();
                }
                break;
            }
            case 'E': {
                break;
            }
            default: {
                mvprintw(20, 2, "Comando non valido!");
                getch();
                break;
            }
        }
    } while (choice != 'E');

    printw("\nPremi un tasto per uscire...");
    refresh();
    getch();
    endwin();
    return 0;
}