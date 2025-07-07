#include "DayLog.h"

// Aggiunge un'attività al registro
void DayLog::addActivity(const Activity& activity) {
    activities.push_back(activity);  // Inserisce l'attività nel vettore
}

// Restituisce tutte le attività registrate
const std::vector<Activity>& DayLog::getActivities() const {
    return activities;  // Ritorna il vettore delle attività
}
bool DayLog::hasOverlappingActivities(const Activity& newActivity) const {
    for (const auto& activity : activities) {
        if (!(newActivity.getEndTime() <= activity.getStartTime() ||
              newActivity.getStartTime() >= activity.getEndTime())) {
            return true;
              }
    }
    return false;
}
void DayLog::removeActivity(size_t index) {
    if (index < activities.size()) {
        activities.erase(activities.begin() + index);
    }
}
