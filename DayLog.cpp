#include "DayLog.h"

// Aggiunge un'attività al registro
void DayLog::addActivity(const Activity& activity) {
    activities.push_back(activity);  // Inserisce l'attività nel vettore
}

// Restituisce tutte le attività registrate
const std::vector<Activity>& DayLog::getActivities() const {
    return activities;  // Ritorna il vettore delle attività
}
